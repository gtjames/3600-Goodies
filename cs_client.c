#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT            8080
#define BUFFER_SIZE     1024
#define HISTORY_LIMIT   20

int main() {
    char *history[HISTORY_LIMIT] = {NULL}; // Array of pointers to hold history
    int sock = 0, h = 0;
    struct sockaddr_in serv_addr;
    char command[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE * 4] = {0}; // Larger buffer to receive command output

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    while (1) {
        printf("Enter remote command -> ");
        fgets(command, BUFFER_SIZE, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0 || strcmp(command, "q") == 0  || strcmp(command, "x") == 0 ) {
            break;
        } else if (strlen(command) == 0) {
            printf("'x' | 'q' | 'exit' to quit: ");
            continue;
        } else if (strcmp(command, "h") == 0 ) {
            for (int i = 0; i < h && i < HISTORY_LIMIT; i++  ) {
                printf("%3d: %s\n", i, history[i]);
            }
            continue;
        } else if (command[0] == '!' ) {
            int cmd = atoi(&command[1]);
            strcpy(command, history[cmd]);
        }
        // Send the command to the server
         // Allocate space for input and copy it to history
        history[h] = malloc(strlen(command) + 1);  // Allocate exact space
        strcpy(history[h], command);
        h++;
        h = h%HISTORY_LIMIT;
        send(sock, command, strlen(command), 0);

        // Receive the response from the server
        memset(response, 0, sizeof(response));
        int read_size = read(sock, response, sizeof(response) - 1);

        if (read_size > 0) {
            printf("Server response:\n%s\n", response);
        }
    }

    close(sock);
    return 0;
}