#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;	// n: ������ ��, m: �ʿ��� ���� ����
int tree[1000000];	// �������� ���� �迭
int max_height;	// ���ܱ⿡ ������ �� �ִ� �ִ� ����

// �������� ����
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;
	else if (num1 < num2)
		return 1;
	else
		return 0;
}

// Ž�� ���� �� ���� �Լ�
int decision(int height) {
	long long count = 0;

	for (int i = 0; i < n; i++) {
		if (tree[i] > height)
			count += tree[i] - height;
	}

	if (count >= m)
		return 1;
	else
		return 0;
}

// ���ܱ⸦ ���� �� �� �ִ� ���̸� ���ϴ� Ž��(upper bound)
int search(int n, int key) {
	int start = 0;
	int end = n + 1;
	int mid;

	while (start < end) {
		mid = ((long long)start + (long long)end) / 2;

		if (decision(mid) == key)
			start = mid + 1;
		else
			end = mid;
	}

	return end;
}

int main() {
	int i;
	int longest_tree;

	// ���� �� �迭 �ʱ�ȭ
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &tree[i]);

	// ���� �� ���� ���� ���ϱ�
	//qsort(tree, n, sizeof(int), compare);
	longest_tree = -1;
	for (i = 0; i < n; i++)
		if (longest_tree < tree[i])
			longest_tree = tree[i];

	// ���ܱ��� ���̸� Ž������ ���� ���Ѵ�
	max_height = search(longest_tree, 1) - 1;

	// ���
	printf("%d\n", max_height);


	return 0;
}