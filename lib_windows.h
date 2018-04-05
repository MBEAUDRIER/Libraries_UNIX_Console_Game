#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

char get_key(void);
void gotoxy(int x,int y);
void hidecursor(void);
void clrscr(void);

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

//Recherche du dernier caractère (renvoie 0 si il n'y a pas de caractère)
char get_key(void)
{
    char c=0;
    while(_kbhit()) {
        c = _getch();
    }
    return c;
}

// deplace le curseur sur l'écran aux coordonnées x et y
void gotoxy(int x,int y)
{
    HANDLE handle;
    COORD coord= {x,y};
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,coord);
}

// vide l'écran
void clrscr(void)
{
    HANDLE handle;
    COORD coord= { 0, 0 };
    DWORD nbcar;
    CONSOLE_SCREEN_BUFFER_INFO info;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle,&info);
    FillConsoleOutputCharacter(handle, (TCHAR) ' ',info.dwSize.X *
                               info.dwSize.Y,coord,&nbcar);
    SetConsoleCursorPosition(handle,coord);
}

