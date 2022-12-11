#include <stdio.h>
#include <stdlib.h>

/*
    argc is the number of arguments being passed into
    the program from the command line and argv is the
    array of arguments.
*/
int main(int argc, char** argv) {
    int input, i, result = 1;
    // If there is no argument
    if (argc != 2) {
        printf("Missing Argument.\n");
        exit(EXIT_FAILURE);
    }

    input = atoi(argv[1]); // Converting ASCII to int.
    for (i=1; i<=input; ++i)
        result *= i;

    printf("The result is %d\n", result);
    return 0;
}