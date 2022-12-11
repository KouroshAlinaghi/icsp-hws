#include <stdio.h>

int main() {
    // int x[0], a=2;
    int x[1], a=2; // 1 - Size of an array should be positive
    
    // int *b = a, *x_ptr = &x;
    int *b = &a, *x_ptr = x; // 2 - value of pointer should be
                             // an address (*b = &a).
                             // 2.5 - *x_ptr = &x, would do the job too, since
                             // they both hold the same value, but they conflict in type.
    
    scanf("%d %d", b, x_ptr);
    
    // printf("a=%d, x=[%d]\n", *b, *x[0]);
    printf("a=%d, x=[%d]\n", *b, x[0]); // 3 - x[0] is not a pointer (nor address) so
                                        // we cannot use *x[0] syntax

    return 0;
}

/*
    The program takes two values from user and stores them
    in a and x[0]
*/