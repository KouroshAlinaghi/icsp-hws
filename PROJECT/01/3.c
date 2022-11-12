#include <stdio.h>
#define FUNC (x*x*x + a*x*x + b*x + c)

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    float deghat;
    scanf("%f", &deghat);

    // this is a terrible way to get max of a
    // list of numbers, but anyway
    int max_square;
    if (a >= b) {
        if (c > a) {
            max_square = c*c;
        } else {
            max_square = a*a;
        }
    } else {
        if (c > b) {
            max_square = c*c;
        } else {
            max_square = b*b;
        }
    }

    int answers_found = 0;
    float last_answer = 0;
    for (float x=-max_square; x<=max_square; x+=0.0001) {
        if (
            // the same as |func| <= deghat (because deghat > 0)
            (FUNC*FUNC <= deghat*deghat) && 
            // here we make sure that we don't count numbers that 
            // are so close to out previous answer (because they represent
            // the same root in fact)
            ((last_answer-x) * (last_answer-x) >= (deghat*deghat))
           )
        {
            last_answer = x;
            printf("%.2f\n", last_answer);
            answers_found++;
        }
    }

    // print "bedoon rishe" (3 - answers_found) times
    for (int i=1; i<=(3-answers_found); i++)
        printf("bedoon rishe\n");

    return 0;
}
