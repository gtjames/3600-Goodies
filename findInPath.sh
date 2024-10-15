#!/bin/bash

# which -a python3 | xargs -I {} ls -l {}

# Find all occurrences of python3 in the system's PATH
for python_path in $(which -a python3); do
    # Display the path and run ls -l on it
    #   echo "Path: $python_path"
    ls -l "$python_path"
done
which -a python3 | xargs -I {} ls -l {}
