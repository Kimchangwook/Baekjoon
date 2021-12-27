#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ ����ϱ� ���� �Լ�
int squared(int a, int b, int c) {
	if (b <= 1)
		return a % c;

	long long result;	// ��� �������� �����÷ο� �߻��� �� �����Ƿ� long long���� ����

	// ������ ¦���� ���
	if (b % 2 == 0) {
		b /= 2;
		result = squared(a, b, c);
		return (result * result) % c;
	}
	// ������ Ȧ���� ��� 
	else {
		b /= 2;
		result = squared(a, b, c);
		return (((result * result) % c) * (a % c)) % c;
	}
}

int main() {
	int a, b, c;	// a�� b�� ���� ���� c�� ���� �������� ���Ѵ�.
	int result;

	scanf("%d %d %d", &a, &b, &c);
	result = squared(a, b, c);	// ��� �� ���

	printf("%d", result);

	return 0;
}