#include <unistd.h>

int main(int argc, char *argv[]) {
    char    *buf = "Hello world!";

    write(1, buf += 6, 6);
}