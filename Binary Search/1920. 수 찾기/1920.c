#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int arr[MAX];
int A[MAX];	// A: ������ �����ϴ� �迭, 
int M[MAX];	// M: �����ϴ��� ã�ƾ��ϴ� �迭

void merge(int* list, int left, int m, int right) {
	int i, j, k;
	i = left; j = m + 1; k = left;

	while (i <= m && j <= right) {
		if (list[i] < list[j])
			arr[k++] = list[i++];
		else
			arr[k++] = list[j++];
	}

	if (i <= m) {
		for (i; i <= m; i++)
			arr[k++] = list[i];
	}
	else {
		for (j; j <= right; j++)
			arr[k++] = list[j];
	}

	for (int l = left; l <= right; l++)
		list[l] = arr[l];
}

// ���� �Լ�
void merge_sort(int* list, int left, int right) {
	if (left < right) {
		int m = (right + left) / 2;
		merge_sort(list, left, m);
		merge_sort(list, m + 1, right);
		merge(list, left, m, right);
	}
}



// num�� list�迭�� �����ϴ��� ã�� �Լ�
int search(int* list, int left, int right, int num) {
	if(left <= right) {
		if (list[left] > num && list[right] < num)
			return 0;

		int m = (right + left) / 2;

		if (list[m] == num)
			return 1;
		else if (list[left] == num)
			return 1;
		else if (list[right] == num)
			return 1;
		else if (list[m] > num)
			return search(list, left, m - 1, num);
		else if(list[m] < num)
			return search(list, m + 1, right, num);
	}
	return 0;
}

int main() {
	int n, m;	// n: ������ �����ϴ� �迭�� ũ��, m: �����ϴ��� ã�ƾ� �ϴ� �迭�� ũ��
	int i;

	// n�Է� & �迭 A �ʱ�ȭ
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	// m�Է� & �迭 M �ʱ�ȭ
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &M[i]);

	merge_sort(A, 0, n - 1);	// �̺� Ž���� ���� A ����

	// M �迭�� ���ҿ� �ϳ��� �����Ͽ� A�迭�� �����ϴ��� ã�� ���
	for (i = 0; i < m; i++)
		printf("%d\n", search(A, 0, n - 1, M[i]));

	return 0;
}