#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int d[MAX + 1] = { 0, };

int lis_dp(int n, int list[]) {
	int max = 1;

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (list[i] > list[j] && d[i] <= d[j])
				d[i] = d[j] + 1;
		}
		if (max < d[i])
			max = d[i];
	}

	return max;
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