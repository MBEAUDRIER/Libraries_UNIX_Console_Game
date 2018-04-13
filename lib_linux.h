
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

struct termios orig_termios;

void clrscr(void)
{
    printf("\033[H\033[J");
}

void hidecursor(void)
{
    printf("\e[?25l");
    fflush(stdout);
}

void gotoXY(int x,int y)
{
    printf("\x1b[%d;%dH",y,x);
    fflush(stdout);
}

void init()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);

    /* register cleanup handler, and set the new terminal mode */
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int get_key()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}
