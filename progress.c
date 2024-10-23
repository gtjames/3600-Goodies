#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define red     "\e[1;31m"   
#define green   "\e[1;32m"   
#define blue    "\e[1;34m"   
#define cyan    "\e[0;36m"   
#define reset   "\e[0m"

char    *color = red, *colors[] = {red, green, blue, cyan};
int     size = 100;
int     delay = 50000;

void handlerr (int iSig) { color = colors[0]; }
void handlerg (int iSig) { color = colors[1]; }
void handlerb (int iSig) { color = colors[2]; }
void handlerc (int iSig) { color = colors[3]; }

void repeat(char *str, char c, int repeat) {
    for (int i = 0; i < repeat; i++) {
        str[i] = c;
    }
    str[repeat] = '\0'; // Null-terminate the string
}
void printProgressBar(int progress, int total) {
    int barWidth = 50;  // Width of the progress bar
    float percentage = (float)progress / total;
    char bar[200];
    
    int pos = barWidth * percentage;
    repeat( bar,      '=', pos);
    repeat(&bar[pos], ' ', barWidth-pos);
    printf("[ %s%s%s ] %d%%  \r", color, bar, reset, (int)(percentage * size));

    // empty the pipe
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    if (argc >= 2)  size  = atoi(argv[1]);
    if (argc >= 3)  delay = atoi(argv[2]) * 1000;
    if (argc >= 4)  color = colors[atoi(argv[3])];

    int total = size;  // Total progress steps
    
    void (*pfRet0)(int) = signal(SIGHUP,  handlerc);   //  1
    void (*pfRet1)(int) = signal(SIGINT,  handlerr);   //  2 ^C
    void (*pfRet2)(int) = signal(SIGQUIT, handlerg);   //  3 ^back slash
    void (*pfRet3)(int) = signal(SIGTSTP, handlerb);   //  20 ^Z

    for (int i = 0; i <= total; ++i) {
        printProgressBar(i, total);
        usleep(delay);  // Sleep for 50 milliseconds
    }
    
    printf("\n");
    return 0;
}