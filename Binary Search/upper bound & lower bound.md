### upper bound & lower bound
***

이진탐색(Binary Search)기반의 탐색 방법입니다. 배열 또는 리스트가 정렬 되어있어야 한다.

#### •upper bound
key 값을 초과하는 가장 첫 번째 원소의 위치를 구하는 함수다.   
```
int upper_bound (int* list, int n, int key) { 
   int start = 0;
   int end = n;
   int mid;
  
   while (start < end){
      mid = (start + end) / 2;
    
      if (list[mid] > key) 
         end = mid;
      else
         start = mid + 1;
   }
   return end;
}
```

#### •lower bound
key 값 크거나 같은 가장 첫 번째 원소의 위치를 구하는 함수다.  
key값이 __없으면__ key값보다 큰 가장 작은 정수 값을 찾는다.
```
int lower_bound (int* list, int n, int key) {
   int start = 0;
   int end = n;
   int mid;
   
   while (start < end) {
      mid = (start + end) / 2;
      
      if (list[mid] >= key)
         end = mid;
      else
         start = mid + 1;
   }
   return end;
}
```
