#ifndef MY_H_INCLUDED
#define MY_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define clrscr() system("cls")

void Line(int cnt, char ch);
void Spc(int cnt);
void gotoxy(int x, int y);

#endif // MY_H_INCLUDED
