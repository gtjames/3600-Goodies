/*
 * usage: ./a.out text_pattern input_file output_file
 * Executes the command "grep text_pattern < input_file > output_file"
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int ifp, ofp;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s text_pattern input_file output_file\n", argv[0]);
        exit(1);
    }

	// grep on text_pattern 
	char *grep_args[] = {"grep", argv[1], NULL};

	// open input and output files
	ifp = open(argv[2], O_RDONLY);
	ofp = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	// duplicate input file to stdin
		// dup2(?);

	// duplicate output file to stdout
	

	// close unused input file descriptor
	
	
	// close unused output file descriptor
	

	// execute grep
	execvp("grep", grep_args);
}
