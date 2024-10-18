#include <stdio.h>
#include <assert.h>
#include <signal.h>

void myHandler(int iSig) {
    printf("\nIn myHandler with argument %d\n", iSig);
}

void myAlarmHandler(int iSig) {
    char            input[30];

    printf("\nIn myHandler with argument %d\n", iSig);
    printf("What's the problem? > ");
    fgets(input, sizeof(input), stdin);
}

int main() {
    void (*pfRet)(int) = signal(SIGINT, myHandler); 
    void (*pfRet2)(int) = signal(SIGALRM, myAlarmHandler); 
    assert(pfRet != SIG_ERR);

    int i = 0;
    printf("Entering an infinite loop\n"); 
    while (1) {
        printf(".");
        i++;
        if(i%100 == 0) printf("\n%d ", i);
    }
    return 0;
}
