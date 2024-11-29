#!/bin/bash

# Function to print the progress bar
print_progress_bar() {
    local progress=$1
    local total=100
    local bar_length=50
    local filled_length=$((progress * bar_length / total))
    local empty_length=$((bar_length - filled_length))

    # Colors
    local green="\033[42m"  # Green background
    local red="\033[41m"    # Red background
    local reset="\033[0m"   # Reset color

    # Progress bar (filled part)
    local filled_bar=$(printf "%-${filled_length}s" | tr ' ' '█')

    # Progress bar (empty part)
    local empty_bar=$(printf "%-${empty_length}s" | tr ' ' ' ')

    # Print the progress bar with green for filled and red for empty
    printf "\rProgress: [${green}${filled_bar}${reset}${red}${empty_bar}${reset}] %d%%" "$progress"
}

# Simulate progress in a loop
for i in $(seq 0 100); do
    print_progress_bar "$i"
    sleep 0.05  # Simulate work being done
done

echo  # New line after the progress bar finishes