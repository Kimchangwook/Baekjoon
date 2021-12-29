import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int[] arr = new int[100000];

    public static void merge(int[] list, int left, int m, int right) {
        int i, j, k;
        i = left;
        j = m + 1;
        k = left;

        while (i <= m && j <= right) {
            if (list[i] < list[j])
                arr[k++] = list[i++];
            else
                arr[k++] = list[j++];
        }

        if (i <= m) {
            for (i = i; i <= m; i++)
                arr[k++] = list[i];
        } else {
            for (j = j; j <= right; j++)
                arr[k++] = list[j];
        }

        for (int l = left; l <= right; l++)
            list[l] = arr[l];
    }

    // 정렬 함수
    public static void mergeSort(int[] list, int left, int right) {
        if (left < right) {
            int m = (right + left) / 2;
            mergeSort(list, left, m);
            mergeSort(list, m + 1, right);
            merge(list, left, m, right);
        }
    }

    // num이 list배열에 존재하는지 찾는 함수 -> 이진 탐색
    public static int search(int[] list, int left, int right, int num) {
        if(left <= right) {
            if (list[left] > num && list[right] < num)
                return 0;

            int m = (right + left) / 2;

            if (list[m] == num)
                return 1;
            else if (list[m] > num)
                return search(list, left, m - 1, num);
            else if(list[m] < num)
                return search(list, m + 1, right, num);
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n, m;   // n: 기존에 존재하는 배열의 크기, m: 존재하는지 찾아야 하는 배열의 크기
        int[] A;    // A: 기존에 존재하는 배열,
        int[] M;    // M: 존재하는지 찾아야하는 배열
        int i;

        // n입력 & 배열 A 초기화
        n = Integer.parseInt(br.readLine());
        A = new int[n];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++)
            A[i] = Integer.parseInt(st.nextToken());

        // m입력 & 배열 M 초기화
        m = Integer.parseInt(br.readLine());
        M = new int[m];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < m; i++)
            M[i] = Integer.parseInt(st.nextToken());

        // M배열의 원소들을 search하기 위해 A배열 정렬
        mergeSort(A, 0, n - 1);

        // 탐색 및 출력
        for (i = 0; i < m; i++) {
            bw.write(search(A, 0, n - 1, M[i]) + "\n");
        }
        bw.flush();
        bw.close();
    }
}
