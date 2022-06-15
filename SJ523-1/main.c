#include <stdio.h>
#define DATA_CNT 11

int main()
{
	int data[DATA_CNT] = { 1,3,5,7,9,11,13,15,17,19,21 };
	int i, key, sw = 0;
	printf("찾을 자료 입력 : ");
	scanf("%d", &key);

	for (i = 0; i < DATA_CNT; i++)
	{
		if (data[i] == key)
		{
			sw = 1;
			break;
		}
	}
	printf(" 검색 횟수 %d\n", i + 1);
	if (sw == 1)
	{
		printf("찾았습니다.\n");
	}
	else
	{
		printf("찾을 수 없습니다.\n");
	}

	i = 0;
	while (data[i] < key && i < DATA_CNT)
	{
		i++;
	}
	printf(" 검색 횟수 %d\n", i + 1);
	if(data[i]==key)
	{
		printf("찾았습니다.\n");
	}
	else
	{
		printf("찾을 수 없습니다.\n");
	}

	return 0;
}
