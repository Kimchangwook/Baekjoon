#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100001

// Heap타입 구조체 정의
typedef struct Heap {
	int abs_min_heap[MAX];
	int size;
}Heap;

// 초기 설정
Heap* init() {
	Heap* h = malloc(sizeof(Heap));
	h->size = 0;

	return h;
}


// 삽입
void push(Heap* h, int data) {
	if (h->size == MAX - 1) return;

	int index = ++(h->size);
	int abs_data = abs(data);	// 삽입 할 데이터의 절댓값
	int abs_parent;	// 크기를 비교할 값의 절댓값

	// 부모와 절댓값을 비교
	// 삽입할 데이터의 절댓값이 더 작으면 SWAP
	// 같으면 원래의 값을 비교
	// 더 작은값을 부모에 위치 시킴
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

// 삭제 + 정렬
int pop(Heap* h) {
	if (h->size == 0) return 0;

	int data = h->abs_min_heap[1];	// 삭제할 데이터
	int tmp = h->abs_min_heap[h->size--];	// 비교할 데이터
	int abs_tmp = abs(tmp);	// 비교할 데이터의 절댓값
	int parent = 1;	// 부모의 index
	int child = parent * 2;	// 자식의 index
	int abs_left_child;	// 왼쪽 자식의 절댓값
	int abs_right_child;	// 오른쪽 자식의 절댓값
	int abs_child;	// 자식들중 더 작은 자식의 절댓값

	// 두 자식의 절댓값을 비교하여 더 작은 자식을 진짜 자식으로 받아드림
	// 만일 절댓값이 같다면 본연의 값중 더 작은 자식을 받아드린다.
	// tmp의 절댓값과 비교, 자식의 절댓값이 더 작으면 swap, 
	// 만일 절댓값이 같다면 본연의 값을 비교, 자식이 더 작으면 swap
	// 그렇지 않으면 break, tmp 삽입
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