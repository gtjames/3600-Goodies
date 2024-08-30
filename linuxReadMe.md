Here is a list of some basic Linux commands along with a brief description of each:

**1. ls**

- **Description**: Lists directory contents.
  - ls: Lists files and directories in the current directory.
  - ls -l: Provides a detailed list, including file permissions, number of links, owner, group, size, and timestamp.
  - ls -a: Includes hidden files (those starting with a dot).

**2. cd**

- **Description**: Changes the current directory.
  - cd directory_path: Changes to the specified directory.
  - cd ..: Moves up one directory level.
  - cd ~: Changes to the home directory.

**3. pwd**

- **Description**: Prints the working directory, displaying the full path to the current directory.
  - pwd: Outputs the absolute path of the current directory.

**4. touch**

- **Description**: Creates an empty file or updates the access and modification times of an existing file.
  - touch filename: Creates a new, empty file named filename.

**5. cp**

- **Description**: Copies files and directories.
  - cp source destination: Copies a file from source to destination.
  - cp -r source_directory destination_directory: Recursively copies a directory and its contents.

**6. mv**

- **Description**: Moves or renames files and directories.
  - mv old_name new_name: Renames a file or directory.
  - mv file_path destination_path: Moves a file to the specified destination.

**7. rm**

- **Description**: Removes files or directories.
  - rm filename: Deletes the specified file.
  - rm -r directory_name: Recursively deletes a directory and its contents.
  - rm -f filename: Forcefully removes a file without prompting for confirmation.

**8. mkdir**

- **Description**: Creates new directories.
  - mkdir directory_name: Creates a new directory named directory_name.

**9. rmdir**

- **Description**: Removes empty directories.
  - rmdir directory_name: Deletes the specified empty directory.

**10. cat**

- **Description**: Concatenates and displays file content.
  - cat filename: Outputs the contents of the file to the terminal.
  - cat file1 file2 > combined_file: Concatenates multiple files and writes the output to a new file.

**11. nano or vi**

- **Description**: Text editors.
  - nano filename: Opens the file in the Nano text editor.
  - vi filename: Opens the file in the Vi text editor.

**12. echo**

- **Description**: Displays a line of text.
  - echo "Hello, World!": Prints "Hello, World!" to the terminal.
  - echo $VARIABLE: Displays the value of a shell variable.

**13. chmod**

- **Description**: Changes file permissions.
  - chmod 755 filename: Sets the permissions of the file to read, write, and execute for the owner, and read and execute for others.

**14. chown**

- **Description**: Changes file ownership.
  - chown owner:group filename: Changes the owner and group of the file.

**15. ps**

- **Description**: Displays currently running processes.
  - ps: Lists the current user's processes.
  - ps aux: Lists all running processes with detailed information.

**16. kill**

- **Description**: Terminates processes.
  - kill PID: Sends a signal to terminate the process with the specified PID (Process ID).
  - kill -9 PID: Forcefully kills the process.

**17. df**

- **Description**: Displays disk space usage.
  - df: Shows disk space usage for all mounted file systems.
  - df -h: Provides disk space usage in a human-readable format.

**18. du**

- **Description**: Estimates file space usage.
  - du: Summarizes disk usage of each file and directory.
  - du -h: Provides disk usage in a human-readable format.

**19. tar**

- **Description**: Archives files.
  - tar -cvf archive_name.tar directory: Creates a tar archive of the specified directory.
  - tar -xvf archive_name.tar: Extracts the contents of the tar archive.

**20. grep**

- **Description**: Searches for patterns within files.
  - grep "pattern" filename: Searches for "pattern" in the specified file.
  - grep -r "pattern" directory: Recursively searches for "pattern" in the specified directory.

**References**

- Linux Commands Cheat Sheet
- Basic Linux Commands
- Beginner's Guide to the Bash Terminal