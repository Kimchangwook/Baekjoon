#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// qsort를 위한 compare 함수
int compare(const void* a, const void* b) {
	int first = *(int*)a;
	int second = *(int*)b;

	if (first > second) 
		return 1;
	else if (first < second) 
		return -1;
	else 
		return 0;
}

// 매개 변수 탐색을 위한 결정 함수
// 기준점 공유기로 부터 주어진 간격보다 크거나 같으면
// 공유기를 설치하고 기준점 이동, count++
int decision(int* list, int list_size, int distance, int c) {
	int count = 1;
	int i;
	int start = list[0];	// 다음 공유기 설치를 위한 기준점

	for (i = 0; i < list_size; i++) {
		if (list[i] - start >= distance) {
			count++;
			start = list[i];
		}
	}

	if (count >= c)
		return 1;
	else
		return 0;
}

// 탐색 ( upper bound )
// t -> f로 바뀌는 상한선을 탐색
int search(int n, int* list, int c, int list_size) {
	int start = 1;
	int end = n + 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (decision(list, list_size, mid, c) == 1)
			start = mid + 1;
		else
			end = mid;
	}

	return end;
}

int main() {
	int n, c;	// n: 집의 개수, c: 공유기 개수
	int* location_of_house;	// 집들의 위치 배열
	int max_distance;	// 가장 인접한 두 공유기 사이 최대 거리
	int i;

	// 변수 초기화 
	scanf("%d %d", &n, &c);
	location_of_house = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &location_of_house[i]);

	// 탐색을 위한 정렬
	qsort(location_of_house, n, sizeof(int), compare);

	// 탐색을 통해 최대 간격 구하기
	max_distance = search(location_of_house[n - 1] - location_of_house[0], location_of_house, c, n) - 1;

	printf("%d\n", max_distance);

	free(location_of_house);

	return 0;
}