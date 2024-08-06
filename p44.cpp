#include <stdio.h>
#include <string.h>

int main()
{

    char x[9];
    int i;

    x[0] = 'C';
    x[1] = 'O';
    x[2] = 'M';
    x[3] = 'P';
    x[4] = 'I';
    x[5] = 'L';
    x[6] = 'E';
    x[7] = 'R';
    x[8] = '\0';

    i = 0;
    while (x[i] != '\0')
        putchar(x[i++]); // putchar() is a function that prints a single character to the screen
}