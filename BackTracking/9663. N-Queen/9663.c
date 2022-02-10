#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 15

// üũ
// �� ���� depth�� row, �밢�� üũ
// *�밢�� üũ�� �ٽ�*
// (x, y), (i, j) �� ��ǥ�� �밢���� �����Ѵٸ� 
// |x - i| == |y - j| ���� �̿�
int check(int depth, int location_of_queen[]) {
	for (int i = 1; i < depth; i++) {
		if (location_of_queen[depth] == location_of_queen[i] || abs(location_of_queen[depth] - location_of_queen[i]) == depth - i)
			return 0;
	}
	return 1;
}

// Ž��
// queen ��ġ -> ���ռ� üũ -> �����ϸ� ���� �Լ� ȣ��/ �ƴϸ� ���� col üũ
int search(int depth, int N, int location_of_queen[]) {
	if (depth > N) return 1;

	int count = 0;

	for (int i = 1; i <= N; i++) {
		location_of_queen[depth] = i;

		if (check(depth, location_of_queen)) {
			count += search(depth + 1, N, location_of_queen);
		}
	}

	return count;
}

int main() {
	int N;
	int location_of_queen[MAX + 1];	// queen���� col��ġ
	int depth = 0;	// queen�� ���� ����?
	int count = 0;	// ���ؾ��ϴ� ����� ��

	scanf("%d", &N);

	//Ž��
	count = search(depth + 1, N, location_of_queen);

	printf("%d", count);

	return 0;
}