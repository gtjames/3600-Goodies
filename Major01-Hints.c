#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include "Major-01.h"

//   gcc Major01-Hints.c -o Major01 -g -lm
//        gtj Dec 2 2024
int main() {
    unsigned int choice, num;
    //  show the menu to get started
    menu();
    
    while (1) {        
        // Reading user's choice
        choice = getNumber("\nEnter your choice: ", 10);
        if (choice != 10 && choice != 0)
            num    = getNumber("Enter a number: ", 2000000000);

        // Handling user's choice
        switch (choice) {
            case 0:     menu();                 break;
            case 1:     printf ("createPalindrome\n");      createPalindrome(num);  break;
            case 2:     printf ("power\n");                 power(num);             break;
            case 3:     printf ("reverse\n");               reverse(num);           break;
            case 4:     printf ("replace\n");               replace(num);           break;
            case 5:     printf ("palindrome\n");            palindrome(num);        break;
            case 10:    return 0;
            default:    printf ("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void menu () {
    // Displaying the menu
    printf("\nMenu:\n");
    printf("1.  Create a Palindrome\n");
    printf("2.  Power\n");
    printf("3.  Reverse\n");
    printf("4.  Replace\n");
    printf("5.  Palindrome\n");
    printf("10. Exit\n");
}

unsigned int getNumber(char *prompt, unsigned int max) {
    unsigned int    num;
    char            input[30];

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        num = atoi(input);
        if (num <= max) {
            return num;
        }
    }
}

void createPalindrome(unsigned int num) {
    unsigned int    pal = reverse(num) | num;
    printf ("Here is your brand new Palindrome: %u", pal);
}

void power(unsigned int num) {

}

unsigned int reverse(unsigned int num) {

}

void replace(unsigned int num) {
}

void palindrome(unsigned int num) {

}
