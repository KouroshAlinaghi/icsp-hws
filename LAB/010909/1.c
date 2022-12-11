#include <stdio.h>

int main() {
    int x;
    int *ptr;
    int **ptr2;
    int ***ptr3;
    
    // not yours
    // ptr = 20; 

    x = 25;
    ptr = &x; // adress of x
    ptr2 = &ptr; // adress of ptr
    *ptr = 2 * **ptr2; // x = 2 * x

    printf("x = %d and adress of x = 0x%p = 0x%p = 0x%x = 0x%p \n",
            x, ptr, &x, &x, *ptr2
          );

    // prints the adress saved in ptr (0)
    printf("x = %d", ptr);
    return 0;
}