#!/bin/bash

# Function to process user IDs
process_user_ids() {
  local user_ids="$1"
    echo "$user_ids[0]"
  # Loop through each user ID
  for user in $user_ids; do
    echo "Active Username: $user"
  done
}

# Get list of unique usernames from active processes, excluding system users like sys
user_ids=$(ps -eo user= | grep -Ev "_|sys" | sort -u)

# Call the function and pass the user IDs
process_user_ids "$user_ids"