echo hello
# Iterate through the list of user IDs
users=(a, t, d, w, 3, 3, f, n)
for user in "${users[@]}"; do
    # Count the number of processes for the user
    echo "User: $user"
done
