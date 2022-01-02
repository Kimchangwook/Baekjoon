#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 500000

int arr[MAX];
int card[MAX];	// 상근이가 가지고 있는 숫자 카드
int find_num[MAX];	// 몇 개 갖고있는지 구해야 하는 숫자 배열

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

// 합병 정렬 함수
void merge_sort(int* list, int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;

		merge_sort(list, s, mid);
		merge_sort(list, mid + 1, e);
		merge(list, s, mid, e);
	}
}

// upper_bound 는 K값보다 처음으로 큰 값이 나오는 위치를 리턴
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

// lower_bound는 데이터내 특정 K값보다 같거나 큰값이 처음 나오는 위치를 리턴
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
	int n;	// 보유 카드 개수
	int m;	// 찾아야 하는 숫자 개수
	int i;
	int ans;

	// n 입력 및 card 배열 초기화 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &card[i]);

	// m 입력 및 find_num 배열 초기화
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf( "%d", &find_num[i]);

	merge_sort(card, 0, n - 1);	 // 정렬

	// upper_bound - lower_bound -> 중복 key 개수 // && 출력
	for (i = 0; i < m; i++) {
		ans = upper_bound(card, n, find_num[i]) - lower_bound(card, n, find_num[i]);
		printf("%d ", ans);
	}
	

	return 0;
}