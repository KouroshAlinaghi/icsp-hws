#include <stdio.h>

int main() {
    int code;
    float initial_jump;
    // printf("Please enter a code (room code)\n");
    scanf("%d", &code);
    int room_code = code % 100;
    int floor = (code - room_code)/100;

    // printf("Please enter height of the initial jump:\n");
    scanf("%f", &initial_jump);

    // printf("The area is #%d\n", (room_code+3)/4);
    printf("%d\n", (room_code+3)/4);

    int jumps = 1;
    while ((0.5*initial_jump*jumps + initial_jump) < floor*2.0+1) {
        jumps++;
    }

    // printf("Jumps: %d\n", jumps);
    printf("%d", jumps);

    return 0;
}