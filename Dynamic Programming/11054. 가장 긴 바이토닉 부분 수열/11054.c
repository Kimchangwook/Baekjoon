#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int d1[MAX + 1] = { 0, };
int d2[MAX + 1] = { 0, };

int lis_dp(int n, int list[]) {
	int max = 1;

	// 오름차순
	for (int i = 1; i <= n; i++) {
		d1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (list[i] > list[j] && d1[i] <= d1[j])
				d1[i] = d1[j] + 1;
		}
	}

	// 내림차순
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = n; j > i; j--) {
			if (list[i] > list[j] && d2[i] <= d2[j])
				d2[i] = d2[j] + 1;
		}
	}

	max = d1[1] + d2[1];
	for (int i = 2; i <= n; i++)
		if (max < d1[i] + d2[i])
			max = d1[i] + d2[i];

	return max - 1;
}

int main() {
	int N;
	int A[MAX + 1];
	int result;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	result = lis_dp(N, A);

	printf("%d", result);

	return 0;
}