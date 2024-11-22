import socket

# Create a server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))  # Bind to an address and port
server_socket.listen(5)  # Start listening for connections

print(f"Server is listening on port 12345...")

# Accept a connection
client_socket, client_address = server_socket.accept()
print(f"Connection established with {client_address}")

# Send and receive data using client_socket
client_socket.send(b"Hello, Client!")
data = client_socket.recv(1024)
print(f"Received from client: {data}");

# Close the sockets
client_socket.close()
server_socket.close()