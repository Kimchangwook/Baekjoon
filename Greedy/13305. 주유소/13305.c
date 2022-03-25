#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 100000

// �⸧�� �־�� �ϴ� ���� ���ú���
// ������ ������ ���õ� ��
// �⸧ ������ ���� ���ú��� ���� �� ������ 
// ���� ���ÿ��� �ѹ��� �ְ� ����.
long long f(int n, int distance[], int oil_price[]) {
	int	L;	// �� ���ÿ��� �����ؾ� �� ���� ��
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