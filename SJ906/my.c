#include <stdio.h>
#include <windows.h>
#define clrscr() system("cls")

void Line(int cnt, char ch)
{
    int i;
    for (i = 0; i < cnt; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}

void Spc(int cnt)
{
    int i;
    for (i = 0; i < cnt; i++)
    {
        putchar(' ');
    }
}

void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
