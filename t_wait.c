#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t children[8];
    for (size_t i = 0; i < 8; i++) {
        if ((children[i] = fork()) == 0)    //  save child pid
            exit(110 + i);                  //  child dies immediately
    }
    for (size_t i = 0; i < 8; i++) {        //  loop to wait on each child
        int status;

        pid_t pid = waitpid(children[i], &status, 0);   //  waiting until child is complete
        assert(pid == children[i]);                     //  childId better match
        assert(WIFEXITED(status) && (WEXITSTATUS(status) == (110 + i)));
        printf("Child with pid %d accounted for (return status of %d).\n",
            children[i], WEXITSTATUS(status));
    }
    return 0;
}