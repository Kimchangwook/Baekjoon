#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

// HeapŸ�� ����ü ����
typedef struct Heap {
	int heap[MAX];
	int size;
}Heap;

// �ʱ� ����
Heap* init() {
	Heap* h = malloc(sizeof(Heap));
	h->size = 0;

	return h;
}

// ���� �ּڰ� Ȥ �ִ� ��ȯ
int get_root(Heap* h) {
	return h->heap[1];
}

// �ִ��� ����
void max_heap_push(Heap* h, int data) {
	if (h->size == MAX - 1) return -1;

	int index = ++(h->size);

	while (index != 1 && data > h->heap[index / 2]) {
		h->heap[index] = h->heap[index / 2];
		index = index / 2;
	}

	h->heap[index] = data;
}

// �ִ� �� ����
int max_heap_pop(Heap* h) {
	if (h->size == 0) return -1;

	int data = h->heap[1];
	int tmp = h->heap[h->size--];
	int parent = 1;
	int child = parent * 2;

	while (child <= h->size) {
		if (child < h->size && h->heap[child] < h->heap[child + 1]) {
			child = child + 1;
		}

		if (h->heap[child] > tmp) {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = parent * 2;
		}
		else
			break;
	}

	h->heap[parent] = tmp;

	return data;
}

// �ּ��� ����
void min_heap_push(Heap* h, int data) {
	if (h->size == MAX - 1) return -1;

	int index = ++(h->size);

	while (index != 1 && data < h->heap[index / 2]) {
		h->heap[index] = h->heap[index / 2];
		index = index / 2;
	}

	h->heap[index] = data;
}

// �ִ��� ����
int min_heap_pop(Heap* h) {
	if (h->size == 0) return -1;

	int data = h->heap[1];
	int tmp = h->heap[h->size--];
	int parent = 1;
	int child = parent * 2;

	while (child <= h->size) {
		if (child < h->size && h->heap[child] > h->heap[child + 1]) {
			child = child + 1;
		}

		if (h->heap[child] < tmp) {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = parent * 2;
		}
		else
			break;
	}

	h->heap[parent] = tmp;

	return data;
}
// �߰����� ã�� �Լ�
// max_heap -> �߰��� ������ ����
// min_heap -> �߰��� �ʰ��� ����
// �׻� �߰����� max_heap�� ��Ʈ�� �����Ѵ�.
// �߰������� ū data�� min_heap�� push
// else max_heap�� push
// max_heap�� min_heap�� ũ��� max_heap�� ũ�⺸�� �׻� ���ų� 1 ũ�� ����
// -> �̴� max_heap�� ��Ʈ�� �׻� �߰����� �����ϰ� �ϵ��� �ϱ� ����.
int find_mid(Heap* min_heap, Heap* max_heap, int data) {
	int gap;

	if (max_heap->size == 0 || get_root(max_heap) >= data)
		max_heap_push(max_heap, data);
	else
		min_heap_push(min_heap, data);

	gap = min_heap->size - max_heap->size;

	if (gap == 1) {
		max_heap_push(max_heap, min_heap_pop(min_heap));
	}
	else if (gap == -2) {
		min_heap_push(min_heap, max_heap_pop(max_heap));
	}

	return get_root(max_heap);
}


int main() {
	int n;
	Heap* min_heap;
	Heap* max_heap;
	int  i, data;
	int mid;

	scanf("%d", &n);
	min_heap = init();
	max_heap = init();

	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		mid = find_mid(min_heap, max_heap, data);
		printf("%d\n", mid);
	}

	return 0;
}