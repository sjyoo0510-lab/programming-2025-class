#include <stdio.h>
#include <math.h>

#define SIZE 10

int main()
{
	double data[SIZE];
	int rank[SIZE];
	int i, j;

	printf("임의의 실수 10개를 입력하세요:\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d번째 수: ", i + 1);
		scanf_s("%lf", &data[i]);

	}

	double sum = 0.0;
	for (i = 0; i < SIZE; i++) {
		sum += data[i];
	}
	double mean = sum / SIZE;

	double sum_sq_diff = 0.0;
	for (i = 0; i < SIZE; i++) {
		rank[i] = 1;
	}

	for (i = 0; i < SIZE; i++) {
		double diff = data[i] - mean;
		sum_sq_diff += diff * diff;

	}
	double variance = sum_sq_diff / SIZE;
	
	double std_dev = sqrt(variance);

	for (i = 0; i < SIZE; i++) {
		rank[i] = 1;
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (data[i] < data[j]) {
				rank[i]++;
			}
	    }
	}
	
	printf("\n========= 결과 =========\n");
	printf(" 순번  |   입력값   |  순위\n");
	printf("---------------------------\n");

	for (i = 0; i < SIZE; i++) {
		printf(" %-6d|  %-10.2f|  %d\n", i + 1, data[i], rank[i]);
	}

	printf("\n--- 통계 ---\n");
	printf("전체 데이터 평균: %.2f\n", mean);
	printf("전체 데이터 분산: %.2f\n", mean);
	printf("전체 데이터 표준편차: %.2f\n", std_dev);

	return 0;
}