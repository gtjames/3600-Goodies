#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

/**
 *      If you use this code will will need to compile from the
 *          command line using this command
 *              gcc calcPrimes.c utils.c -o calcPrimes
 */

void sortArray      (int *arr, int n);
void printResults   (int array[], int primeCount);
int *getParams      (int argc, char *argv[]);

#define MAX_PRIMES  80000   // Set a maximum size for the prime array

int prime_array[MAX_PRIMES]; // Global array to hold prime numbers
int prime_count = 0;         // Counter for primes in the array
int current_base = 0;        // Start base for prime calculations
int numThreads, maxBase, blockSize, sharedMutex;

pthread_mutex_t mutex[2];       // Mutex to protect shared resources

// Function to check if a number is prime
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function that calculates primes between base and base + blockSize
void* calc_primes(void* arg) {
    int thread_id = *(int*)arg;  // Access thread-specific argument
    free(arg);                   // Free dynamically allocated memory

    printf("Thread %d started.\n", thread_id);
    
    while (1) {
        int base;
        
        // Lock mutex to get the current base
        pthread_mutex_lock(&mutex[0]);         //  accessing current_base
        if (current_base > maxBase) {      //  Check if we are done
            printf("last base %d for thread %d\n", base, thread_id);
            pthread_mutex_unlock(&mutex[0]);   //  Unlock the mutex and exit
            break;                          //  all primes are exhausted
        }
                                            //  zone is still locked
        base = current_base;                //  Get the current base
        current_base += blockSize;               //  Update the base for the next thread
        pthread_mutex_unlock(&mutex[0]);       //  Unlock the mutex after modifying current_base
        printf("Thread %d: Next bucket starting at %d\n", thread_id, base);

        // Calculate primes between base and base + blockSize
        for (int num = base; num < base + blockSize; num++) {
            if (is_prime(num)) {
                pthread_mutex_lock(&mutex[sharedMutex?0:1]);             //  need access to prime count and prime array
                if (prime_count < MAX_PRIMES) {         //  do we have room for another prime
                    prime_array[prime_count++] = num;   //  Add prime to the array
                }
                pthread_mutex_unlock(&mutex[sharedMutex?0:1]);           //  prime save continue
            }
        }
    }
    printf("Thread %d finished.\n", thread_id);

    return NULL;
}

int main(int argc, char *argv[]) {
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    //  returns an array of params
    int *vars = getParams(argc, argv);
    numThreads  = vars[0];
    maxBase     = vars[1];
    blockSize   = vars[2];

    pthread_t threads[numThreads];      //  save Thread IDs
    
    // Initialize the mutex
    pthread_mutex_init(&mutex[0], NULL);
    pthread_mutex_init(&mutex[1], NULL);

    // Create threads to calculate primes
    for (int i = 0; i < numThreads; i++) {
        int *arg = malloc(sizeof(*arg)); // Allocate memory for each thread's argument
        *arg = i;                        // Set the thread id
        pthread_create(&threads[i], NULL, calc_primes, arg);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex[0]);
    pthread_mutex_destroy(&mutex[1]);

    sortArray(prime_array, prime_count);
    printResults(prime_array, prime_count);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time: %f\n", cpu_time_used);

    return 0;
}