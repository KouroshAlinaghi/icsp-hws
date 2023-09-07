#include <stdio.h>

int main() {
    FILE* my_file = fopen("file.txt", "w");

    fputs("Help", my_file);
    fseek(my_file, 3, SEEK_SET);
    fputs("local", my_file);
    fseek(my_file, 5, SEEK_SET);
    fputs("Friday", my_file);
    fseek(my_file, 8, SEEK_SET);
    fputs("end!", my_file);
    
    return 0;
}

/*
    1 - We put "Help".
    2 - We move the pointer to after l in "Helo".
    3 - We put "local" => text is "Hellocal".
    4 - We move the pointer to after o in "Hellocal".
    5 - We put "Friday" => text is "HelloFriday".
    6 - We move the pointer to after i in "HelloFriday".
    7 - We put "end!", so the text is going to be "HelloFriend!"!
*/