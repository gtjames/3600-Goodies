#include <stdio.h> 
#include <sys/file.h> 
#include <unistd.h> 
int main(int argc, char **argv)
{
   char *cmd[4]; 
   cmd[0] = (argc == 2) ? argv[1] : "ls"; 
   cmd[1] = NULL;
   int fd = open("ls.out", O_CREAT | O_TRUNC | O_WRONLY, 0600);
   dup2(fd, 1);
   execvp(cmd[0], cmd);
}
