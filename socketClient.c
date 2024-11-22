#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to the server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to serverat 12345\n");

    // Receive a message from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Message from server: %s\n", buffer);

    // Send a message to the server
    const char *message = "Hello, Server!";
    send(sock, message, strlen(message), 0);

    // Close the socket
    close(sock);

    return 0;
}