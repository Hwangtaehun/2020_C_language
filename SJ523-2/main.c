#include <stdio.h>
#define DATA_CNT 11

int main()
{
	int data[DATA_CNT] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	int cnt, low, high, mid, sw, key;

	sw = 0;
	cnt = 0;
	low = 0;
	high = DATA_CNT - 1;

	printf("ã�� �ڷ� �Է� : ");
	scanf("%d", &key);

	while (low <= high)
	{
		cnt++;
		mid = (low + high) / 2;
		if (data[mid] > key)
		{
			high = mid - 1;
		}
		else if (data[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			sw = 1;
			break;
		}
	}

	printf(" �˻� Ƚ�� %d\n", cnt);
	if (sw == 1)
	{
		printf("ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("ã�� �� �����ϴ�.\n");
	}
	return 0;
}
