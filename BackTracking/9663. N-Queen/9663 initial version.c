#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 15

// 탐색
// 퀸 배치 -> 퀸 의 공격 경로 색칠 -> 다음 퀸 배치시 색칠되어있지 않은 col에 배치
// 만약 모든 col에 색칠 되어있을경우 이 이후는 탐색 의미 x
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
	int N; // 체스판의 크기 N * N
	int chess_board[MAX + 1][MAX + 1] = { 0, };	// 체스 판 배열
	int depth;	// 체스판에 놓은 퀸들의 개수
	int count;	// 구해야 하는 경우의 수


	scanf("%d", &N);
	depth = 0;

	// 탐색
	count = search(depth + 1, N, chess_board);

	printf("%d", count);

	return 0;
}