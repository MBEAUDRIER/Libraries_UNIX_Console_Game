
#include <stdio.h>
#include<stdlib.h>

void clrscr(void)
{
    printf("\033[H\033[J");
}

void hidecursor(void)
{
    printf("\e[?25l");
    fflush(stdout);
    return 0;
}

void gotoXY(int x,int y)
{
    printf("\x1b[%d;%dH",y,x);
    fflush(stdout);
}
