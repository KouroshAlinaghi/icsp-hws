#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "draw.h"
#include "spread_cards.h"
#include "rules.h"
#include <unistd.h>

#define NUM_OF_PLAYERS 4
#define NUM_OF_TYPES 4
#define NUM_OF_CARDS 11
#define NUM_OF_TEAMS 2
#define A_ASCII_CODE 65

void shuffle_card(int* card);
void my_sort(int arr[NUM_OF_CARDS], int size);
int get_card_from_index(int self_cards[NUM_OF_TYPES][NUM_OF_CARDS], int choice, int *row);

int main() {
    int sets[NUM_OF_TEAMS] = {0, 0};

    while (1) {
        /*
            [
                Player 0: [
                    Type A: [0, 0, 1, 11, 3, ..]
                    Type B: ..
                    ...
                    ...
                ],
                Player 1: ...
                ...
                ...
            ]
        */
        int players_cards[NUM_OF_PLAYERS][NUM_OF_TYPES][NUM_OF_CARDS] = {0};
        int cards[NUM_OF_TYPES][NUM_OF_CARDS] = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, // A
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, // B
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, // C
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}  // D
        };
        int points[NUM_OF_TEAMS] = {0, 0};
        int round = 0, turn = 0, starter = 0;
        int hokm = 0; // 0, 1, 2, 3

        // Checking if the game's finished
        for (int team=0; team<NUM_OF_TEAMS; team++) {
            if (sets[team] >= 3) {
                printf("TEAM %d WON THE GAME!\n", team+1);
                return 0;
            }
        }

        shuffle_card(cards);
        spread_cards(cards, players_cards, &hokm);

        // Sorting all cards for each player and type:
        for (int p=0; p<NUM_OF_PLAYERS; p++) {
            for (int t=0; t<NUM_OF_TEAMS; t++) {
                my_sort(players_cards[p][t], NUM_OF_CARDS);
            }
        }

        while (1) {
            int flag = 0;
            for (int team=0; team<NUM_OF_TEAMS; team++) {
                if (points[team] == 6) {
                    printf("TEAM %d WON THE SET!\n", team+1);
                    sets[team]++;

                    if (points[!team] == 0)
                        sets[team]++;
                        
                    flag = 1;
                    break;
                }
            }
            if (flag) 
                break;
            /* 
                one for each player, containing a number in [0, 43]
            */
            int cards_played[NUM_OF_PLAYERS] = {-1, -1, -1, -1};
            int circles_turned = 0;
            turn = starter;
            int played_card;

            while (1) {
                for (int p=0; p<NUM_OF_PLAYERS; p++) {
                    for (int t=0; t<NUM_OF_TYPES; t++) {
                        my_sort(players_cards[p][t], NUM_OF_CARDS);
                    }
                }
                
                if (turn == 0)
                    draw(players_cards, hokm, round, "It's your turn, choose!", points, cards_played, sets);
                else
                    draw(players_cards, hokm, round, "Wait for your turn", points, cards_played, sets);

                // wait ~1 second so we can see what other players play.
                for (int i=0; i<300000000; i++);

                if (starter == turn) 
                    circles_turned++;

                // if all players have played a card in this round:
                if (circles_turned==2) {
                    /*
                        we assign the value of winner (returned by determine_winner())
                        to starter for next round and break out of this round.
                    */
                    starter = determine_winner(cards_played, starter, hokm);
                    points[starter%2]++;
                    break;
                }

                if (turn == 0) {
                    // choice will be in [0, 11-round)
                    int choice, scanf_result;
                    while (1) {
                        scanf_result = scanf("%d", &choice);
                        if (scanf_result == 0) {
                            while (getchar() != '\n');
                            continue;
                        }
                        
                        if (choice < 0 || choice > (NUM_OF_CARDS-round-1))
                            continue;

                        int row;
                        played_card = get_card_from_index(players_cards[0], choice, &row);

                        if (starter != turn) {
                            int zamine = cards_played[starter]/NUM_OF_CARDS;
                            if (players_cards[turn][zamine][NUM_OF_CARDS-1] != 0 && played_card/NUM_OF_CARDS != zamine) {
                                draw(players_cards, hokm, round, "You should play zamine, since you got card(s) from it", points, cards_played, sets);
                                continue;
                            }
                        }

                        players_cards[0][played_card/NUM_OF_CARDS][row] = 0;
                        break;
                    }
                    
                    
                } else {
                    played_card = decide_what_to_play(
                        turn,
                        // the player should not know about other players cards!
                        players_cards[turn],
                        starter,
                        cards_played,
                        hokm
                    );
                }
                cards_played[turn] = played_card;
                turn = (turn + 1)%NUM_OF_PLAYERS;
            }
            round++;
        }
    }

    return 0;
}

void shuffle_card(int* card) {
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}

// Used this function for development, kind of don't 
// want to delete it, so here it will stay.
int print_cards(int players_card[NUM_OF_PLAYERS][NUM_OF_TYPES][NUM_OF_CARDS]) {
    for (int p=0; p<NUM_OF_PLAYERS; p++) {
        printf("%d:\n", p);
        for (int t=0; t<NUM_OF_TYPES; t++) {
            printf("    %c:\n       ", t+A_ASCII_CODE);
            for (int c=0; c<NUM_OF_CARDS; c++) {
                printf("%d ", players_card[p][t][c]);
            }
            printf("\n");
        }
    }
}

// We sort players cards everytime we wanna do calculation
// of the cards, since it's based on sort.
void my_sort(int arr[NUM_OF_CARDS], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Get number of card from index (choice) in [0, (11-round-1)]
int get_card_from_index(int self_cards[NUM_OF_TYPES][NUM_OF_CARDS], int choice, int *row) {
    int played_card;
    /*
        Ugly code alert:
            We get choice as a number in [0 and 11-round).
            Here we create played_card (in [0, 43]) based
            on value of choice.
    */                       
    for (int index=0, t=0; t<NUM_OF_TYPES; t++) {
        for (int i=0; i<NUM_OF_CARDS; i++) {
            if (!self_cards[t][i]) 
                continue;

            if (choice == index) {
                *row = i;
                return NUM_OF_CARDS*t + self_cards[t][i]-1;
            }

            index++;
        }
    }
}