#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 1000

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

// 가장 적게 걸리는 사람부터 선택
int greedy(int n, int list[]) {
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += list[j];
		}
	}

	return sum;
}

int main() {
	int N;	// num of people
	int times[MAXIMUM];	// times array per person
	int result;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &times[i]);

	// 시간이 적게 걸리는 순으로 정렬
	qsort(times, N, sizeof(times[0]), compare);

	result = greedy(N, times);

	printf("%d", result);

	return 0;
}