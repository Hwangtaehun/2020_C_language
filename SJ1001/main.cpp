#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char name[10];
    int age;
    double score;
    cout << " cin, cout ���� �Դϴ�. \n";

    cout << " �� �� : ";
    cin >> name;

    cout << " �� �� : ";
    cin >> age;

    cout << " �� �� : ";
    cin >> score;

    cout << "cout���� ����� " << name << "���� ���̴� ";
    cout << age << "���̰� ������ " << score << " ���Դϴ�.\n";

    printf("printf�� ����� %s���� ���̴� ", name);
    printf("%d���̰� ������ %5.2lf ���Դϴ�.\n", age, score);

    return 0;
}
