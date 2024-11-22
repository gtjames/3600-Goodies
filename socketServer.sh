# #!/bin/bash

echo "Server is listening on port 12345..."

# Trap SIGINT to gracefully exit the loop
trap "echo 'Shutting down server...'; exit" SIGINT

# Start the server with a static message
while true; do
    # For each client connection, send a static message
    echo "Hello, Client! $(date)" | nc -l 12345
done
