#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int check(char* board[], int start_row, int start_col) {
	int count1 = 0;
	int count2 = 0;
	
	// 체스판의 첫 부분이 화이트로 시작하는 경우
	for (int i = start_row; i < start_row + 8; i++) {
		for (int j = start_col; j < start_col + 8; j++) {
			if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 0 && board[i][j] != 'W')
				count1++;
			else if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 1 && board[i][j] != 'B')
				count1++;
			else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 0 && board[i][j] != 'B')
				count1++;
			else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 1 && board[i][j] != 'W')
				count1++;
		}
	}

	// 체스판의 첫 부분이 블랙으로 시작하는 경우
	for (int i = start_row; i < start_row + 8; i++) {
		for (int j = start_col; j < start_col + 8; j++) {
			if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 0 && board[i][j] != 'B')
				count2++;
			else if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 1 && board[i][j] != 'W')
				count2++;
			else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 0 && board[i][j] != 'W')
				count2++;
			else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 1 && board[i][j] != 'B')
				count2++;
		}
	}

	if (count1 <= count2)
		return count1;
	else
		return count2;

}
int main() {
	int n, m;	// n: 보드의 세로크기, m: 가로크기
	char** board;	// 보드 배열
	int count = -1;	// 다시 칠해야 하는 사각형의 개수
	int new_count;	// 기존의 개수와 비교하기 위한 변수
	int i, j, k;

	// 보드의 크기 입력 & 보드 배열 동적 할당
	scanf("%d %d", &n, &m);
	board = malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		board[i] = malloc(sizeof(char) * m);
	}
	
	// 보드 배열 입력
	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < m; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	// 다시 칠해야 하는 최소 갯수 count 구하는 코드
	for (i = 0; i <= n - 8; i++) {
		for (j = 0; j <= m - 8; j++) {
			new_count = check(board, i, j);
			if (count == -1) {
				count = new_count;
				continue;
			}

			if (count > new_count)
				count = new_count;
		}
	}

	printf("%d", count);

	// 동적 할당 해제
	for (i = 0; i < n; i++)
		free(board[i]);
	free(board);

	return 0;
}