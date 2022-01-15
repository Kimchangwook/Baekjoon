#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;	// n: 나무의 수, m: 필요한 나무 길이
int tree[1000000];	// 나무들의 길이 배열
int max_height;	// 절단기에 설정할 수 있는 최대 높이

// 내림차순 정렬
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

// 탐색 과정 속 결정 함수
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

// 절단기를 설정 할 수 있는 높이를 구하는 탐색(upper bound)
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

	// 변수 및 배열 초기화
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &tree[i]);

	// 가장 긴 나무 길이 구하기
	//qsort(tree, n, sizeof(int), compare);
	longest_tree = -1;
	for (i = 0; i < n; i++)
		if (longest_tree < tree[i])
			longest_tree = tree[i];

	// 절단기의 높이를 탐색으로 부터 구한다
	max_height = search(longest_tree, 1) - 1;

	// 출력
	printf("%d\n", max_height);


	return 0;
}