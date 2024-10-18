/* This program will demonstrate what happens if a read takes place with a pipe whose write end is closed, and vice versa */
#include <stdio.h>
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h>

#define READ 0 /* The index of the read end of the pipe */
#define WRITE 1 /* The index of the write end of the pipe */ 

char* phrase = "Another pipe example end closed";

void signal_catcher(int);

int main() {
    int fd[2], bytesWritten = 0, bytesRead;
    char message[100]; /* Parent process' message buffer */ 

    signal(SIGPIPE, signal_catcher);
    pipe(fd); /* Create pipe */
    close(fd[WRITE]); /* Close used end */ 
    
    printf("About to read from pipe\n"); 
    bytesRead = read(fd[READ], message, 100);
    printf("%i bytes were read with write closed\n", bytesRead);
    close(fd[READ]); /* Close used end */ 
    
    pipe(fd); /* Recreate unnamed pipe */ 
    close(fd[READ]); /* Close unused end */ 
    printf("About to write to pipe\n");
    bytesWritten = write(fd[WRITE], phrase, strlen(phrase) + 1);
    printf("%i bytes were written with read end closed\n", bytesWritten); 
    close(fd[WRITE]);
}

void signal_catcher(int theSig) {
    printf("A SIGPIPE (%i) has been caught\n", theSig);
}
