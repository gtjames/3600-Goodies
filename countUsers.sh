#!/bin/bash

# Function to process user IDs
process_user_ids() {
    local user_ids=("$@")
  echo $user_ids
while true; do
  # Loop through each user ID
  for user in $user_ids; do
    # Count processes for all users
    ps -u $user -o user= | grep $user | sort | uniq -c | while read -r count user; do
        printf "%-20s %d\n" "$user" "$count"
    done
  done
  sleep 5
  done
}

if [ $# -eq 0 ]; then
  # Get list of unique usernames from active processes, excluding system users like sys
  user_ids=$(ps -eo user= | grep -Ev "_|sys" | sort -u)

  # Call the function and pass the user IDs
  #   add an additional comment
  process_user_ids "$user_ids"
else
    process_user_ids "$*"
fi
