#include <stdio.h>
#define DATA_CNT 11

int BinarySearch1(int data[], int low, int high, int key);
int BinarySearch2(int data[], int low, int high, int key);

int main()
{
	int data[DATA_CNT] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	int low, high, mid, key, n;

	low = 0;
	high = DATA_CNT - 1;

	printf("찾을 자료 입력 : ");
	scanf("%d", &key);

	n = BinarySearch1(data, low, high, key);
	if (n != -1)
	{
		printf("%d -> data의 %d번째 찾았습니다.\n", key, n);
	}
	else
	{
		printf("%d -> data에 없습니다.\n", key);
	}

	n = BinarySearch2(data, low, high, key);
	if (n != -1)
	{
		printf("%d -> data의 %d번째 찾았습니다.\n", key, n);
	}
	else
	{
		printf("%d -> data에 없습니다.\n", key);
	}

	return 0;
}

int BinarySearch1(int data[], int low, int high, int key)
{
    int mid;
    while (low <= high)
	{
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
			return mid;
		}
	}
	return -1;
}

int BinarySearch2(int data[], int low, int high, int key)
{
    int mid;
    if(low > high)
        return -1;
   mid = (low + high) / 2;
    if (data[mid] > key)
        return BinarySearch2(data, low, mid-1, key);
    else if (data[mid] < key)
        return BinarySearch2(data, mid+1, high, key);
    else
        return mid;
}
