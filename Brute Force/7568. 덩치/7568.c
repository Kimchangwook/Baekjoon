#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct BodySpec {
	int weight;
	int height;
}BodySpec;

int main() {
	int* rank;	// 등수
	int n;	// 학생 수
	BodySpec* body;	// 몸무게, 키 구조체
	int count = 0;
	int i, j;

	scanf("%d", &n);
	rank = malloc(sizeof(int) * n);
	body = malloc(sizeof(BodySpec) * n);

	// 학생별 몸무게, 키 입력
	for (i = 0; i < n; i++)
		scanf("%d %d", &(body[i].weight), &(body[i].height));

	// 학생들의 덩치 등수 구하기 위한 반복문
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++) {
			if (body[i].weight < body[j].weight && body[i].height < body[j].height)
				count++;
		}
		rank[i] = count + 1;
	}

	// 덩치 등수 출력
	for (i = 0; i < n; i++) {
		printf("%d ", rank[i]);
	}

	return 0;
}