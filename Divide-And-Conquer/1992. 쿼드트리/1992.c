#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char quadtree[10000];	// ������ ���� Ʈ�� 
int index = 0;	// quadtree�� ���� �ֱ� ���� index�� ����� ���� ����

// ���� ���� ���� üũ
char check(char** video, int start_row, int start_col, int n) {
	char start_point = video[start_row][start_col];	// ���ҵ� ������ ù ��

	for (int i = start_row; i < start_row + n; i++) {
		for (int j = start_col; j < start_col + n; j++) {
			if (start_point != video[i][j])
				return '2';	// ���� �Ұ� -> '2'��ȯ
		}
	}
	return start_point;	// ���� ����
}

void convert_to_quadtree(char** video, int start_row, int start_col, int n) {
	// ���� �Ұ����� ũ��
	if (n <= 1) {
		quadtree[index++] = video[start_row][start_col];
		return;
	}

	char check_point = check(video, start_row, start_col, n);
	
	//	���� ���� 
	if (check_point == '0' || check_point == '1') {
		quadtree[index++] = check_point;
	}
	// ���� �Ұ��� -> ����
	else {	
		n /= 2;

		quadtree[index++] = '(';
		convert_to_quadtree(video, start_row, start_col, n);
		convert_to_quadtree(video, start_row, start_col + n, n);
		convert_to_quadtree(video, start_row + n, start_col, n);
		convert_to_quadtree(video, start_row + n, start_col + n, n);
		quadtree[index++] = ')';
	}
}

int main() {
	int n;	// ������ ũ��
	char** video;	// ���� �迭
	int i, j;

	//	������ ũ�� n �Է� & ���� �����Ҵ�
	scanf("%d", &n);
	video = malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
		video[i] = malloc(sizeof(char) * n);

	// ���� �迭 �ʱ�ȭ
	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < n; j++) {
			scanf("%c", &video[i][j]);
		}
	}

	// ������ ����Ʈ���� �����ϴ� �Լ�
	convert_to_quadtree(video, 0, 0, n);

	// ���� Ʈ�� ���
	for (i = 0; i < index; i++)
		printf("%c", quadtree[i]);

	return 0;
}