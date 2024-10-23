/* The program demonstrates implementing redirection.
    To run: ./a.out <output filename> <command>
*/
#include <stdio.h> 
#include <sys/file.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    int fd;
    /* Open file for redirection */
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
    dup2(fd, 1);    /* Duplicate descriptor to standard output */
    close(fd);      /* Close original descriptor to save descriptor space */
    execvp(argv[2], &argv[2]); /* Invoke program; will inherit stdout */ perror("main"); /* Should never execute */
}
