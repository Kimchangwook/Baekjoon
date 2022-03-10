#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 100000
#define MAX(x, y) (((x)>(y))?(x):(y))

int d[MAXIMUM] = { 0, };

// Á¡È­½Ä
// d[i] = MAX(d[i - 1] + list[i], list[i]);
int dp(int n, int list[]) {
	int max;

	d[0] = list[0];
	max = d[0];

	for (int i = 1; i < n; i++) {
		d[i] = MAX(d[i - 1] + list[i], list[i]);

		if (max < d[i])
			max = d[i];
	}

	return max;
}

int main() {
	int n;
	int* list = malloc(sizeof(int) * MAXIMUM);
	int result;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	result = dp(n, list);

	printf("%d", result);

	free(list);

	return 0;
}