#include <stdio.h>
#include <stdlib.h>

//      given a reference to an int array 
//      and the number elements in the array
//      do a bubble rock sort
void sortArray(int *arr, int n) {
    // for (int k = 0; k < n; k++) printf ("%d ", arr[k]);
    // printf("\n");

    for (int i = 0; i < n - 1; i++) {
       for (int j = i + 1; j < n - i - 1; j++) {
            if (arr[j] < arr[i]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            } else if (arr[j] > arr[n - i - 1]) {
                // Swap arr[j] and arr[n - i - 1]
                int temp = arr[j];
                arr[j] = arr[n - i - 1];
                arr[n - i - 1] = temp;
            }
        }
        // for (int k = 0; k < n; k++) printf ("%d ", arr[k]);
        // printf("\n");
    }
}

//      given a reference to an int array 
//      and the number elements in the array
//      print all elements in the array
//      with 15 numbers per line
//      only show the first 3 and last 3
void printResults(int array[], int primeCount) {
    int maxRows = primeCount/15;
    // Print the collected primes
    printf("\nPrimes found: %d\n---------------------", primeCount);
    for (int i = 0, row = 0; i < primeCount; i++) {
        row = i / 15;
        if(row >= 3 && row < maxRows - 2)
          continue;
        if (i % 15 == 0) {
            printf("\n%4d - ", i+1);
        }
        printf("%4d ", array[i]);
    }
    printf("\n");
}

//  convert command line params to numbers
//  if the command line has not numbers as the user
int *getParams(int argc, char *argv[]) {
    char    input[20];
    static  int vars[4];

    if(argc < 5){
        printf("# of Threads : ");
        fgets(input, sizeof(input), stdin);
        vars[0] = atoi(input);      //      numThreads

        printf("Max # : ");
        fgets(input, sizeof(input), stdin);
        vars[1] = atoi(input);      //      maxBase

        printf("Block Size : ");
        fgets(input, sizeof(input), stdin);
        vars[2] = atoi(input);      //      blockSize

        printf("Shared Mutex : ");
        fgets(input, sizeof(input), stdin);
        vars[3] = input[0] == 'T';      //      blockSize
    } else {
        vars[0] = atoi(argv[1]);    //      numThreads
        vars[1] = atoi(argv[2]);    //      maxBase
        vars[2] = atoi(argv[3]);    //      blockSize  
        vars[3] =      argv[4][0] == 'T';  //      sharedMutex
    }
    printf("Process Params:\n\tThreads:\t%d\n\tLast Prime:\t%d\n\tRequest Size:\t%d\n", vars[0], vars[1], vars[2]);
    return vars;
}
