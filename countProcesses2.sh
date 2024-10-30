#!/bin/bash

# Function to count processes per user
count_processes() {
    # Get the list of user IDs to monitor
    local user_ids=("$@")  # Use "$@" to capture all arguments as an array
    echo "Number of unique users: ${#user_ids[@]}"

    local users=("$@")  # Array of users passed as arguments
    user_list=$(IFS=,; echo "${users[*]}")  # Convert array to comma-separated list
    echo "Listing processes for users: $user_list"
    
    # Use ps to list processes for the given users
    ps -u "$user_list" -o user | sort | uniq -c
}
# Main script execution
if [ $# -eq 0 ]; then
    # Get unique user IDs from processes
    user_ids=($(ps -eo user= | grep -Ev "_" | sort -u))  # Capture output as an array
    count_processes "${user_ids[@]}"  # Pass the array to the function
else
    # If users are provided as command-line arguments
    count_processes "$@"
fi

