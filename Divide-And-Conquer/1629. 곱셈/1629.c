#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 제곱을 계산하기 위한 함수
int squared(int a, int b, int c) {
	if (b <= 1)
		return a % c;

	long long result;	// 계산 과정에서 오버플로우 발생할 수 있으므로 long long으로 선언

	// 지수가 짝수인 경우
	if (b % 2 == 0) {
		b /= 2;
		result = squared(a, b, c);
		return (result * result) % c;
	}
	// 지수가 홀수인 경우 
	else {
		b /= 2;
		result = squared(a, b, c);
		return (((result * result) % c) * (a % c)) % c;
	}
}

int main() {
	int a, b, c;	// a를 b번 곱한 수에 c로 나눈 나머지를 구한다.
	int result;

	scanf("%d %d %d", &a, &b, &c);
	result = squared(a, b, c);	// 계산 후 결과

	printf("%d", result);

	return 0;
}