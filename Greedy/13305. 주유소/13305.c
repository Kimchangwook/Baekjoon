#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 100000

// 기름을 넣어야 하는 현재 도시부터
// 앞으로 가야할 도시들 중
// 기름 가격이 현재 도시보다 작을 때 까지는 
// 현재 도시에서 한번에 넣고 간다.
long long f(int n, int distance[], int oil_price[]) {
	int	L;	// 각 도시에서 구매해야 할 리터 수
	long long cost = 0;
	int skip_cites;

	for (int i = 0; i < n; i++) {
		L = 0;
		skip_cites = 0;

		for (int j = i + 1; j < n; j++) {	
			if (oil_price[i] < oil_price[j]) {
				L += distance[j - 1];
				skip_cites++;
			 }
			else {
				L += distance[j - 1];
				break;
			}
		}

		cost += (long long)L * oil_price[i];
		i += skip_cites;
	}

	return cost;
}

int main() {
	int N;	// num of cities
	int* distance = malloc(sizeof(int) * MAXIMUM);
	int* oil_price = malloc(sizeof(int) * MAXIMUM);
	long long result;

	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &distance[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &oil_price[i]);;
	}

	result = f(N, distance, oil_price);

	printf("%lld", result);

	free(distance);
	free(oil_price);

	return 0;
}