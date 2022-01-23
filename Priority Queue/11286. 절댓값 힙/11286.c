#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100001

// HeapŸ�� ����ü ����
typedef struct Heap {
	int abs_min_heap[MAX];
	int size;
}Heap;

// �ʱ� ����
Heap* init() {
	Heap* h = malloc(sizeof(Heap));
	h->size = 0;

	return h;
}


// ����
void push(Heap* h, int data) {
	if (h->size == MAX - 1) return;

	int index = ++(h->size);
	int abs_data = abs(data);	// ���� �� �������� ����
	int abs_parent;	// ũ�⸦ ���� ���� ����

	// �θ�� ������ ��
	// ������ �������� ������ �� ������ SWAP
	// ������ ������ ���� ��
	// �� �������� �θ� ��ġ ��Ŵ
	while (index != 1) {
		abs_parent = abs(h->abs_min_heap[index / 2]);
		
		if (abs_parent > abs_data) {
			h->abs_min_heap[index] = h->abs_min_heap[index / 2];
			index /= 2;
		}
		else if (abs_parent == abs_data && h->abs_min_heap[index/2] > data) {
			h->abs_min_heap[index] = h->abs_min_heap[index / 2];
			index /= 2;
		}
		else
			break;
	}

	h->abs_min_heap[index] = data;
}

// ���� + ����
int pop(Heap* h) {
	if (h->size == 0) return 0;

	int data = h->abs_min_heap[1];	// ������ ������
	int tmp = h->abs_min_heap[h->size--];	// ���� ������
	int abs_tmp = abs(tmp);	// ���� �������� ����
	int parent = 1;	// �θ��� index
	int child = parent * 2;	// �ڽ��� index
	int abs_left_child;	// ���� �ڽ��� ����
	int abs_right_child;	// ������ �ڽ��� ����
	int abs_child;	// �ڽĵ��� �� ���� �ڽ��� ����

	// �� �ڽ��� ������ ���Ͽ� �� ���� �ڽ��� ��¥ �ڽ����� �޾Ƶ帲
	// ���� ������ ���ٸ� ������ ���� �� ���� �ڽ��� �޾Ƶ帰��.
	// tmp�� ���񰪰� ��, �ڽ��� ������ �� ������ swap, 
	// ���� ������ ���ٸ� ������ ���� ��, �ڽ��� �� ������ swap
	// �׷��� ������ break, tmp ����
	while (child <= h->size) {
		abs_left_child = abs(h->abs_min_heap[child]);
		abs_right_child = abs(h->abs_min_heap[child + 1]);

		if (child < h->size && abs_left_child > abs_right_child) 
			child = child + 1;
		else if (child < h->size && abs_left_child == abs_right_child && h->abs_min_heap[child] > h->abs_min_heap[child + 1]) 
			child = child + 1;

		abs_child = abs(h->abs_min_heap[child]);

		if (abs_child < abs_tmp) {
			h->abs_min_heap[parent] = h->abs_min_heap[child];
			parent = child;
			child = parent * 2;
		}
		else if (abs_child == abs_tmp && h->abs_min_heap[child] < tmp) {
			h->abs_min_heap[parent] = h->abs_min_heap[child];
			parent = child;
			child = parent * 2;
		}
		else
			break;
	}

	h->abs_min_heap[parent] = tmp;
	return data;
}

int main() {
	int n;
	int data;
	Heap* heap;
	int i;

	scanf("%d", &n);
	heap = init();

	for (i = 0; i < n; i++) {
		scanf("%d", &data);

		if (data != 0)
			push(heap, data);
		else
			printf("%d\n", pop(heap));
	}

	free(heap);

	return 0;
}