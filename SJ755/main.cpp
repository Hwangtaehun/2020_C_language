#include <stdio.h>
#define STACK_SIZE 5
#define BOTTOM 0

int stack[STACK_SIZE];
int top;
void ClearStack(void);
int Push(int data);
int Pop(void);
void DisplayStack(void);

int main(int ac, char **av)
{
    int i, n;
    ClearStack();
    Push(55);
    Push(44);
    Push(77);
    Push(66);
    printf("55, 44, 77, 66 Push �� Stack ����\n");
    DisplayStack();

    printf("pop --> %d \n", Pop());
    printf("pop --> %d \n", Pop());
    printf("Pop 2�� ���� �� stack ����\n");
    DisplayStack();

    for(i=0;i<5;i++)
    {
       if(Push(i+10) == -1)
        break;
    }
    printf("Pop %d�� ���� �� stack ����\n", i);
    DisplayStack();

    for(i=0;i<10;i++)
    {
       n = Pop();
       if(n == -1)
        break;
        printf("pop --> %d \n", n);
    }
    printf("Pop %d�� ���� �� stack ����\n", i);
    DisplayStack();

    Push(55);
    Push(44);
    printf("55, 44 Push �� Stack ����\n");
    DisplayStack();

    ClearStack();
    printf("ClearStack ���� �� Stack ����\n");
    DisplayStack();

    return 0;
}

void ClearStack(void)
{
    top = -1;
}

int Push(int data)
{
    if(top >= STACK_SIZE -1)
    {
        printf("Stack�� ���Ŀ�.\n");
        return -1;
    }
    top++;
    stack[top] = data;
    return data;
}

int Pop(void)
{
    int data;
    if(top < BOTTOM)
    {
        printf("Stack�� �ڷᰡ �����.\n");
        return -1;
    }
    data = stack[top];
    top--;
    return data;
}

void DisplayStack(void)
{
    int i;
    printf("Stack : ");
    for(i = top; i >= 0; i--)
    {
        printf("%-6d", stack[i]);
    }
    printf("\n");
}
