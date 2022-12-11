#include <stdio.h>

int main() {
    int array[100] = {};
    for (int i=0; i<100; i++) // I'm pretty sure ; is a typo mistake here, isn't it?
        array[i] = 3*i + 1;

    printf("%d\n", array);
    printf("%d\n", array[5]+1);
    printf("%d\n", &array[5]+1);

    return 0;
}

/*
    array holds the value &array[0] which is x1000      => 4096
    array[5] + 1 = 3*5 + 1 + 1 = 17                     => 17
    &array[5] + 1 = &array[0] + 5*4 (bytes) + 1*4 = 100 => 4120
*/