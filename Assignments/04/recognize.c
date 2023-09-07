#include <stdio.h>
 
void recognize(char s[], int sizeString) {
    // declaring a counter and a flag variable:
    int uniques_count = 0, found_match = 0;

    /*
        We loop through every char of string and
        check from start to that point if any character
        matches the current one. if it doesn't, we increase
        the counter by +1.
    */
    for (int i=0; i<sizeString; i++) {
        found_match = 0;

        for (int j=0; j<i; j++) {
            if (s[i] == s[j]) {
                found_match = 1;
                break;
            }
        }

        printf("%d\n", found_match);
        
        if (!found_match)
            uniques_count++;
    }

    if (uniques_count % 2 == 0) {
        printf("CHAT WITH THIS USER");
    } else {
        printf("BLOCK THIS USER");
    }
}