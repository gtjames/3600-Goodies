#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main() {
    int i = 100;
    pid_t pid = fork();
    if ( pid == 0 ) {
        /* child */
        for ( ; i > 0; i--)
            printf("child %d\n", i);
        printf("child      done pid - %d\n", getpid());
        printf("         parent pid - %d\n", getppid());
        exit(1);
    }
    else {
        /* parent */ 
        for ( ; i < 200; i++)
            printf("    parent %d\n", i);
        wait( (int *)0 );
        // waitpid(pid, (int *) 0, 0);
        printf("    parent done pid - %d\n", getpid());
        printf("    child       pid - %d\n", pid);
    }
} /* main */
