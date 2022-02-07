#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

// 깊이 우선 탐색을 이용
// 모든 수를 탐색
// pre == m 이면 prev 출력
// else 방문하지 않은 다음 수를 탐색
// 가장 최근에 추가한 prev와 visited의 원소 삭제 후 return;
void dfs(int v, int pre, int* prev, int* visited, int n, int m) {
	int i;
	pre++;
	prev[pre] = v;
	visited[v] = 1;


	if (pre == m) {
		for (i = 1; i <= m; i++) {
			printf("%d ", prev[i]);
		}
		printf("\n");
	}
	else {
		for (i = 1; i <= n; i++) {
			if (visited[i] == 0)
				dfs(i, pre, prev, visited, n, m);
		}
	}

	prev[pre] = 0;
	visited[v] = 0;
}

int main() {
	int n, m;	// n: 숫자 크기, m: 선택해야할 횟수
	int pre = 0;	// 현재 선택한 횟수
	int prev[MAX + 1] = { 0, };	// 선택한 수를 담는 배열
	int visited[MAX + 1] = { 0. };	// 특정 수를 방문했는지 표시하는 배열
	int i, j;

	scanf("%d %d", &n, &m);

	// 탐색
	for (i = 1; i <= n; i++)
		dfs(i, pre, prev, visited, n, m);


	return 0;
}