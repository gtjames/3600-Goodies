import socket

# Create a client socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_address = ('localhost', 12345)
client_socket.connect(server_address)
print(f"Connected to server at {server_address}")

# Receive a message from the server
message = client_socket.recv(1024)
print(f"Message from server: {message.decode()}")

# Send a response to the server
client_socket.send(b"Hello, Server!")

# Close the client socket
client_socket.close()