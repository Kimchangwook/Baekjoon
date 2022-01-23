import java.util.*;
import java.io.*;

public class Main {
    private static final int MAX = 100001;

    // Heap타입 클래스 정의 (일종의 구조체 역학)
    public static class Heap {
        public int[] minHeap;
        public int size;

        public Heap() {
            this.minHeap = new int[MAX];
            this.size = 0;
        }
    }

    // 삽입
    public static void push(Heap h, int data) {
        if (h.size == MAX - 1) return;

        int index = ++h.size;

        while (index != 1 && (h.minHeap[index / 2] > data)) {
            h.minHeap[index] = h.minHeap[index / 2];
            index /= 2;
        }

        h.minHeap[index] = data;
    }

    // 삭제 + 정렬
    public static int pop(Heap h) {
        if (h.size == 0) return 0;

        int data = h.minHeap[1];
        int tmp = h.minHeap[h.size--];
        int parent = 1;
        int child = parent * 2;

        while (child <= h.size) {
            if (child < h.size && h.minHeap[child] > h.minHeap[child + 1])
                child = child + 1;
            if (h.minHeap[child] < tmp) {
                h.minHeap[parent] = h.minHeap[child];
                parent = child;
                child = parent * 2;
            } else
                break;
        }

        h.minHeap[parent] = tmp;
        return data;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        // 변수 선언
        int n, data;
        Heap heap;
        int i;

        // 변수 초기화
        n = Integer.parseInt(br.readLine());
        heap = new Heap();

        // 삽입 삭제
        for (i = 0; i < n; i++) {
            data = Integer.parseInt(br.readLine());

            if (data != 0)
                push(heap, data);
            else
                sb.append(pop(heap)).append("\n");
        }

        // 출력
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}