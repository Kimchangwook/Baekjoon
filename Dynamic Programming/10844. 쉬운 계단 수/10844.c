#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 101
#define DIVISOR 1000000000

int memo[MAXIMUM][MAXIMUM] = { 0, };

// Á¡È­½Ä
// i == 0, memo[n][i] = memo[n - 1][i + 1]
// i == 9, memo[n][i] = memo[n - 1][i - 1]
// else, memo[n][i] = memo[n - 1][i - 1] + memo[n - 1][i + 1]
int dp(int N) {
	long long tmp;
	long long result = 0;

	for (int i = 0; i < 10; i++)
		memo[N][i] = 1;

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				tmp = memo[i + 1][j + 1];
			else if (j == 9)
				tmp = memo[i + 1][j - 1];
			else
				tmp = (long long)memo[i + 1][j + 1] + memo[i + 1][j - 1];

			memo[i][j] = tmp % DIVISOR;
		}
	}

	for (int i = 1; i <= 9; i++)
		result += memo[1][i];

	return result % DIVISOR;
}

int main() {
	int N;
	int result;

	scanf("%d", &N);

	result = dp(N);

	printf("%d", result);

	return 0;
}