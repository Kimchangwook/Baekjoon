#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int k, n;	// k: ���� ���� ������ ����, n: �ʿ��� ������ ����
int max_length;	// ���� �� �ִ� ���� �ִ� ����
int LAN_cable[10000];	// ���� ���� ������ ���� �迭

// qsort�� ���� compare method
int compare(void* first, void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

// Parametric search�� ���� ���� �Լ�
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

	// ���� �Է�
	scanf("%d %d", &k, &n);
	for (i = 0; i < k; i++)
		scanf("%d", &LAN_cable[i]);

	// ���� �� ���� ���̸� �˱� ���� ����
	qsort(LAN_cable, k, sizeof(int), compare);

	// Ž��
	max_length = search(LAN_cable[k - 1]) - 1;

	printf("%d\n", max_length);

	

	return 0;
}