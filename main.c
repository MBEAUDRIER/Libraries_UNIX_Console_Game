#include <stdio.h>

int main()
{
    hidecursor();
    return 0;
}

void hidecursor(void)
{
    printf("\e[?25l");
    fflush(stdout);
    return 0;
}

void gotoxy(int x,int y)
{
    printf("\x1b[%d;%dH",y,x);
    fflush(stdout);
}
