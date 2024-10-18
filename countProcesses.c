
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main()
{
    printf("Hello1 %d\n", getpid());
    pid_t p = fork();
    if (p > 0) {
        printf("Hello2 %d %d\n", getpid(), p);
        p = fork();
        printf("Hello3 %d %d\n", getpid(), p);
    }
    printf("Exiting %d %d\n", getpid(), p);
    return 0;
}