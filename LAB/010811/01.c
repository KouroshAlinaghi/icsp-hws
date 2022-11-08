#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    printf("Recieved: %d\n", input);
    if (input == 5) { // wrong, should've been input == 5
        printf("Your number was 5\n");
    } else if (input > 5) {
        printf("Your number was greater than 5\n");
    } else {
        printf("Your number was less than 5!\n");
    }
    return 0;
}