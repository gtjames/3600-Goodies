#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char data[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set socket options
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Bind the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
 
    // Start listening for connections
    listen(server_fd, 5);

    printf("Server is listening on port %d...\n", PORT);

    // Accept a connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    printf("Connection established with client\n");

    // Send a message to the client
    const char *message = "Hello, Client!";
    send(new_socket, message, strlen(message), 0);

    // Receive a message from the client
    int valread = read(new_socket, data, BUFFER_SIZE);
    printf("Received from client: %s\n", data);

    // Close the sockets
    close(new_socket);
    close(server_fd);
}