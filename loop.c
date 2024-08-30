#include <stdio.h>
#include <stdlib.h>

unsigned int getNumber(char *prompt, unsigned int max);

int main(int argc, char *argv[]) {
    int first;
    int second;
    if (argc == 3) {				//	user has two input params on the command line
        first  = atoi(argv[1]);			//	convert first to int
        second = atoi(argv[2]);			//	convert second to int
    }
    else if (argc == 2) {			//	user has only asingle command line param
        first  = atoi(argv[1]);			//	convert first to int
        second = getNumber("Enter 2nd #: ", 100);	//	ask user for the second number
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
    unsigned int    num;
    char            input[30];

    while (1) {
        printf("%s", prompt);               //  Ask user to enter a number
        // fgets(input, sizeof(input), stdin);
	    scanf("%s", input);                 //  get the text
        num = atoi(input);                  //  convert to int
        if (num >= 0 && num <= max) {       //  
            return num;
        }
    }
}

