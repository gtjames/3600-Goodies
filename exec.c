#include <stdio.h> 
#include <unistd.h>

int main()
{
    char *cmd[] = {"who", "ls", "date", "../3600/02-Minor.sh"}; 
    int i;
    printf("0=who 1=ls 2=date 3=Minor02 : "); 
    scanf("%d", &i);
    execlp(cmd[i], cmd[i], (char *)0 );
    printf("execlp failed\n"); 
    return 0;
}