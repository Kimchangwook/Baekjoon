import java.util.*;
import java.io.*;

public class Main {
    private static final int MAX = 100001;

    // Heap타입 클래스 정의 (일종의 구조체 역학)
    public static class Heap {
        public int[] absMinHeap;
        public int size;

        public Heap() {
            this.absMinHeap = new int[MAX];
            this.size = 0;
        }
    }

    // 삽입
    public static void push(Heap h, int data) {
        if (h.size == MAX - 1) return;

        int index = ++(h.size);
        int absData = Math.abs(data);	// 삽입 할 데이터의 절댓값
        int absParent;	// 크기를 비교할 값의 절댓값

        // 부모와 절댓값을 비교
        // 삽입할 데이터의 절댓값이 더 작으면 SWAP
        // 같으면 원래의 값을 비교
        // 더 작은값을 부모에 위치 시킴
        while (index != 1) {
            absParent = Math.abs(h.absMinHeap[index / 2]);

            if (absParent > absData) {
                h.absMinHeap[index] = h.absMinHeap[index / 2];
                index /= 2;
            }
            else if (absParent == absData && h.absMinHeap[index/2] > data) {
                h.absMinHeap[index] = h.absMinHeap[index / 2];
                index /= 2;
            }
            else
                break;
        }

        h.absMinHeap[index] = data;
    }

    // 삭제 + 정렬
    public static int pop(Heap h) {
        if (h.size == 0) return 0;

        int data = h.absMinHeap[1];	// 삭제할 데이터
        int tmp = h.absMinHeap[h.size--];	// 비교할 데이터
        int absTmp = Math.abs(tmp);	// 비교할 데이터의 절댓값
        int parent = 1;	// 부모의 index
        int child = parent * 2;	// 자식의 index
        int absLeftChild;	// 왼쪽 자식의 절댓값
        int absRightChild;	// 오른쪽 자식의 절댓값
        int absChild;	// 자식들중 더 작은 자식의 절댓값

        // 두 자식의 절댓값을 비교하여 더 작은 자식을 진짜 자식으로 받아드림
        // 만일 절댓값이 같다면 본연의 값중 더 작은 자식을 받아드린다.
        // tmp의 절댓값과 비교, 자식의 절댓값이 더 작으면 swap, 
        // 만일 절댓값이 같다면 본연의 값을 비교, 자식이 더 작으면 swap
        // 그렇지 않으면 break, tmp 삽입
        while (child <= h.size) {
            absLeftChild = Math.abs(h.absMinHeap[child]);
            absRightChild = Math.abs(h.absMinHeap[child + 1]);

            if (child < h.size && absLeftChild > absRightChild)
                child = child + 1;
            else if (child < h.size && absLeftChild == absRightChild && h.absMinHeap[child] > h.absMinHeap[child + 1])
                child = child + 1;

            absChild = Math.abs(h.absMinHeap[child]);

            if (absChild < absTmp) {
                h.absMinHeap[parent] = h.absMinHeap[child];
                parent = child;
                child = parent * 2;
            }
            else if (absChild == absTmp && h.absMinHeap[child] < tmp) {
                h.absMinHeap[parent] = h.absMinHeap[child];
                parent = child;
                child = parent * 2;
            }
            else
                break;
        }

        h.absMinHeap[parent] = tmp;
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