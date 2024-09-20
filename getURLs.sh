URL=$1
# Fetch the webpage content using curl
webpage_content=$(curl -s "$URL")

# Use grep with a regular expression to extract URLs
# This regex is a basic example and may not cover all possible URL formats
urls=$(echo "$webpage_content" | grep -o 'http[s]*://[^"]*')

# Print out the extracted URLs
echo "URLs found in $URL:"
echo "$urls"

