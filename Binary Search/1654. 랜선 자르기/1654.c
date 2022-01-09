#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int k, n;	// k: 보유 중인 랜선의 개수, n: 필요한 랜선의 개수
int max_length;	// 만들 수 있는 랜선 최대 길이
int LAN_cable[10000];	// 보유 중인 랜선의 길이 배열

// qsort를 위한 compare method
int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

// Parametric search를 위한 결정 함수
int decision(int length) {
	int count = 0;

	for (int i = 0; i < k; i++)
		count += LAN_cable[i] / length;

	if (count >= n)
		return 1;
	else
		return 0;
}

// Parametric method (upper bound)
int search(int n) {
	int start = 1;
	int end = n + 1;
	int mid;

	while (start < end) {
		mid = ((long long)start + (long long)end) / 2;

		if (decision(mid) == 1)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main() {
	int i;

	// 변수 입력
	scanf("%d %d", &k, &n);
	for (i = 0; i < k; i++)
		scanf("%d", &LAN_cable[i]);

	// 가장 긴 랜선 길이를 알기 위해 정렬
	qsort(LAN_cable, k, sizeof(int), compare);

	// 탐색
	max_length = search(LAN_cable[k - 1]) - 1;

	printf("%d\n", max_length);

	

	return 0;
}