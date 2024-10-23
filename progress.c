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

char    *color = red, *colors[] = {red, green, blue, cyan};
int     size = 100;
int     delay = 50000;

void handlerr (int iSig) { color = colors[0]; }
void handlerg (int iSig) { color = colors[1]; }
void handlerb (int iSig) { color = colors[2]; }
void handlerc (int iSig) { color = colors[3]; }

void printProgressBar(int progress, int total) {
    int barWidth = 50;  // Width of the progress bar
    float percentage = (float)progress / total;
    
    printf("[");
    
    int pos = barWidth * percentage;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) {
            // Green color for completed progress
            printf("%s=", color);
        } else {
            // Red color for remaining progress
            printf(" ");
        }
    }
    
    // Reset color and print percentage
    printf("\e[0m] %d%%  \r", (int)(percentage * size));
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