#include<cmath>
#include<cstdlib>
#include<iostream>

using namespace std;

#define STACK_SIZE 30
#define BOTTOM 0

struct STACK
{
	int num;
	char ch;
};

int PriCompare(char ch1, char ch2);
int Priority(char ch);
int PostPush(char* p, char op);
int OpPush(char ch);
char OpPop();
void InToPost(char* s);
int CompPush(int num);
int CompPop();
int Compute();

struct STACK PostStack[STACK_SIZE];
char OpStack[STACK_SIZE];
int CompStack[STACK_SIZE];
int OpTop, PostTop, CompTop;

int main(int ac, char** av)
{
	char inFix[30];
	int i, result;
	while (1)
	{
		cout << "계산식을 입력 (종료는 q)" << endl;
		cin >> inFix;
		if (toupper(inFix[0]) == 'Q')
			break;
		InToPost(inFix);
		cout << "inFix 표기 : " << inFix << endl;
		cout << "PostFix 표기 : " ;
		for (i = 0; i <= PostTop; i++)
		{
			if (PostStack[i].ch == 'D')
				cout << PostStack[i].num << " ";
			else
				cout << PostStack[i].ch << " ";
		}
		cout << endl;
		result = Compute();
		cout << "결과 = " << result << endl;
	}
	return 0;
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

int PostPush(char* p, char op)
{
	if (PostTop >= STACK_SIZE - 1)
	{
		cout << "PostStck OverFlow \n";
		return -1;
	}
	PostTop++;
	PostStack[PostTop].num = atoi(p);
	PostStack[PostTop].ch = op;
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
	OpTop--;
	return data;
}

void InToPost(char* s)
{
	int i = 0, n = 0;
	char buf[100];
	OpTop = PostTop = -1;
	while (s[i] != NULL)
	{
		if (Priority(s[i]) != 0)
		{
			if (n != 0)
			{
				buf[n] = NULL;
				PostPush(buf, 'D');
				n = 0;
			}
			while (OpTop >= BOTTOM && PriCompare(s[i], OpStack[OpTop]) <= 0)
			{
				PostPush("0", OpPop());
			}
			OpPush(s[i]);
		}
		else
		{
			buf[n] = s[i];
			n++;
		}
		i++;
	}
	if (n != 0)
	{
		buf[n] = NULL;
		PostPush(buf, 'D');
		n = 0;
	}
	while (OpTop >= BOTTOM)
	{
		PostPush("0", OpPop());
	}
}

int CompPush(int num)
{
	if (CompTop >= STACK_SIZE - 1)
	{
		cout << "CompStack OverFlow \n";
		return -1;
	}
	CompTop++;
	CompStack[CompTop] = num;
	return 0;
}

int CompPop()
{
	int data;
	if (CompTop < BOTTOM)
	{
		cout << "CompStack Underflow. \n";
		return -1;
	}
	data = CompStack[CompTop];
	CompTop--;
	return data;
}

int Compute()
{
	int i = 0, data1, data2, result = 0;
	CompTop = -1;
	for (i = 0; i <= PostTop; i++)
	{
		if (PostStack[i].ch != 'D')
		{
			data1 = CompPop();
			data2 = CompPop();
			switch (PostStack[i].ch)
			{
			case '+':
				result = data2 + data1;
				break;
			case '-':
				result = data2 - data1;
				break;
			case '*':
				result = data2 * data1;
				break;
			case '/':
				result = data2 / data1;
				break;
			case '^':
				result = (int)pow((double)data2, (double)data1);
				break;
			}
			CompPush(result);
		}
		else
		{
			CompPush(PostStack[i].num);
		}
	}
	return CompPop();
}
