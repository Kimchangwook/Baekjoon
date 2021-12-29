#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int arr[MAX];
int A[MAX];	// A: 기존에 존재하는 배열, 
int M[MAX];	// M: 존재하는지 찾아야하는 배열

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

// 정렬 함수
void merge_sort(int* list, int left, int right) {
	if (left < right) {
		int m = (right + left) / 2;
		merge_sort(list, left, m);
		merge_sort(list, m + 1, right);
		merge(list, left, m, right);
	}
}



// num이 list배열에 존재하는지 찾는 함수
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
	int n, m;	// n: 기존에 존재하는 배열의 크기, m: 존재하는지 찾아야 하는 배열의 크기
	int i;

	// n입력 & 배열 A 초기화
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	// m입력 & 배열 M 초기화
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &M[i]);

	merge_sort(A, 0, n - 1);	// 이분 탐색을 위해 A 정렬

	// M 배열의 원소에 하나씩 접근하여 A배열에 존재하는지 찾고 출력
	for (i = 0; i < m; i++)
		printf("%d\n", search(A, 0, n - 1, M[i]));

	return 0;
}