int play_smallest_of_all(int self_cards[4][11]);
int play_biggest_of_given_type(int self_cards[4][11], int type);
int play_biggest_except_given_type(int self_cards[4][11], int type);
int play_smallest_except_given_type(int self_cards[4][11], int type);
int play_smallest_of_given_type(int self_cards[4][11], int type);
int get_point_of_card(int card, int zamine, int hokm);

int determine_winner(int played_cards[4], int starter, int hokm) {
    int zamine = played_cards[starter]/11;
    int real_values_of_cards[4] = {0, 0, 0, 0};

    // See comments for get_point_of_card()
    for (int c=0; c<4; c++)
        real_values_of_cards[c] = get_point_of_card(played_cards[c], zamine, hokm);


    int max = real_values_of_cards[0];
    for (int i=1; i<4; i++) {
        if (real_values_of_cards[i] > max)
            max = real_values_of_cards[i];
    }

    for (int i=0; i<4; i++) {
        if (max == real_values_of_cards[i]) 
            return i;
    }
}

int decide_what_to_play(
    int player,
    int self_cards[4][11],
    int starter,
    int played_cards[4],
    int hokm
) {
    int zamine = played_cards[starter]/11;

    // If player isn't the starter
    if (starter != player) {

        // Emtiazi, Section 2:
        int points_of_cards_played[4] = {0, 0, 0, 0};
        for (int p=0; p<4; p++) {
            if (played_cards[p] != -1)
                points_of_cards_played[p] = get_point_of_card(played_cards[p], zamine, hokm);
        }

        int max = 0;
        for (int p=0; p<4; p++) {
            if (points_of_cards_played[p] > max)
                max = points_of_cards_played[p];
        }

        int friend = (player+2)%4;
        if (points_of_cards_played[friend] == max) {
            if (self_cards[zamine][10] == 0) {

                // We count the number of types which
                // player doesn't have any cards of it (except hokm)
                int num_of_zeros = 0;
                for (int t=0; t<4; t++) {
                    if (t == hokm)
                        continue;

                    if (self_cards[t][10] == 0)
                        num_of_zeros++;
                }

                // Player only has hokm
                if (num_of_zeros == 3)
                    return play_smallest_of_given_type(self_cards, hokm);
                
                // Player has cards other than hokm
                else
                    return play_smallest_except_given_type(self_cards, hokm);

            } else {
                return play_smallest_of_given_type(self_cards, zamine);
            }
        }

        // if player doesn't have zamine card
        if (self_cards[zamine][10] == 0) {

            // if player doesn't have any hokm
            if (self_cards[hokm][10] == 0)
                // it should play the smallest card
                return play_smallest_except_given_type(self_cards, hokm);
            // if player has hokm
            else
                // it should play the biggest hokm
                return play_biggest_of_given_type(self_cards, hokm);
        
        // if player does have zamine card
        } else
            return play_biggest_of_given_type(self_cards, zamine);
        
    // if player is the starter
    } else {
        // EMTIAZI, SECTION 2:
        int num_of_bigger_than_nines = 0;
        for (int t=0; t<4; t++) {
            if (self_cards[t][10] > 9)
                num_of_bigger_than_nines++;
        }

        // If player doesn't have any 10s or 11s
        if (num_of_bigger_than_nines == 0) {
            // it should play smallest card that isn't hokm
            return play_smallest_except_given_type(self_cards, hokm);
        }

        /*
            We count the number of types (except hokm) that
            the player doesn't have any cards of it.
            If it's 3, than it means that player only has hokm.
        */
        int num_of_zeros = 0;
        for (int t=0; t<4; t++) {
            if (t == hokm)
                continue;

            if (self_cards[t][10] == 0)
                num_of_zeros++;
        }

        // If player only has hokm, it should play biggest hokm.
        if (num_of_zeros == 3) {
            return play_biggest_of_given_type(self_cards, hokm);
        }
        
        // If player only has cards other than hokm, it should play
        // the biggest card that isn't hokm.
        else {
            return play_biggest_except_given_type(self_cards, hokm);
        }
    }
}

// Will play and return smallest card of all
int play_smallest_of_all(int self_cards[4][11]) {
    /*
        We'll creata an array with four integers, each integer
        is the smallest number of type (index) that player
        has. zero if player doesn't have any card of that type.
    */
    int smallest_of_each_type[4] = {0, 0, 0, 0};
    for (int t=0; t<4; t++) {
        for (int i=0; i<11; i++) {
            if (self_cards[t][i]) {
                smallest_of_each_type[t] = self_cards[t][i];
                break;
            }
        }
    }
    
    int least = 0;
    for (int i=0; i<4; i++) {
        if (least == 0 && smallest_of_each_type[i] > 0)
            least = smallest_of_each_type[i];
            
        if (smallest_of_each_type[i] && smallest_of_each_type[i] < least)
            least = smallest_of_each_type[i];
        else
            continue;
            
    }

    for (int i=0; i<4; i++) {
        if (least == smallest_of_each_type[i]) {
            int r = 11*i+smallest_of_each_type[i]-1;
                
            // Making the card zero.
            for (int j=0; j<11; j++) {
                if (self_cards[i][j]) {
                    self_cards[i][j] = 0;
                    break;
                }
            }

            return r;
        }
    }
}

// Will play and return biggest card of given type
int play_biggest_of_given_type(int self_cards[4][11], int type) {
    // Making the card zero.
    int r = 11*type + self_cards[type][10]-1;
    self_cards[type][10] = 0;
    return r;
}

// Will play and return biggest card of all types except the given one.
int play_biggest_except_given_type(int self_cards[4][11], int type) {
    int biggest_of_each_type[4] = {0, 0, 0, 0};
    for (int t=0; t<4; t++)
        biggest_of_each_type[t] = self_cards[t][10];

    biggest_of_each_type[type] = 0;
    int max = biggest_of_each_type[0];

    for (int t=1; t<4; t++) {
        if (biggest_of_each_type[t] > max)
            max = biggest_of_each_type[t];
    }

    for (int t=0; t<4; t++) {
        if (biggest_of_each_type[t] == max) {
            int r = 11*t + max-1;
            self_cards[t][10] = 0;
            return r;
        }
    }
}

// Will play and return smallest card of all types except the given one.
int play_smallest_except_given_type(int self_cards[4][11], int type) {
    /*
        We'll creata an array with four integers, each integer
        is the smallest number of type (index) that player
        has. zero if player doesn't have any card of that type.
    */
    int smallest_of_each_type[4] = {0, 0, 0, 0};
    for (int t=0; t<4; t++) {
        for (int i=0; i<11; i++) {
            if (self_cards[t][i]) {
                smallest_of_each_type[t] = self_cards[t][i];
                break;
            }
        }
    }

    // So it wont play card of type __type__
    smallest_of_each_type[type] = 11;
    
    int least = 0;
    for (int i=0; i<4; i++) {
        if (least == 0 && smallest_of_each_type[i] > 0)
            least = smallest_of_each_type[i];
                
        if (smallest_of_each_type[i] && smallest_of_each_type[i] < least)
            least = smallest_of_each_type[i];
        else
            continue;
            
    }

    for (int i=0; i<4; i++) {
        if (least == smallest_of_each_type[i]) {
            int r = 11*i+smallest_of_each_type[i]-1;
                
                // Making the card zero.
            for (int j=0; j<11; j++) {
                if (self_cards[i][j]) {
                    self_cards[i][j] = 0;
                    break;
                }
            }

            return r;
        }
    }
}
    
// Will play and return smallest card of given type
int play_smallest_of_given_type(int self_cards[4][11], int type) {
    for (int n=0; n<11; n++) {
        if (self_cards[type][n]) {
            int r = 11*type + self_cards[type][n]-1;
            self_cards[type][n] = 0;
            return r;
        }
    }
}

/*
    An idea came to my mind, we create a new array with
    values of cards in it. the values are calculated like this:
        1) if card is not hokm and is not zamine, it doesn't
        have any value, it's zero. (you can never win a round like this!)
        
        2) if card is the same type of zamine, it has the value of 
        the card's number.

        3) if zamine is not hokm and card is hokm, it has the value
        of the card's number + 11.

    At the end, we see which player played the card with most value
    and return the index of that player. (0, 1, 2, 3)
*/
int get_point_of_card(int card, int zamine, int hokm) {
    if (card/11 == zamine) {
        return card%11 + 1;
    } else {
        if (card/11 == hokm) {
            return 11 + card%11 + 1;
        } else {
            return 0;
        }
    }
}