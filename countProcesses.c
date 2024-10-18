
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main()
{
    pid_t p = fork();
    if (p > 0) {
        printf("Hello2 %d %d\n", getpid(), p);
        p = fork();
        printf("Hello3 %d %d\n", getpid(), p);
    }
    printf("Hello %d %d\n", getpid(), p);
    return 0;
}