### 우선 순위 큐(Priority Queue)
***

큐(queque)는 먼저 들어간 데이터가 먼저나오는 FIFO(First In First Out)구조의 자료구조이다.   
__우선 순위 큐(Priority Queue)__ 는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 자료구조 이다.   
__우선 순위 큐__ 는 일반적으로 __힙(Heap)__ 을 이용해 구현한다.

#### 최대 힙(Max Heap)

부모 노드의 키 값이 자식 노드보다 크거나 같은 완전이진트리이다.   
❝ key(부모노드) ≥ key(자식노드) ❞   

![max heap](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcT2Dxb%2FbtqSATggBLA%2FCIBeKSLq0s6MDTNVM345Jk%2Fimg.png)   

#### 최소 힙(Min Heap)

부모 노드의 키 값이 자식 노드보다 작거나 같은 완전이진트리이다.   
❝ key(부모노드) ≥ key(자식노드) ❞   

![min heap](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbwtTZl%2FbtqSASIpEE1%2FzJxtetzfI1OGHucT99Mcuk%2Fimg.png)   

#### 구현

힙은 일반적으로 __배열을 이용하여 구현__ 한다. 완전 이진트리이므로 중간에 비어있는 요소가 없기 때문이다.

```
#include <stdio.h>
#define MAX 1000

// 최대 힙 구현
typedef struct Heap{
   int size;
   int max_heap[MAX];
} Heap;

// 삽입
void push (Heap* h, int data) {
   if (h->size == MAX - 1) return -1;
   
   int index = ++(h->size); 
   
   while (index != 1 && h->max_heap[index] > h->max_heap[index / 2]) {
      h->max_heap[index] = h->max_heap[index / 2];
      index /= 2;
   }
   
   h->max_heap[index] = data;
}

// 삭제
int pop (Heap* h) {
   int data = h->max_heap[1];
   int tmp = h->max_heap[h->size--];
   int parent = 1;
   int child = parent * 2;
   
   while (child <= h->size) {
      if (child < h->size && h->max_heap[child] < h->max_heap[child + 1])
         child = child + 1;
         
      if (h->max_heap[child] > tmp) {
         h->max_heap[parent] = h->max_heap[child];
         parent = child;
         child = parent * 2;
      }
      else
         break;
   }
   
   h->max_heap[parent] = tamp;
   return data;
}  
```
