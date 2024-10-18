#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main() {
    char *cmd[] = {"who", "ls", "date"};        //  add anything you like
    char            input[30];
    int i;
    while( 1 ) {
        printf("0=who 1=ls 2=date : ");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        i = atoi(input);
        if(fork() == 0) {
            /* child */
            execlp( cmd[i], cmd[i], (char *)0 ); 
            printf("execlp failed: %s\n", cmd[i]);      //  we only get here on a failure
            exit(1);
        }
        else {
            /* parent */ 
            wait( (int *)0 );       //  wait for any child of mine to complete
            printf("child finished\n");
        }
    } /* while */
} /* main */
