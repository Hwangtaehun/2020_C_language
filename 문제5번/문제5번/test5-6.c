#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char name[100][10];
	int no[100], kor[100], eng[100], mat[100], tot[100];
	int i, j, cnt = 0, rank, tkor = 0, teng = 0, tmat = 0;
	float av;
	printf("번호 이름 국어 영어 수학 점수를 입력(종료 ^Z)\n");
	while (scanf("%d%s%d%d%d", &no[cnt], &name[cnt], &kor[cnt], &eng[cnt], &mat[cnt]) != EOF)
	{
		tot[cnt] = kor[cnt] + eng[cnt] + mat[cnt];
		cnt++;
	}
	printf("\n---------------------------------------\n");
	printf("번호 이름 국어 영어 수학 총점 평균 석차\n");
	printf("---------------------------------------\n");
	for (i = 0; i < cnt; i++)
	{
		av = (float)tot[i] / 3.0f;
		rank = 1;
		for (j = 0; j < cnt; j++)
		{
			if (tot[i] < tot[j])
				rank++;
		}
		printf("%3d%-8s%5d%7d%7d%5d%7.2f%4d\n", no[i], name[i], kor[i], eng[i], mat[i], tot[i], av, rank);
		tkor += kor[i];
		teng += eng[i];
		tmat += mat[i];
	}
	printf("---------------------------------------\n");
	printf("반평균   %7.2f %7.2f %7.2f\n", (float)tkor/(float)cnt, (float)teng/(float)cnt, (float)tmat/(float)cnt );
	printf("---------------------------------------\n");

	return 0;
}