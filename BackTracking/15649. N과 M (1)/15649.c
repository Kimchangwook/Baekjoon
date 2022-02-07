#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

// ���� �켱 Ž���� �̿�
// ��� ���� Ž��
// pre == m �̸� prev ���
// else �湮���� ���� ���� ���� Ž��
// ���� �ֱٿ� �߰��� prev�� visited�� ���� ���� �� return;
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
	int n, m;	// n: ���� ũ��, m: �����ؾ��� Ƚ��
	int pre = 0;	// ���� ������ Ƚ��
	int prev[MAX + 1] = { 0, };	// ������ ���� ��� �迭
	int visited[MAX + 1] = { 0. };	// Ư�� ���� �湮�ߴ��� ǥ���ϴ� �迭
	int i, j;

	scanf("%d %d", &n, &m);

	// Ž��
	for (i = 1; i <= n; i++)
		dfs(i, pre, prev, visited, n, m);


	return 0;
}