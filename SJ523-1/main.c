#include <stdio.h>
#define DATA_CNT 11

int main()
{
	int data[DATA_CNT] = { 1,3,5,7,9,11,13,15,17,19,21 };
	int i, key, sw = 0;
	printf("ã�� �ڷ� �Է� : ");
	scanf("%d", &key);

	for (i = 0; i < DATA_CNT; i++)
	{
		if (data[i] == key)
		{
			sw = 1;
			break;
		}
	}
	printf(" �˻� Ƚ�� %d\n", i + 1);
	if (sw == 1)
	{
		printf("ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("ã�� �� �����ϴ�.\n");
	}

	i = 0;
	while (data[i] < key && i < DATA_CNT)
	{
		i++;
	}
	printf(" �˻� Ƚ�� %d\n", i + 1);
	if(data[i]==key)
	{
		printf("ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("ã�� �� �����ϴ�.\n");
	}

	return 0;
}
