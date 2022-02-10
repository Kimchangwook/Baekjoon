#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 15

// Ž��
// �� ��ġ -> �� �� ���� ��� ��ĥ -> ���� �� ��ġ�� ��ĥ�Ǿ����� ���� col�� ��ġ
// ���� ��� col�� ��ĥ �Ǿ�������� �� ���Ĵ� Ž�� �ǹ� x
// return;
int search(int depth, int N, int chess_board[][MAX + 1]) {
	if (depth > N)
		return 1;

	int count = 0;
	int boolean;
	int i, j, k;

	for (i = 1; i <= N; i++) {
		boolean = 1;
		for (j = depth, k = i; j >= 1 && k >= 1; j--, k--) {
			if (chess_board[j][k] == 1) {
				boolean = 0;
				break;
			}
		}

		if (boolean == 1) {
			for (j = depth; j >= 1; j--) {
				if (chess_board[j][i] == 1) {
					boolean = 0;
					break;
				}
			}
		}
		else continue;

		if (boolean == 1) {
			for (j = depth, k = i; j >= 1 && k <= N; j--, k++) {
				if (chess_board[j][k] == 1) {
					boolean = 0;
					break;
				}
			}
		}
		else continue;

		if (boolean == 0) continue;

		chess_board[depth][i] = 1;

		count += search(depth + 1, N, chess_board);

		chess_board[depth][i] = 0;

	}

	return count;
}

int main() {
	int N; // ü������ ũ�� N * N
	int chess_board[MAX + 1][MAX + 1] = { 0, };	// ü�� �� �迭
	int depth;	// ü���ǿ� ���� ������ ����
	int count;	// ���ؾ� �ϴ� ����� ��


	scanf("%d", &N);
	depth = 0;

	// Ž��
	count = search(depth + 1, N, chess_board);

	printf("%d", count);

	return 0;
}