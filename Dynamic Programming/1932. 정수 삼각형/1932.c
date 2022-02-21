#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 250*501
#define MAX(x, y) (((x)>(y))?(x):(y))

int triangle[MAXIMUM + 1];

int main() {
	int n;	// 삼각형의 크기
	int index;
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		index = ((i - 1) * i) / 2;
		for (j = 1; j <= i; j++) {
			scanf("%d", &triangle[index + j]);
		}
	}

	// 삼각형의 밑에서 부터 최댓값을 구하며 올라온다.
	for (i = n - 1; i >= 1; i--) {
		index = ((i - 1) * i) / 2;
		for (j = 1; j <= i; j++) {
			triangle[index + j] += MAX(triangle[index + j + i], triangle[index + j + i + 1]);
		}
	}

	printf("%d", triangle[1]);

	return 0;
}