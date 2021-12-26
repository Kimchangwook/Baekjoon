#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int check(char* board[], int start_row, int start_col) {
	int count1 = 0;
	int count2 = 0;
	
	// ü������ ù �κ��� ȭ��Ʈ�� �����ϴ� ���
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

	// ü������ ù �κ��� ������ �����ϴ� ���
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
	int n, m;	// n: ������ ����ũ��, m: ����ũ��
	char** board;	// ���� �迭
	int count = -1;	// �ٽ� ĥ�ؾ� �ϴ� �簢���� ����
	int new_count;	// ������ ������ ���ϱ� ���� ����
	int i, j, k;

	// ������ ũ�� �Է� & ���� �迭 ���� �Ҵ�
	scanf("%d %d", &n, &m);
	board = malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		board[i] = malloc(sizeof(char) * m);
	}
	
	// ���� �迭 �Է�
	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < m; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	// �ٽ� ĥ�ؾ� �ϴ� �ּ� ���� count ���ϴ� �ڵ�
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

	// ���� �Ҵ� ����
	for (i = 0; i < n; i++)
		free(board[i]);
	free(board);

	return 0;
}