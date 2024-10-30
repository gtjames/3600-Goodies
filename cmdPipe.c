/* Modeling the command-line command:
        ls -al | wc using pipes */
        
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum
{
    READ,
    WRITE
};

int main()
{
    int fd[2];
    pipe(fd);

    switch (fork()) {
    case 0: /* in child */
        dup2(fd[WRITE], fileno(stdout));
        close(fd[READ]);
        close(fd[WRITE]);
        execl("/bin/ls", "ls", "-al", (char *)0);
        exit(3);
    default: /* in parent */
        dup2(fd[READ], fileno(stdin));
        close(fd[READ]);
        close(fd[WRITE]);
        execl("/usr/bin/wc", "wc", (char *)0);
        exit(4);
    }
    return 0;
}