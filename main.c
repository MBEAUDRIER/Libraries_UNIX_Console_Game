*clrscr
#include <stdio.h>
#include<stdlib.h>

void clrscr(void);

int main()
{
    clrscr();
    return 0;
}

void clrscr(void)
{
    printf("\033[H\033[J");
}


*hide_cursor
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
