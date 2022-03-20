#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int greedy(int coin[], int n, int k) {
	int count = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (k == 0)
			return count;

		if (coin[i] <= k) {
			count += k / coin[i];
			k %= coin[i];
		}
	}

	return count;
}

int main() {
	int n, k;	// n->������ ����, k->��ġ�� ��
	int* coin;	// ���� �迭
	int result;

	scanf("%d %d", &n, &k);
	coin = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", coin + i);

	result = greedy(coin, n, k);

	printf("%d", result);

	free(coin);

	return 0;
}