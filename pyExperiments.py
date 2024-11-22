# Function to calculate the square of a number
def power(num, exp):
    return num ** exp

# Calculate factorial using recursion
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

def option_zero():
    print("-1 - exit")
    print("0 - Menu")
    print("1 - String functions")
    print("2 - Number functions")
    print("3 - Array")
    print("4 - Grouping stuff")
    print("5 - Multiplication")
    print("6 - ord and chr")
    print("7 - I/O to a file")

def option_one():
    # Reverse a string
    string = "Hello, Python!"
    reversed_string = string[::-1]
    print(f"Original: {string}")
    print(f"Reversed: {reversed_string}")

    text = "hello world"
    print(text.upper())  # Convert to uppercase: "HELLO WORLD"
    print(text.capitalize())  # Capitalize the first letter: "Hello world"
    print(text.title())  # Capitalize each word: "Hello World"

    text = "Python123"
    print(text.isalpha())  # Check if all characters are alphabetic: False
    print(text.isdigit())  # Check if all characters are digits: False
    print(text.isalnum())  # Check if all characters are alphanumeric: True

    spaces = "   "
    print(spaces.isspace())  # Check if all characters are whitespace: True

    text = "Python is awesome, isn't it?"
    print(text.find("awesome"))  # Find the starting index of "awesome": 10
    print(text.replace("awesome", "amazing"))  # Replace "awesome" with "amazing"

    text = input("Enter a short string with leading and trailing spaces: ")
    print(f">{text.strip()}<")  # Remove leading/trailing spaces: "hello world"
    print(f">{text.lstrip()}<")  # Remove leading spaces: "hello world  "
    print(f">{text.rstrip()}<")  # Remove trailing spaces: "  hello world"

    padded = text.strip().center(20, "-")  # Center text and pad with "-": "----hello world-----"
    print(padded)

    print(f"5-10: {text[5:10]}")
    print(f"10->: {text[10:]}")
    print(f"<-5: {text[:5]}")

def option_two():
    num = int(input("Enter a #: "))
    pow = int(input("Enter the Exp: "))
    print(f"{num}^{pow} is: {power(num,pow)}")

    print(f"Factorial of {num}: {factorial(num)}")

def option_three():
    text = "apple,banana,cherry"
    fruits = text.split(",")  # Split string into a list: ['apple', 'banana', 'cherry']
    print(fruits)

    joined_text = "-".join(fruits)  # Join list into a string: "apple-banana-cherry"
    print(joined_text)

def option_four():
    # Count occurrences of each character in a string
    string = input("Enter a long string with repeating characters: ")
    char_count = {}
    for char in string:
        char_count[char] = char_count.get(char, 0) + 1
    print("Character counts:", char_count)

def option_five():
    num = int(input("Enter a #: "))
    # Print the header row
    print("     ", end="")
    for col in range(num):
        print(f"{col:>3}", end=" ")
    print("\n" + "---+-" + "-" * 40)
    
    # Print the multiplication table
    for row in range(num):
        print(f"{row:>2} |", end=" ")  # Row header
        for col in range(num):
            print(f"{row * col:>3}", end=" ")  # Print the product
        print()  # Newline after each row

def option_six():
    #   convert characters back and form from characters to numbers
    for n in range(ord('a'), ord('g')):
        print(f"{n:>4} - {chr(n)}")

def option_seven():
    string = input("Enter text to save to a file ")
    # Write and read from a file
    with open("example.txt", "w") as file:
        file.write(string)

    with open("example.txt", "r") as file:
        content = file.read()
    print("File content:", content)

# Define more option functions as needed
def option_default():
    print("Invalid option. Please choose a number between 1-7 (0-menu,-1-exit).")

# Function map (like a switch case)
options = {
    0: option_zero,
    1: option_one,
    2: option_two,
    3: option_three,
    4: option_four,
    5: option_five,
    6: option_six,
    7: option_seven,
}

def main():
    while True:
        try:
            user_input = int(input("Enter an option (1 to 10): "))
            if user_input == -1:
                print("Exiting the program. Goodbye!")
                break  # Exit the loop and end the program
            # Call the corresponding function, or the default if option not found
            options.get(user_input, option_default)()
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 10.")

if __name__ == "__main__":
    main()