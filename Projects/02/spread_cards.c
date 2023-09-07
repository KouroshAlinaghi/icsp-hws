#include <stdio.h>

void spread_cards(int cards[4][11], int players_cards[4][4][11], int *hokm) {
    // giving first 5 cards to player 0:
    int i=0;
    for (int c=0; c<5; c++, i++) {
        int card = cards[i/11][i%11];
        players_cards[0][card/11][card%11] = card%11 + 1;
    }

    printf("Your cards are:\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<11; j++) {
            if (players_cards[0][i][j] == 0) 
                continue;

            printf("%c%d ", i+65, players_cards[0][i][j]);
        }
    }

    // Getting bakhshnameh:
    printf("\nPlease choose your Bakhshnameh!\n");
    while (scanf("%c", hokm) == 0 || *hokm > 68 || *hokm < 65);
    *hokm  = *hokm - 65;

    // 5
    for (int p=1; p<4; p++) {
        for (int c=0; c<5; c++, i++) {
            int card = cards[i/11][i%11];
            players_cards[p][card/11][card%11] = card%11 + 1;
        }
    }
        
    // 4
    for (int p=0; p<4; p++) {
        for (int c=0; c<4; c++, i++) {
            int card = cards[i/11][i%11];
            players_cards[p][card/11][card%11] = card%11 + 1;
        }
    }  

    // 2
    for (int p=0; p<4; p++) {
        for (int c=0; c<2; c++, i++) {
            int card = cards[i/11][i%11];
            players_cards[p][card/11][card%11] = card%11 + 1;
        }
    }
}