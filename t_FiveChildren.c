#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


// five-children.c
static const size_t kNumChildren = 5;
static size_t numChildrenDonePlaying = 0;

static void reapChild(int sig) {
    waitpid(-1, NULL, 0);
    numChildrenDonePlaying++;
    printf("Num of children. %zu\n", numChildrenDonePlaying);
}
int main(int argc, char *argv[]) {
    printf("Let my five children play while I take a nap.\n");
    signal(SIGCHLD, reapChild);
    for (size_t kid = 1; kid <= kNumChildren; kid++) {
        if (fork() == 0) {
            sleep(3 * kid); // sleep emulates "play" time
            printf("Child #%zu tired... returns to parent.\n", kid);
            return 0;
        }
    }
    while (numChildrenDonePlaying < kNumChildren) {
        printf("At least one child still playing, so parent nods off.\n");
        sleep(5); // custom fn to sleep uninterrupted
        printf("Parent wakes up! ");
    }
    printf("All children accounted for.  Good job, parent!\n");
    return 0;
}