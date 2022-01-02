#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 500000

int arr[MAX];
int card[MAX];	// ����̰� ������ �ִ� ���� ī��
int find_num[MAX];	// �� �� �����ִ��� ���ؾ� �ϴ� ���� �迭

void merge(int* list, int s, int mid, int e) {
	int i, j, k;
	i = s; j = mid + 1; k = s;

	while (i <= mid && j <= e) {
		if (list[i] < list[j])
			arr[k++] = list[i++];
		else
			arr[k++] = list[j++];
	}

	if (i <= mid) {
		while (i <= mid)
			arr[k++] = list[i++];
	}
	else {
		while (j <= e)
			arr[k++] = list[j++];
	}

	for (int l = s; l <= e; l++)
		list[l] = arr[l];
}

// �պ� ���� �Լ�
void merge_sort(int* list, int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;

		merge_sort(list, s, mid);
		merge_sort(list, mid + 1, e);
		merge(list, s, mid, e);
	}
}

// upper_bound �� K������ ó������ ū ���� ������ ��ġ�� ����
int upper_bound(int* list, int n, int key) {
	int s = 0, e = n;
	int mid;

	while (s < e) {
		mid = (s + e) / 2;

		if (list[mid] <= key)
			s = mid + 1;
		else
			e = mid;
	}

	return e;
}

// lower_bound�� �����ͳ� Ư�� K������ ���ų� ū���� ó�� ������ ��ġ�� ����
int lower_bound(int* list, int n, int key) {
	int s = 0, e = n;
	int mid;

	while (s < e) {
		mid = (s + e) / 2;

		if (list[mid] < key)
			s = mid + 1;
		else
			e = mid;
	}

	return e;
}


int main() {
	int n;	// ���� ī�� ����
	int m;	// ã�ƾ� �ϴ� ���� ����
	int i;
	int ans;

	// n �Է� �� card �迭 �ʱ�ȭ 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &card[i]);

	// m �Է� �� find_num �迭 �ʱ�ȭ
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf( "%d", &find_num[i]);

	merge_sort(card, 0, n - 1);	 // ����

	// upper_bound - lower_bound -> �ߺ� key ���� // && ���
	for (i = 0; i < m; i++) {
		ans = upper_bound(card, n, find_num[i]) - lower_bound(card, n, find_num[i]);
		printf("%d ", ans);
	}
	

	return 0;
}