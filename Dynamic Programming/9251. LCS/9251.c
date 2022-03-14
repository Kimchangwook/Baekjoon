#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 1001
#define MAX(x,y) (((x)>(y))?(x):(y))

int d[MAXIMUM][MAXIMUM] = { 0, };

int dp(char A[], char B[]) {
	for (int i = 0; i < strlen(A); i++) {
		for (int j = 0; j < strlen(B); j++) {
			if (A[i] == B[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = MAX(d[i][j + 1], d[i + 1][j]);
		}
	}

	return d[strlen(A)][strlen(B)];
}

int main() {
	char string_A[MAXIMUM];
	char string_B[MAXIMUM];
	int result;

	scanf("%s", string_A);
	scanf("%s", string_B);

	result = dp(string_A, string_B);

	printf("%d", result);

	return 0;
}