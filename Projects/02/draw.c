#include <stdio.h>

#define SPACE_FROM_LEFT 8
#define BOARD_WIDTH 60
#define BOARD_HEIGHT 11
#define TABLE_WIDTH 5*num_of_cards+1

void print_multipy(char c, int times);

// Will draw the board and scores and cards tables
void draw(
    int players_cards[4][4][11],
    int hokm,
    int round,
    char msg[],
    int points[2],
    int played_cards[4],
    int sets[2]
) 
{
    int num_of_cards = 11-round;

    printf("Hokm: %c\n", hokm+65);

    if (played_cards[2] == -1) {
        print_multipy(' ', SPACE_FROM_LEFT+(BOARD_WIDTH-2)/2);
        printf("P3\n");
    } else {
        print_multipy(' ', SPACE_FROM_LEFT+(BOARD_WIDTH-6)/2);
        printf("P3 (%c%02d)\n", (played_cards[2]/11)+65, played_cards[2]%11 + 1);
    }
    
    print_multipy(' ', SPACE_FROM_LEFT);
    print_multipy('-', BOARD_WIDTH);
    print_multipy(' ', SPACE_FROM_LEFT);
    printf("Team 1: ");
    printf("%d", points[0]);

    for (int i=0; i<BOARD_HEIGHT; i++) {
        printf("\n");
        if (i == BOARD_HEIGHT/2) {
            print_multipy(' ', SPACE_FROM_LEFT-2);

            if (played_cards[1] == -1) {
                printf("P2|");
            } else {
                printf("P2|(%c%02d)", (played_cards[1]/11)+65, played_cards[1]%11 + 1);
            }
        } else {
            print_multipy(' ', SPACE_FROM_LEFT);
            printf("|");
        }
        
        if (i == BOARD_HEIGHT/2) {
            if (played_cards[1] == -1) {            
                print_multipy(' ', BOARD_WIDTH-2);
            } else {
                print_multipy(' ', BOARD_WIDTH-9);
            }

            if (played_cards[3] == -1) {
                printf("|P4");
            } else {
                printf("P4|(%c%02d)", (played_cards[3]/11)+65, played_cards[3]%11 + 1);
            }
        } else {
            print_multipy(' ', BOARD_WIDTH-2);
            printf("|");
        }

        if (i == 2) {
            print_multipy(' ', SPACE_FROM_LEFT-4);
            printf("Team 1 total sets: %d", sets[0]);
        }

        if (i == BOARD_HEIGHT-3) {
            print_multipy(' ', SPACE_FROM_LEFT-4);
            printf("Team 2 total sets: %d", sets[1]);
        }
    }

    printf("\n");
    print_multipy(' ', SPACE_FROM_LEFT);
    print_multipy('-', BOARD_WIDTH);
    print_multipy(' ', SPACE_FROM_LEFT);
    printf("Team 2: ");
    printf("%d", points[1]);
    printf("\n");

    if (played_cards[0] == -1) {
        print_multipy(' ', SPACE_FROM_LEFT+(BOARD_WIDTH-2)/2);
        printf("P1");
    } else {
        print_multipy(' ', SPACE_FROM_LEFT+(BOARD_WIDTH-5)/2);
        printf("P1 (%c%02d)", (played_cards[0]/11)+65, played_cards[0]%11 + 1);
    }
    printf("\n");
    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT);
    print_multipy('-', TABLE_WIDTH);
    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT-7);
    printf("Symbol");
    printf(" |");
    for (int i=0; i<4; i++) {
        for (int j=0; j<11; j++) {
            if (players_cards[0][i][j]) {
                printf(" %c  |", i+65);
            }
        }
    }

    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT);
    print_multipy('-', TABLE_WIDTH);
    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT-7);
    printf("Number");
    printf(" |");
    for (int i=0; i<4; i++) {
        for (int j=0; j<11; j++) {
            if (players_cards[0][i][j]) {
                printf(" %02d |", players_cards[0][i][j]);
            }
        }
    }

    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT);
    print_multipy('-', TABLE_WIDTH);
    printf("\n");

    print_multipy(' ', SPACE_FROM_LEFT+1);
    for (int i=0; i<num_of_cards; i++) {
        printf(" %02d  ", i);
    }
    printf("\n");
    printf("\n");

    printf("%s", msg);
    printf("\n");
}

/*
    this function takes a char and an int: times and
    prints the char to the console __times__ times
*/
void print_multipy(char c, int times) {
    for (int i=0; i<times; i++)
        putchar(c);
}
