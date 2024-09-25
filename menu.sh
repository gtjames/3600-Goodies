echo "Select a file to view:"

select file in *  # Lists all files in the current directory
do
    if [ -n "$file" ]; then
        echo "Displaying contents of $file:"
        cat "$file"
    else
        echo "Invalid selection"
    fi
done
