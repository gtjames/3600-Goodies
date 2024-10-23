#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int sig, char *cmd) {
    if(fork() == 0) {
        /* child */
        printf("%d %s\n", sig, cmd);
        execlp( cmd, cmd, (char *)0 );
        printf("Not here");
        exit(1);
    } else {
        wait((int *)0);
    }
}

void myHandler(int iSig) {
    printf("\nIn myHandler for Signal: %d\n", iSig);
}

void whoHandler (int iSig) { handler(iSig, "who"); }
void lsHandler  (int iSig) { handler(iSig, "ls"); }
void cmdHandler (int iSig) {
    char    input[100];
    printf("Your command %d>  ", iSig);
    fflush(stdin);
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = 0;
    handler(iSig, input);
}

int main() {
    void (*pfRet0)(int) = signal(SIGHUP,  myHandler);   //  1
    void (*pfRet1)(int) = signal(SIGINT,  myHandler);   //  2
    void (*pfRet2)(int) = signal(SIGALRM, whoHandler);  //  14
    void (*pfRet3)(int) = signal(SIGTRAP, lsHandler);   //  5
    void (*pfRet4)(int) = signal(SIGABRT, cmdHandler);  //  6

    int i = 0;
    printf("Entering an infinite loop\n"); 
    while (1) {
        printf(".");
        i++;
        sleep(1);
        if(i%50 == 0) printf("\n%d ", i);
    }
    return 0;
}
