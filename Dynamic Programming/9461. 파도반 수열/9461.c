#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long memoization[101] = { 0, };

long long P(int N) {
	for (int i = 1; i <= N; i++) {
		if (memoization[N] != 0)
			return memoization[N];

		if (i >= 1 && i <= 3)
			memoization[i] = 1;
		else if (i >= 4 && i <= 5)
			memoization[i] = 2;
		else
			memoization[i] = memoization[i - 1] + memoization[i - 5];
	}

	return memoization[N];
}

int main() {
	int T;	// 테스트 케이스 개수
	int N;	// P(N);
	long length = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		length = P(N);
		printf("%lld\n", length);
	}

	return 0;
}