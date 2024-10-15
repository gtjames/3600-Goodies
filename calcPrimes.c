#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// #define MAX_BASE    10000
// #define blockSize        1000
#define MAX_PRIMES  5000   // Set a maximum size for the prime array
// #define NUM_THREADS 8       // Number of threads to run

int prime_array[MAX_PRIMES]; // Global array to hold prime numbers
int prime_count = 0;         // Counter for primes in the array
int current_base = 2;        // Start base for prime calculations
int numThreads, maxBase, blockSize;

pthread_mutex_t mutex;       // Mutex to protect shared resources

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
        pthread_mutex_lock(&mutex);         //  accessing current_base
        if (current_base > maxBase) {      //  Check if we are done
            printf("last base %d for thread %d\n", base, thread_id);
            pthread_mutex_unlock(&mutex);   //  Unlock the mutex and exit
            break;                          //  all primes are exhausted
        }
                                            //  zone is still locked
        base = current_base;                //  Get the current base
        current_base += blockSize;               //  Update the base for the next thread
        pthread_mutex_unlock(&mutex);       //  Unlock the mutex after modifying current_base
        printf("Getting next tranche %d for thread %d\n", base, thread_id);

        // Calculate primes between base and base + blockSize
        for (int num = base; num < base + blockSize; num++) {
            if (is_prime(num)) {
                pthread_mutex_lock(&mutex);             //  need access to prime count and prime array
                if (prime_count < MAX_PRIMES) {         //  do we have room for another prime
                    prime_array[prime_count++] = num;   //  Add prime to the array
                }
                pthread_mutex_unlock(&mutex);           //  prime save continue
            }
        }
    }
    printf("Thread %d finished.\n", thread_id);

    return NULL;
}

void sortArray(int *arr, int n) {
    for (int k = 0; k < n; k++) printf ("%d ", arr[k]);
    printf("\n");

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
        for (int k = 0; k < n; k++) printf ("%d ", arr[k]);
        printf("\n");
    }
}

void     getParams(int argc, char *argv[]) {
    char    input[20];

    if(argc < 4){
        printf("# of Threads : ");
        fgets(input, sizeof(input), stdin);
        numThreads = atoi(input);

        printf("Max # : ");
        fgets(input, sizeof(input), stdin);
        maxBase = atoi(input);

        printf("Block Size : ");
        fgets(input, sizeof(input), stdin);
        blockSize = atoi(input);
    } else {
        numThreads  = atoi(argv[1]);
        maxBase     = atoi(argv[2]);
        blockSize   = atoi(argv[3]);
    }
    printf("Process Params:\n\tThreads:\t%d\n\tLast Prime:\t%d\n\tRequest Size:\t%d\n", numThreads, maxBase, blockSize);
}

int main(int argc, char *argv[]) {

    getParams(argc, argv);

    pthread_t threads[numThreads];      //  save Thread IDs
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

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
    pthread_mutex_destroy(&mutex);

    sortArray(prime_array, prime_count);
    // Print the collected primes
    printf("Primes found: %d\n%4d  ", prime_count, 0);
    for (int i = 0; i < prime_count; i++) {
        printf("%4d ", prime_array[i]);
        if ((i + 1) % 15 == 0) printf("\n%4d - ", i+1);
    }
    printf("\n");

    return 0;
}