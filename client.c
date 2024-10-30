#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char command[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE * 4] = {0}; // Larger buffer to receive command output

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address.\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    while (1) {
        printf("Enter a command to execute on server (or 'exit' to quit): ");
        fgets(command, BUFFER_SIZE, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strlen(command) == 0) {
            continue;
        }

        // Send the command to the server
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