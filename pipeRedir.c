/* Equivalent to "sort < file2 | uniq */ 

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) {
    int fd[2];
    FILE *fp = fopen(argv[1], "r");     //  no error checking
    dup2(fileno(fp), fileno(stdin)); 
    fclose(fp);
    pipe(fd);
    if (fork() == 0) {
        dup2(fd[1], fileno(stdout)); 
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/sort", "sort", (char*) 0); 
        exit(2);
    } else {
        dup2(fd[0], fileno(stdin)); 
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/uniq", "uniq", (char*)0); 
        exit(3);
    }
    return 0;
}
