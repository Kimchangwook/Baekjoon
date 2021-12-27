#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char quadtree[10000];	// 영상의 쿼드 트리 
int index = 0;	// quadtree에 값을 넣기 위해 index를 계산을 위한 변수

// 압축 가능 여부 체크
char check(char** video, int start_row, int start_col, int n) {
	char start_point = video[start_row][start_col];	// 분할된 영상의 첫 점

	for (int i = start_row; i < start_row + n; i++) {
		for (int j = start_col; j < start_col + n; j++) {
			if (start_point != video[i][j])
				return '2';	// 압축 불가 -> '2'반환
		}
	}
	return start_point;	// 압축 가능
}

void convert_to_quadtree(char** video, int start_row, int start_col, int n) {
	// 분할 불가능한 크기
	if (n <= 1) {
		quadtree[index++] = video[start_row][start_col];
		return;
	}

	char check_point = check(video, start_row, start_col, n);
	
	//	압축 가능 
	if (check_point == '0' || check_point == '1') {
		quadtree[index++] = check_point;
	}
	// 압축 불가능 -> 분할
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
	int n;	// 영상의 크기
	char** video;	// 영상 배열
	int i, j;

	//	영상의 크기 n 입력 & 영상 동적할당
	scanf("%d", &n);
	video = malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
		video[i] = malloc(sizeof(char) * n);

	// 영상 배열 초기화
	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < n; j++) {
			scanf("%c", &video[i][j]);
		}
	}

	// 영상을 쿼드트리로 압축하는 함수
	convert_to_quadtree(video, 0, 0, n);

	// 쿼드 트리 출력
	for (i = 0; i < index; i++)
		printf("%c", quadtree[i]);

	return 0;
}