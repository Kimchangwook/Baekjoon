#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DIVISOR 15746

int memoizaition[1000001] = { 0, };

// memoization[n] = memoization[n - 1] + memoization[n - 2]
// N의 범위가 매우 크기 때문에 반복문을 이용.
int tile(int N) {
	for (int i = 1; i <= N; i++) {
		if (i == 1)
			memoizaition[i] = 1;
		else if (i == 2)
			memoizaition[i] = 2;
		else
			memoizaition[i] = (memoizaition[i - 1] + memoizaition[i - 2]) % DIVISOR;
	}

	return memoizaition[N];
}

int main() {
	int N;
	int cases = 0;

	scanf("%d", &N);

	cases = tile(N);

	printf("%d", cases);

	return 0;
}