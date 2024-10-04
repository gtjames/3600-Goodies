read a b c
1 22 333 4444 55555

find . -name "*.c" -exec ls -l {} \;

  dirs=("/etc" "/var" "/opt" "/tmp")
  echo $dirs
  echo ${dirs[0]}
  echo ${dirs[1]}
  echo ${dirs[2]}
  echo ${dirs[-1]}
  echo ${#dirs[@]}
  len=${#dirs[@]}
  echo $len

for dir in ${dirs[@]}; do
    echo "Dir name: $dir"
done

dirs=("/etc" "/var" "/opt" "/tmp")
dirs+=("/bin")
echo ${dirs[@]}

1.  PATH        Directories searched for executable programs.
2.  HOME        Current user's home directory.
3.  USER        Name of the current user.
4.  SHELL       Path to the current shell.
5.  PWD         Current working directory.
6.  OLDPWD      Previous working directory.
7.  IFS         Internal Field Separator, default is space, tab, and newline.
8.  PS1         Primary command prompt string.
9.  PS2         Secondary prompt string (used for multi-line commands).
10. UID         User ID of the current user.
11. EUID        Effective User ID (can differ from UID with sudo or setuid).
12. LANG        Locale setting (language and regional settings).
13. TERM        Terminal type.
14. RANDOM      Generates a random number between 0 and 32767.
15. SECONDS     Number of seconds since the shell started.
16. HISTFILE    File where command history is saved.
17. HISTSIZE    Number of commands stored in history.
18. HISTFILESIZE        Maximum number of lines in the history file.
19. BASH_VERSION        Version of Bash being used.
20. OSTYPE      Operating system type.
21. LINENO      Current line number in a script.
22. PPID        Process ID of the parent process.
23. COLUMNS     Number of columns in the terminal window.
24. LINES       Number of lines in the terminal window.

gawk '/user/ { print NR, $0 }' users.sh

# Assign the first command-line argument to a variable
pattern="$1"

# Use the shell variable inside the gawk command
cat file | gawk -v pattern="$pattern" '{ if ($1 ~ pattern) { print $1 " matches pattern!" } }'

# skip lines 2-4
sed '2,4! s/old/new/g' file.txt

#   how do we compare numbers in a shell
comparing numbers in a shell == or -eq

#   skips lines that are commented out
sed '/^#/! s/old/new/g' file.txt

# ignore any line containing error
grep -v 'error' file.txt | sed 's/old/new/g'

#   Signals
^C  Kill
^D  EOF
^Z  pause

#   separate commands with a ;
date; ls; read a b c ; echo $b ;


# what section has system calls in the 'man' command

