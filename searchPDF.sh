#!/bin/bash

# Directory to search and the string to look for
directory_to_search="/Users/garyjames/Documents/UNT/3600 Systems Programming"  # Replace with your directory
search_string="SIGINT"

# Find all .pptx files and loop through them
find "$directory_to_search" -name "*.pptx" | while read -r pptx_file; do
  # Create a temporary directory for each file
  temp_dir=$(mktemp -d)
  
  # Unzip the pptx file into the temporary directory
  unzip -q "$pptx_file" -d "$temp_dir"
  
  # Search for the string in the unzipped XML files
  if grep -q "$search_string" "$temp_dir"/*/*.xml; then
    echo "Found '$search_string' in: $pptx_file"
  fi
  
  # Clean up the temporary directory
  rm -rf "$temp_dir"
done