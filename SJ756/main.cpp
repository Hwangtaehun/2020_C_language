#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define clrscr() system("cls");

void gotoxy(int x, int y)
{
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int walking (int **walk, int size);
int **GetMemory(int size);
void ReleaseMemory(int **walk, int size);

int main(int argc, char **argv)
{
    int **walk;
    int cnt, size;
    char ch;
    srand((unsigned int)time (NULL));
    while(1)
    {
        clrscr();
        printf(" *** RanDom Walker *** \n");
        printf("Ä­ ¼ö : ");
        scanf("%d", &size);
        if(size < 2)
            continue;
        walk = GetMemory( size );
        cnt = walking(walk, size);

        printf("\n\n\nÃÑÀÌµ¿È½¼ö = %d\n", cnt);
        ReleaseMemory(walk, size);
        printf("°è¼Ó (Y/N) ? ");
        scanf(" %c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }
    return 0;
}

int walking (int **walk, int size)
{
    int moveCnt = 0, ccnt =1;
    int x, y, bx, by;
    for(x = 0; x < size ; x++)
    {
         for(y = 0; y < size ; y++)
        {
            gotoxy((x+1)*5, y*2+5);
            printf("¡á");
        }
    }
    x = rand() % size;
    y = rand() % size;
    walk[y][x]++;
    while(1)
    {
        do{
            bx = x;
            bx += rand()%3-1;
        }while(bx < 0 || bx >= size);
        do{
            by = y;
            by += rand()%3-1;
        }while(by < 0 || by >= size);
        if(bx == x && by == y)
            continue;

        gotoxy((x+1)*5, y*2+5);
        printf("¡à");
        x = bx;
        y = by;
        walk[y][x]++;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        gotoxy((x+1)*5, y*2+5);
        printf("¡á");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        moveCnt++;
        gotoxy(5, size*2+5);
        printf("ÇöÀç ÀÌµ¿ È½¼ö : %d ", moveCnt);

        if(walk[y][x] == 1)
        {
            ccnt++;
            if(ccnt >= size*size)
                break;
        }
        Sleep(200);
    }
    return moveCnt;
}

int **GetMemory(int size)
{
    int i, **walk;
    walk = new int *[size];
    for(i=0;i<size;i++)
    {
        walk[i] = new int [size];
        memset(walk[i], 0, sizeof(int)*size);
    }
    return walk;
}

void ReleaseMemory(int **walk, int size)
{
    int i;
     for(i=0;i<size;i++)
    {
        delete[] walk[i];
    }
    delete [] walk;
}
