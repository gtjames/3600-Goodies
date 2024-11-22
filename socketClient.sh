#!/bin/bash

# Connect to the server on localhost and port 12345
echo "Connecting to server on localhost:12345..."
response=$(echo "Hello, Server! $(date)" | nc localhost 12345)

# Print the server's response
echo "$response"