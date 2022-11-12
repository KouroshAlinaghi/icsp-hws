#include <stdio.h>

int main() {
    int code;
    float initial_jump;
    scanf("%d", &code);
    int room_code = code % 100;
    int floor = (code - room_code)/100;

    scanf("%f", &initial_jump);

    printf("%d\n", (room_code+3)/4);

    int jumps = 1;
    while ((0.5*initial_jump*jumps + initial_jump) < floor*2.0+1) {
        jumps++;
    }

    printf("%d", jumps);

    return 0;
}
