#include <stdio.h>

int main() {
    char x;
    printf("Please enter a character:\n");
    scanf("%c", &x);
    printf("%d\n", x); // Output: 115

    // ---------------------------
    
    float y;
    printf("Please enter a decimal number:\n");
    scanf("%d", &y);
    printf("%f\n", y);

    /*
     *
     * Decimal 1092091904 to binary => 1000001000110000000000000000000 
     *   to IEEE-754 floating point => 9.5
     * 
    */

    return 0;
}
