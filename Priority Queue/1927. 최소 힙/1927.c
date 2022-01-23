#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

// Heap타입 구조체 정의
typedef struct Heap {
	int min_heap[MAX];
	int size;
}Heap;

// 초기 설정
Heap* init() {
	Heap* h;
	h = malloc(sizeof(Heap));
	h->size = 0;

	return h;
}

// 삽입
void push(Heap* h, int data) {
	if (h->size == MAX - 1) return;

	int index = ++(h->size);

	while (index != 1 && h->min_heap[index / 2] > data) {
		h->min_heap[index] = h->min_heap[index / 2];
		index /= 2;
	}

	h->min_heap[index] = data;
}

// 삭제 + 정렬
int pop(Heap* h) {
	if (h->size == 0) return 0;

	int data = h->min_heap[1];
	int tmp = h->min_heap[h->size--];
	int parent = 1;
	int child;

	while (1) {
		child = parent * 2;

		if (child < h->size && h->min_heap[child] > h->min_heap[child + 1])
			child = child + 1;

		if (child <= h->size && h->min_heap[child] < tmp) {
			h->min_heap[parent] = h->min_heap[child];
			parent = child;
		}
		else
			break;
	}

	h->min_heap[parent] = tmp;
	return data;
}

int main() {
	int n;
	Heap* h;
	int i, data;

	scanf("%d", &n);
	h = init();

	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		if (data != 0)
			push(h, data);
		else
			printf("%d\n", pop(h));
	}

	free(h);

	return 0;
}