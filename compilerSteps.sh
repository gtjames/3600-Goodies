gcc helloWorld.c -E    ;   preprocessor to stdout
gcc helloWorld.c -S    ;   assembler

gcc -c helloWorld.c

nm helloWorld.o
objdump -t helloWorld.o

gcc helloWorld.o
