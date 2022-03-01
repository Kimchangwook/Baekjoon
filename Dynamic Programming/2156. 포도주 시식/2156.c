#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 10001
#define MAX(x, y) (((x)>(y))?(x):(y))

int memo[MAXIMUM] = { 0, };


// Á¡È­½Ä
// memo[n] = MAX(memo[n - 2], list[n - 1] + memo[n - 3], list[n - 1] + memo[n - 4])
// result = MAX(memo[n], memo[n - 1])
int dp(int N, int list[]) {
	if (N == 1) {
		memo[1] = list[1];
		return memo[1];
	}
	else if(N == 2){
		memo[1] = list[1];
		memo[2] = list[2] + list[1];
		return memo[2];
	}
	else {
		memo[1] = list[1];
		memo[2] = list[2] + list[1];
		memo[3] = list[3] + MAX(list[2], list[1]);
	}

	for (int i = 4; i <= N; i++) {
		memo[i] = list[i] + MAX(MAX(memo[i - 2], list[i - 1] + memo[i - 3]), list[i - 1] + memo[i - 4]);
	}

	return MAX(memo[N], memo[N - 1]);
}

int main(){
	int N;
	int wines[MAXIMUM];
	int result;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &wines[i]);

	result = dp(N, wines);

	printf("%d\n", result);

	return 0;
}