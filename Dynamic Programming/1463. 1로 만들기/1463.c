#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001
#define MIN(x, y) (((x)<(y))?(x):(y))

int memo[MAX] = { 0, };

// 3가지의 점화식을 갖는다
// memo[n] = memo[n / 3] + 1
// memo[n] = memo[n / 2] + 1
// memo[n] = memo[n - 1] + 1
// 이 중 최솟값을 갖게 된다.
int dp(int N) {
	memo[1] = 0;

	for (int i = 2; i <= N; i++) {
		if (i % 6 == 0)
			memo[i] = MIN(MIN(memo[i / 2], memo[i / 3]), memo[i - 1]) + 1;
		else if (i % 2 == 0)
			memo[i] = MIN(memo[i / 2], memo[i - 1]) + 1;
		else if (i % 3 == 0)
			memo[i] = MIN(memo[i / 3], memo[i - 1]) + 1;
		else
			memo[i] = memo[i - 1] + 1;
	}

	return memo[N];
}

int main() {
	int N;
	int result;

	scanf("%d", &N);

	result = dp(N);

	printf("%d\n", result);

	return 0;
}