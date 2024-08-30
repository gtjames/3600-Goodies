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
    else if (argc == 1) {                           //  user entered no parmas
        first  = getNumber("Enter 1st #: ", 100);   //  ask user for param 1
        second = getNumber("Enter 2nd #: ", 100);   //  ask user for param 2
    }

    for (int i = first; i < second; i++) {
        printf ("still looping i = %d\n", i);
    }
}

unsigned int getNumber(char *prompt, unsigned int max) {
    unsigned int    num;
    char            input[30];

    while (1) {
        printf("%s", prompt);               //  Ask user to enter a number
        fgets(input, sizeof(input), stdin);
	    // scanf("%s", input);                 //  get the text
        num = atoi(input);                  //  convert to int
        if (num >= 0 && num <= max) {       //  
            return num;
        }
    }
}

