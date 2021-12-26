#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct BodySpec {
	int weight;
	int height;
}BodySpec;

int main() {
	int* rank;	// ���
	int n;	// �л� ��
	BodySpec* body;	// ������, Ű ����ü
	int count = 0;
	int i, j;

	scanf("%d", &n);
	rank = malloc(sizeof(int) * n);
	body = malloc(sizeof(BodySpec) * n);

	// �л��� ������, Ű �Է�
	for (i = 0; i < n; i++)
		scanf("%d %d", &(body[i].weight), &(body[i].height));

	// �л����� ��ġ ��� ���ϱ� ���� �ݺ���
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++) {
			if (body[i].weight < body[j].weight && body[i].height < body[j].height)
				count++;
		}
		rank[i] = count + 1;
	}

	// ��ġ ��� ���
	for (i = 0; i < n; i++) {
		printf("%d ", rank[i]);
	}

	return 0;
}