#include <stdio.h>
#include <string.h>

#include <libgeometry/checkarg.h>
#include <libgeometry/vocabulary.h>

int isCircle(char* str)
{
    if (Figure(str) == 1)
        return 1;

    if (checkArg(str) == 2)
        return 2;

    if (checkArg(str) == 3)
        return 3;

    if (End(str) == 4)
        return 4;

    if (End(str) == 5)
        return 5;

    return 0;
}

void Error(char* line, int check, int num)
{
    printf("\nFigure %d.\n %s", num, line);
    switch (check) {
    case 1:
        printf(" Incorrect input of figure name\n");
        break;
    case 2:
        printf(" Figure coordinates entered incorrectly\n");
        break;
    case 3:
        printf(" Figure radius entered incorrectly\n");
        break;
    case 4:
        printf(" Wrong final symbol\n");
        break;
    case 5:
        printf(" Wrong final symbol\n");
        break;
    }
}
