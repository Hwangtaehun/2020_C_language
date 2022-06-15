#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    int i, JulianDay;

    printf("날짜 입력(년 월 일) : ");
    scanf("%d %d %d", &year, &month, &day);
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        days[2] = 29;
    }
    else{
        days[2] = 28;
    }

    JulianDay = 0;
    for(i = 1; i < month; i++){
        JulianDay += days[i];
    }
    JulianDay += day;
    printf("%d년 %d월 %d일의 JulianDay는 %d입니다.\n", year, month, day, JulianDay);
    return 0;
}
