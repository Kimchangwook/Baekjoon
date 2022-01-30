import java.util.*;
import java.io.*;

public class Main {
    public static final int MAX = 100001;

    static class Heap {
        private int size;
        private int[] heap;

        public Heap() {
            size = 0;
            heap = new int[MAX];
        }

        public int getSize() {
            return size;
        }

        public int getRoot() {
            return heap[1];
        }
    }

    // 최대힙 삽입
    public static void maxHeapPush(Heap h, int data) {
        if (h.size == MAX - 1) return;

        int index = ++(h.size);

        while (index != 1 && data > h.heap[index / 2]) {
            h.heap[index] = h.heap[index / 2];
            index = index / 2;
        }

        h.heap[index] = data;
    }

    // 최대 힙 삭제
    public static int maxHeapPop(Heap h) {
        if (h.size == 0) return -1;

        int data = h.heap[1];
        int tmp = h.heap[h.size--];
        int parent = 1;
        int child = parent * 2;

        while (child <= h.size) {
            if (child < h.size && h.heap[child] < h.heap[child + 1]) {
                child = child + 1;
            }

            if (h.heap[child] > tmp) {
                h.heap[parent] = h.heap[child];
                parent = child;
                child = parent * 2;
            } else
                break;
        }

        h.heap[parent] = tmp;

        return data;
    }

    // 최소힙 삽입
    public static void minHeapPush(Heap h, int data) {
        if (h.size == MAX - 1) return;

        int index = ++(h.size);

        while (index != 1 && data < h.heap[index / 2]) {
            h.heap[index] = h.heap[index / 2];
            index = index / 2;
        }

        h.heap[index] = data;
    }

    // 최대힙 삭제
    public static int minHeapPop(Heap h) {
        if (h.size == 0) return -1;

        int data = h.heap[1];
        int tmp = h.heap[h.size--];
        int parent = 1;
        int child = parent * 2;

        while (child <= h.size) {
            if (child < h.size && h.heap[child] > h.heap[child + 1]) {
                child = child + 1;
            }

            if (h.heap[child] < tmp) {
                h.heap[parent] = h.heap[child];
                parent = child;
                child = parent * 2;
            } else
                break;
        }

        h.heap[parent] = tmp;

        return data;
    }

    // 중간값을 찾는 함수
    // maxHeap -> 중간값 이하의 값들
    // minHeap -> 중간값 초과의 값들
    // 항상 중간값은 maxHeap의 루트에 존재한다.
    // 중간값보다 큰 data는 minHeap에 push
    // else maxHeap에 push
    // maxHeap과 minHeap의 크기는 maxHeap의 크기보다 항상 같거나 1 크게 유지
    // -> 이는 maxHeap의 루트에 항상 중간값을 존재하게 하도록 하기 위함.
    public static int findMid(Heap minHeap, Heap maxHeap, int data) {
        int gap;

        if (maxHeap.size == 0 || maxHeap.getRoot() >= data)
            maxHeapPush(maxHeap, data);
        else
            minHeapPush(minHeap, data);

        gap = minHeap.size - maxHeap.size;

        if (gap == 1) {
            maxHeapPush(maxHeap, minHeapPop(minHeap));
        } else if (gap == -2) {
            minHeapPush(minHeap, maxHeapPop(maxHeap));
        }

        return maxHeap.getRoot();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int n, mid;
        Heap minHeap;
        Heap maxHeap;
        int i;
        int data;
        n = Integer.parseInt(br.readLine());
        minHeap = new Heap();
        maxHeap = new Heap();

        for (i = 0; i < n; i++) {
            data = Integer.parseInt(br.readLine());
            mid = findMid(minHeap, maxHeap, data);
            sb.append(mid).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}