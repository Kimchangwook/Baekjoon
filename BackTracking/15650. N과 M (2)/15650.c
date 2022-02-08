#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

// DFS�� �̿�
// data���� ū ���ҵ鸸 Ž��
// depth == M �ϰ�� Ž�� ���߰� ��� ���
// ���� �Լ��� �ǵ��� �� �� ���� �� Ž��
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
	int N, M; // N: ���� ũ��, M: �����ؾ��ϴ� ���� ���� 
	int depth = 0;	// Ž���� ���� -> ������ ���� ����
	int result[MAX + 1] = { 0, };	// ������ ���� ����
	int i;

	scanf("%d %d", &N, &M);

	// Ž��
	for (i = 1; i <= N; i++)
		DFS(depth + 1, i, result, N, M);

	return 0;
}