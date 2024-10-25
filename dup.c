/* This program demonstrates the dup and dup2 system calls.
You must have a file present in the directory called "test.txt".
It may be empty or have stuff in it doesn't matter. */ 
#include <stdio.h>
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/file.h> 
#include <unistd.h> 

int main() {
    int fd1, fd2, fd3;
    
    fd1 = open("test.txt", O_RDWR | O_TRUNC); 
    printf("fd1 = %i\n", fd1);
    write(fd1, "what's", 6);
 
    fd2 = dup(fd1);             /* make a copy of fd1 */ 
    printf("fd2 = %i\n", fd2);
    write(fd2, " up", 3);       /* write 3 bytes to dup'd fd */
    close(0);                   /* close standard input */
 
    fd3 = dup(fd1);             /* make another copy of fd1 */ 
    printf("fd3 = %i\n", fd3);  /*  note that fd3 is now 0  */
    write(0, " doc", 4);        /* because 0 was the smallest file descriptor */
                                /* and now belongs to fd3 */

    dup2(3, 2);                 /* duplicate channel 3 to channel 2 */ 
    write(2, "?\n", 2);
}
