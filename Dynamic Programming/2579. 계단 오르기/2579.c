#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 301
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)<(y))?(x):(y))

int memo[MAXIMUM] = { 0, };

int dp(int N, int* list) {
	memo[1] = list[1];
	memo[2] = list[2] + list[1];

	for (int i = 3; i <= N; i++) 
		memo[i] = list[i] + MAX(memo[i - 2], list[i - 1] + memo[i - 3]);

	return memo[N];
}

int main() {
	int N;
	int stairs[MAXIMUM];
	int result;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stairs[i]);
	}

	result = dp(N, stairs);

	printf("%d\n", result);

	return 0;
}
