# Function to count processes per user
count_processes() {
    # Get the list of user IDs to monitor
    local user_ids=("$@")  # Use "$@" to capture all arguments as an array

    echo ${user_ids[@]}
    echo "Number of unique users: ${#user_ids[@]}"
}

# just a comment
# Main script execution
if [ $# -eq 0 ]; then
    user_ids=($(ps -eo user= | grep -Ev "_" | sort -u))
    count_processes "${user_ids[@]}"
fi
