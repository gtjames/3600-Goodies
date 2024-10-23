#include <stdio.h> 
#include <string.h> 
#include <unistd.h>

#define READ 0	/* The index of the read end of the pipe */ 
#define WRITE 1 /* The index of the write end of the pipe */

char* phrase = "This goes in the pipe"; 

int main () {
    int fd[2], bytesRead;
    char message[100]; /* Parent process' message buffer */

    pipe(fd); /* Create unnamed pipe */ 
    if (fork() == 0) /* Child, writer */ 
    {
        close(fd[READ]); /* Close unused end */
        write(fd[WRITE], phrase, strlen(phrase) + 1); /* Include NULL */ 
        close(fd[WRITE]); /* Close used end */
    }
    else /* Parent, reader */
    {
        close(fd[WRITE]); /* Close unused end */ 
        bytesRead = read(fd[READ], message, 100);
        printf("Parent just read %i bytes: %s\n", bytesRead, message); 
        close(fd[READ]); /* Close used end */
    }
}
