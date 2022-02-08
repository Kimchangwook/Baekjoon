#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

// DFS를 이용
// data보다 큰 원소들만 탐색
// depth == M 일경우 탐색 멈추고 결과 출력
// 이전 함수로 되돌아 간 후 다음 수 탐색
void DFS(int depth, int data, int result[], int N, int M) {
	int i;

	result[depth] = data;

	if (depth == M) {
		for (i = 1; i <= M; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	else {
		for (i = data + 1; i <= N; i++) {
			DFS(depth + 1, i, result, N, M);
		}
	}

}

int main() {
	int N, M; // N: 수의 크기, M: 선택해야하는 수의 개수 
	int depth = 0;	// 탐색의 깊이 -> 선택한 수의 개수
	int result[MAX + 1] = { 0, };	// 선택한 수를 저장
	int i;

	scanf("%d %d", &N, &M);

	// 탐색
	for (i = 1; i <= N; i++)
		DFS(depth + 1, i, result, N, M);

	return 0;
}