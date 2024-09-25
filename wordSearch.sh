#!/bin/bash

# Directory to search
SEARCH_DIR="$1"

# Token to search for
TOKEN="$2"

# Loop through all files in the directory
for FILE in "$SEARCH_DIR"/*; do
  if [ -f "$FILE" ]; then
    # Use grep to search for the token in the file
    if grep -q "$TOKEN" "$FILE"; then
      echo "Token found in: $FILE"
    fi
  fi
done

