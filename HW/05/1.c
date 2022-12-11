#include <stdio.h>

int main() {
    int array[4] = {1, 4, 7, 10};
    int *ptr1= (int *)(&array + 1);
    printf("%d\n", ptr1 - array);
    int *ptr2= (int *)(array + 1);
    printf("%d\n", ptr2 - array);

    return 0;
}

/*
    comparing by value, &array = array both
    hold the same values: &array[0]
    but considering types, they're different:
    array is a int*
    &array is int (*)[16]
    and this difference in type, makes these objects
    behave differently when doing mathematical operation
    such as + and -.
    array + 1 is the adress of array[1], but &array + 1 
    is the address of first byte after last item of array.
*/