import java.io.*;
import java.util.*;

public class Main {
    // Heap 구조체 정의
    public static class Heap {
        public int[] maxHeap;
        public int size;

        public Heap(int size) {
            maxHeap = new int[size];
            this.size = 0;
        }
    }

    // 삽입
    public static void push(Heap h, int item) {
        int index = ++h.size;

        while (index != 1 && h.maxHeap[index / 2] < item) {
            h.maxHeap[index] = h.maxHeap[index / 2];
            index = index / 2;
        }

        h.maxHeap[index] = item;
    }

    // 루트 노드 출력 후 정렬
    public static int pop(Heap h) {
        if (h.size == 0) return 0;

        int item = h.maxHeap[1];
        int tmp = h.maxHeap[h.size--];
        int parent = 1;
        int child = parent * 2;

        while (child <= h.size) {
            if (h.maxHeap[child] < h.maxHeap[child + 1])
                child = child + 1;
            if (h.maxHeap[child] > tmp) {
                h.maxHeap[parent] = h.maxHeap[child];
                parent = child;
                child = parent * 2;
            } else
                break;
        }

        h.maxHeap[parent] = tmp;
        return item;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        // 정수를 일일이 문자열로 변환해 출력하는것 보다
        // 문자열에 정수를 추가한 후 한번에 출력하는 것이
        // 더 빠르다.
        StringBuilder sb = new StringBuilder();

        int n;
        int item;
        Heap heap;
        int i;

        n = Integer.parseInt(br.readLine());
        heap = new Heap(n);
        for (i = 0; i < n; i++) {
            item = Integer.parseInt(br.readLine());
            if (item != 0)
                push(heap, item);
            else {
                sb.append(pop(heap));
                sb.append("\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();

    }
}