#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int n, m;	// n: ī���� ����, m: �ѵ�
	int* card_number;	// ī�忡 ���� ��
	int sum = -1;
	int new_sum = -1;
	int i, j, k;

	scanf("%d %d", &n, &m);
	card_number = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &card_number[i]);
	}

	// ��� ������ ī�� �� ��
	for (i = 0; i < n-2; i++) {
		for (j = i + 1; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				new_sum = card_number[i] + card_number[j] + card_number[k];
				if (new_sum > m)
					continue;
				else if (sum == -1)
					sum = new_sum;
				else if (sum < new_sum)
					sum = new_sum;
			}
		}
	}

	printf("%d\n", sum);

	return 0;
}