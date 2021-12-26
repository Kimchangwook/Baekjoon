#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int white = 0;	// num of white paper
int blue = 0;	// num of blue paper

int check(int** paper, int start_row, int start_col, int n) {
	int i, j;
	int start_num = paper[start_row][start_col];

	for (i = start_row; i < start_row + n; i++) {
		for (j = start_col; j < start_col + n; j++) {
			if (start_num != paper[i][j])
				return -1;
		}
	}
	return start_num;
}

void cut_paper(int** paper, int start_row, int start_col, int n) {
	if (n <= 1 && paper[start_row][start_col] == 0) {
		white++;
		return;
	}
	else if (n <= 1 && paper[start_row][start_col] == 1) {
		blue++;
		return;
	}

	int check_point = check(paper, start_row, start_col, n);

	if (check_point == 0) {
		white++;
		return;
	}
	else if (check_point == 1) {
		blue++;
		return;
	}
	else {
		n /= 2;
		cut_paper(paper, start_row, start_col, n);
		cut_paper(paper, start_row, start_col + n, n);
		cut_paper(paper, start_row + n, start_col, n);
		cut_paper(paper, start_row + n, start_col + n, n);
	}

}

int main() {
	int n;	// 전체 종이의 한 변의 길이
	int** paper;	// 전체 종이 배열
	int i, j;

	// n 입력 & paper 동적 할당
	scanf("%d", &n);
	paper = malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		paper[i] = malloc(sizeof(int) * n);

	// paper 배열 초기화
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	cut_paper(paper, 0, 0, n);
	
	printf("%d\n", white);
	printf("%d\n", blue);


	// paper 동적 할당 해제
	for (i = 0; i < n; i++)
		free(paper[i]);
	free(paper);

	return 0;
}