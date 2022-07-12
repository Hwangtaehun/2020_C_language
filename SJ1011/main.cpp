#include<iostream>
#include<iomanip>
using namespace std;

#define STACK_SIZE 30
#define BOTTOM 0

int PriCompare(char ch1, char ch2);
int Priority(char ch);
int PostPush(char ch);
int OpPush(char ch);
char OpPop();
void InToPost(char* s);

char PostStack[STACK_SIZE];
char OpStack[STACK_SIZE];
int OpTop, PostTop;

int main(int argc, char** argv)
{
	char inFix[] = "A/B^C+D*E-A*C";

	InToPost(inFix);
	cout << "°á°ú" << endl;
	cout << inFix << "-->" << PostStack << endl;

	return 0;
}

void InToPost(char* s)
{
	int i = 0;
	OpTop = PostTop = -1;
	cout << "s[i] " << "PostStack" << setw(18) << "OpStack" << endl;

	while (s[i] != NULL)
	{
		if (Priority(s[i]) != 0)
		{
			while (OpTop >= BOTTOM && PriCompare(s[i], OpStack[OpTop]) <= 0)
			{
				PostPush(OpPop());
			}
			OpPush(s[i]);
		}
		else
		{
			PostPush(s[i]);
		}

		cout << setiosflags(ios::left);
		cout << s[i] << " :  " << setw(20) << PostStack << OpStack << endl;

		i++;
	}

	while (OpTop >= BOTTOM)
	{
		PostPush(OpPop());
	}
	PostPush('\0');
}

int PriCompare(char ch1, char ch2)
{
	int a, b;
	a = Priority(ch1);
	b = Priority(ch2);
	return(a - b);

}

int Priority(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	return 0;
}

int OpPush(char ch)
{
	if (OpTop >= STACK_SIZE - 1)
	{
		cout << "OpStack OverFlow \n";
		return -1;
	}
	OpTop++;
	OpStack[OpTop] = ch;
	return 0;
}

char OpPop()
{
	char data;
	if (OpTop < BOTTOM)
	{
		cout << "OpStack Underflow. \n";
		return -1;
	}
	data = OpStack[OpTop];
	OpStack[OpTop] = NULL;
	OpTop--;
	return data;
}

int PostPush(char ch)
{
	if (PostTop >= STACK_SIZE - 1)
	{
		cout << "PostStack OverFlow \n";
		return -1;
	}
	PostTop++;
	PostStack[PostTop] = ch;
	return 0;
}
