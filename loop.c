#include <stdio.h>
#include <stdlib.h>

unsigned int getNumber(char *prompt, unsigned int max);

int main(int argc, char *argv[]) {
    int first;
    int second;
    if (argc == 3) {
        first  = atoi(argv[1]);
        second = atoi(argv[2]);
    }
    else if (argc == 2) {
        first  = atoi(argv[1]);
        second = getNumber("Enter 2nd #: ", 100);
    }
    else if (argc == 1) {
        first  = getNumber("Enter 1st #: ", 100);
        second = getNumber("Enter 2nd #: ", 100);
    }

    for (int i = first; i < second; i++) {
        printf ("still looping i = %d\n", i);
    }
}

unsigned int getNumber(char *prompt, unsigned int max) {
    unsigned int    num;`   
    char            input[30];

    while (1) {
        printf("%s", prompt);
       fgets(input, sizeof(input), stdin);
	    // scanf("%d", &num);
        num = atoi(input);
        if (num >= 0 && num <= max) {
            return num;
        }
    }
}

