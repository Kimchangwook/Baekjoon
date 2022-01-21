#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// qsort�� ���� compare �Լ�
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

// �Ű� ���� Ž���� ���� ���� �Լ�
// ������ ������� ���� �־��� ���ݺ��� ũ�ų� ������
// �����⸦ ��ġ�ϰ� ������ �̵�, count++
int decision(int* list, int list_size, int distance, int c) {
	int count = 1;
	int i;
	int start = list[0];	// ���� ������ ��ġ�� ���� ������

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

// Ž�� ( upper bound )
// t -> f�� �ٲ�� ���Ѽ��� Ž��
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
	int n, c;	// n: ���� ����, c: ������ ����
	int* location_of_house;	// ������ ��ġ �迭
	int max_distance;	// ���� ������ �� ������ ���� �ִ� �Ÿ�
	int i;

	// ���� �ʱ�ȭ 
	scanf("%d %d", &n, &c);
	location_of_house = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &location_of_house[i]);

	// Ž���� ���� ����
	qsort(location_of_house, n, sizeof(int), compare);

	// Ž���� ���� �ִ� ���� ���ϱ�
	max_distance = search(location_of_house[n - 1] - location_of_house[0], location_of_house, c, n) - 1;

	printf("%d\n", max_distance);

	free(location_of_house);

	return 0;
}