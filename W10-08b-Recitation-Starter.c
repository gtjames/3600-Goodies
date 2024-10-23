/*
 * usage: ./a.out input_file text_pattern
 * Executes the command "cat input_file | grep text_pattern | cut -b 1-10".
 * Note only minimal error checking is done for simplicity/shortness of code.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int status;
	int i;

	if (argc == 3)
	{
		// arguments for commands
		char *cat_args[]  = {"cat", argv[1], NULL};
		char *grep_args[] = {"grep", argv[2], NULL};
		char *cut_args[]  = {"cut", "-b", "1-10", NULL};

		// file descriptors for 2 pipes: fd1 for cat-to-grep, fd2 for grep-to-cut
		int fd1[2], fd2[2];

        	// make pipe for cat to grep
		// fd1[0] = read  end of cat->grep pipe (read by grep)
		// fd1[1] = write end of cat->grep pipe (written by cat)
		

        	// make pipe for grep to cut
		// fd2[0] = read  end of grep->cut pipe (read by cut)
		// fd2[1] = write end of grep->cut pipe (written by grep)
		
		
		// fork the first child (to execute cat)
		if (fork() == 0)
		{
			// duplicate write end of cat->grep pipe to stdout
			

			// close both ends of all created fd# pipes (very important!)
      			
      			
      			
      			

           	 	execvp(*cat_args, cat_args);
 	 	}
		else // parent (assume no error)
    		{
          		// fork second child (to execute grep)
          		if (fork() == 0)
    			{
    	  			// duplicate read end of cat->grep pipe to stdin (of grep)
    	  			
    
    	  			// duplicate write end of grep->cut pipe to stdout (of grep)
    	  			
    
    	  			// close both ends of all created fd# pipes (very important!)
    	  			
    	  			
    	  			
    	  			
    
    	  			execvp(*grep_args, grep_args);
    			}
         		 else // parent (assume no error)
    			{
    	  			// fork third child (to execute cut)
    	  			if (fork() == 0)
                    		{
                        		// duplicate read end of grep->cut pipe to stadin (of cut)
    	      				
    
                        		// close both ends of all created fd# pipes (very important!)
    	      				
    	      				
    	      				
    	      				
    
                        		execvp(*cut_args, cut_args);
                    		}
    			}
      		}
      
  		// only the parent gets here, close all pipes and wait for 3 children to finish
  		close(fd1[0]);
  		close(fd1[1]);
  		close(fd2[0]);
  		close(fd2[1]);

  		for (i = 0; i < 3; i++)
		{
    			wait(&status);
		}
	}
	else
	{
		printf("usage: %s input_file text_pattern\n", argv[0]);
	}

	return 0;
}
