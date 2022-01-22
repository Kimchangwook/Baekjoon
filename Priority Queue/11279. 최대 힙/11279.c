#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 힙 자료 구조 구조체 정의
typedef struct Heap {
	int* max_heap;
	int size;
} Heap;

// 힙 사용 위해 초기 설정
void init(Heap* h, int n) {
	h->max_heap = malloc(sizeof(int) * n);
	h->size = 0;
}

// 삽입
void push(Heap* h, int item) {
	int index = ++(h->size);

	while (index != 1 && h->max_heap[index / 2] < item) {
		h->max_heap[index] = h->max_heap[index / 2];
		index = index / 2;
	}

	h->max_heap[index] = item;
}

// 루트 노드 출력 후 정렬
int pop(Heap* h) {
	if (h->size == 0) return 0;

	int item = h->max_heap[1];
	int tmp = h->max_heap[(h->size)--];
	int parent = 1;
	int child = parent * 2;

	while (child <= h->size) {
		if (h->max_heap[child] < h->max_heap[child + 1])
			child = child + 1;

		if (tmp < h->max_heap[child]) {
			h->max_heap[parent] = h->max_heap[child];
			parent = child;
			child = parent * 2;
		}
		else
			break;
	}

	h->max_heap[parent] = tmp;
	return item;
}

int main() {
	Heap heap;
	int n;
	int item;
	int i;

	scanf("%d", &n);
	init(&heap, n);

	for (i = 0; i < n; i++) {
		scanf("%d", &item);
		if (item != 0)
			push(&heap, item);
		else
			printf("%d\n", pop(&heap));
	}

	return 0;
}