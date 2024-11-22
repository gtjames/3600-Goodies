#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void execute_command(char *command, char *response) {
    FILE *fp;
    fp = popen(command, "r");
    if (fp == NULL) {
        strcpy(response, "Failed to execute command.\n");
        return;
    }

    char temp[BUFFER_SIZE];
    while (fgets(temp, sizeof(temp), fp) != NULL) {
        strcat(response, temp);
    }
    if(strlen(response) == 0)
        strcpy(response, "no data");
    printf("waiting 2\n");
    pclose(fp);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE * 4] = {0}; // Larger response buffer for command output

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        memset(response, 0, sizeof(response));

        int read_size = read(client_socket, buffer, BUFFER_SIZE);
        if (read_size <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received command: %s\n", buffer);
        
        // Execute the command
        execute_command(buffer, response);
        
        // Send the response back to the client
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    exit(0); // Exit the child process when done with client
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connected to client.\n");

        // Fork a process to handle the client
        pid_t pid = fork();
        if (pid == 0) {
            // In child process
            close(server_fd); // Close the listening socket in the child process
            handle_client(client_socket);
        } else {
            // In parent process
            close(client_socket); // Close client socket in parent, as child is handling it
        }

        // Clean up any terminated child processes
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }

    close(server_fd);
    return 0;
}
