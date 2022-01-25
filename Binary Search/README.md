## 이분 탐색   

![이분 탐색 이미지](https://blog.penjee.com/wp-content/uploads/2015/04/binary-and-linear-search-animations.gif)

### 이분 탐색
__정렬되어 있는 배열__ 에서 탐색 범위를 반씩 줄여가며 찾고자 하는 값을 찾는 탐색 방법이다. 

### 반복   

```
int binary_search (int* list, int n, int key) {
   int start = 0;
   int end = n - 1;
   int mid;
   
   while (start <= end) {
      mid = (start + end) / 2;
      
      if (list[mid] > key)
         end = mid - 1;
      else if (list[mid] < key)
         start = mid + 1;
      else
         return mid;
   }
   
   return -1;
}
```

### 재귀  

```
int binary_search (int* list, int start, int end, int key) {
   if (start > end)
      return -1;
   
   int mid = (start + end) / 2;
   
   if (list[mid] == key)
      return mid;
   else if (list[mid] > key)
      return binary_search(list, start, mid - 1, key);
   else
      return binary_search(list, mid + 1, end, key);
}
```
