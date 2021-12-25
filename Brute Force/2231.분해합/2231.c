#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main() {
	int n;	
	int ctor = 0;	// ������
	int digit = 0;	// n�� �ڸ���
	int clone = 0;;	
	scanf("%d", &n);

	// n�� digit ���ϱ�
	while (n / pow(10, digit) >= 10)
		digit++;
	digit++;

	// ctor ���ϱ�
	for (int i = n - digit * 9; i <=  n; i++) {
		clone = i;
		ctor = i;
		while (ctor != 0) {
			clone += ctor % 10;
			ctor /= 10;
		}

		if (clone == n) {
			ctor = i;
			break;
		}
	}
	if (clone == n)
		printf("%d", ctor);
	else
		printf("0");

	return 0;
}