#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char name[10];
    int age;
    double score;
    cout << " cin, cout 연습 입니다. \n";

    cout << " 이 름 : ";
    cin >> name;

    cout << " 나 이 : ";
    cin >> age;

    cout << " 점 수 : ";
    cin >> score;

    cout << "cout으로 출력한 " << name << "씨의 나이는 ";
    cout << age << "살이고 점수는 " << score << " 점입니다.\n";

    printf("printf로 출력한 %s씨의 나이는 ", name);
    printf("%d살이고 점수는 %5.2lf 점입니다.\n", age, score);

    return 0;
}
