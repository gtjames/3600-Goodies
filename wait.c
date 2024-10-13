#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main() {
    char *cmd[] = {"who", "ls", "date"}; 
    char            input[30];
    int i;
    while( 1 ) {
        printf("0=who 1=ls 2=date : ");
        fgets(input, sizeof(input), stdin);
        i = atoi(input);
        if(fork() == 0) {
            /* child */
            execlp( cmd[i], cmd[i], (char *)0 ); 
            printf("execlp failed\n");      //  we only get here on a failure
            exit(1);
        }
        else {
            /* parent */ 
            wait( (int *)0 );
            printf("child finished\n");
        }
    } /* while */
} /* main */
