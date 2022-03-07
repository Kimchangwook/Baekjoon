#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	int pos_A;
	int pos_B;
}Pos;

int d1[MAX] = { 0, };
int d2[MAX] = { 0, };

int compare(const void* a, const void* b) {
	Pos num1 = *(Pos*)a;
	Pos num2 = *(Pos*)b;

	return num1.pos_A - num2.pos_A;
}

// LIS -> 나머지는 없애버림
int dp(int n, Pos p[]) {
	int max1 = 1;
	int max2 = 1;

	// 오름차순 경우
	for (int i = 0; i < n; i++) {
		d1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (p[i].pos_B > p[j].pos_B && d1[i] <= d1[j])
				d1[i] = d1[j] + 1;
		}
		if (max1 < d1[i])
			max1 = d1[i];
	}

	// 내림차순 경우
	for (int i = 0; i < n; i++) {
		d2[i] = 1;
		for (int j = 0; j < i; j++) {
			if (p[i].pos_B > p[j].pos_B && d2[i] <= d2[j])
				d2[i] = d2[j] + 1;
		}
		if (max2 < d2[i])
			max2 = d2[i];
	}

	// 더 큰 경우를 고름
	if (max1 > max2)
		return n - max1;
	else
		return n - max2;
}

int main() {
	int n;
	Pos electric_wires[MAX] = { 0, };
	int result;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &electric_wires[i].pos_A, &electric_wires[i].pos_B);

	// 한 쪽 전선을 정렬
	qsort(electric_wires, n, sizeof(Pos), compare);

	result = dp(n, electric_wires);

	printf("%d", result);

	return 0;
}