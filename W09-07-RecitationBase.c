#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 120

// Global variables
char sentence[MAX_LEN];

//  define the mutex lock

int     nextLetter = 0;

int getNextIndex() {
    int index = nextLetter;
    sleep(0);
    nextLetter = nextLetter + 1;
    return index;
}

void* capitalize(void* arg) {
    int index;

    // Lock the mutex before accessing/modifying the shared data

    index = getNextIndex();
    // Unlock the mutex after modifying the shared data


    if (index % 2 == 1) {           //  mod 2 == 1 this is an odd character
        sentence[index] = '_';  //   toupper(sentence[index]);
    } 
    printf("The new sentence is [%2d]: %c\n", index, sentence[index]);

    return NULL;
}

int main() {
    pthread_t threads[MAX_LEN];
    int indices[MAX_LEN];    
    
    // Read input sentence
    printf("Enter a sentence (max %d characters): ", MAX_LEN);
    fgets(sentence, MAX_LEN, stdin);

    int len = strlen(sentence);

    // Create a thread for each character
    for (int i = 0; i < len; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, capitalize, 0);   // (void*)&indices[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < len; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the modified sentence
    printf("%s\n", sentence);

    return 0;
}
