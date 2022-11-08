#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int seed = 810101476;
    srand(seed);
    int random_number = rand() % 100;
    while (true) {        
        printf("Enter your guess in [0, 100)\n");
        int guess;
        scanf("%d", &guess);
        if (guess == random_number) {
            printf("Heyyyyy, that's right!\n");
            break;
        } else if (guess > random_number) {
            printf("Your guess was bigger than the number;\n");
        } else {
            printf("Your guess was less than the number;\n");
        }
    }

    return 0;
}