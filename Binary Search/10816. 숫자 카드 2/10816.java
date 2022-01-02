import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 500000;
    public static int[] arr = new int[MAX];
    public static int[] card = new int[MAX];
    public static int[] findNum = new int[MAX];

    public static void merge(int[] list, int s, int mid, int e) {
        int i, j, k;
        i = s;
        j = mid + 1;
        k = s;

        while (i <= mid && j <= e) {
            if (list[i] < list[j])
                arr[k++] = list[i++];
            else
                arr[k++] = list[j++];
        }

        if (i <= mid) {
            while (i <= mid)
                arr[k++] = list[i++];
        } else {
            while (j <= e)
                arr[k++] = list[j++];
        }

        for (int l = s; l <= e; l++)
            list[l] = arr[l];
    }

    // 합병 정렬 함수
    public static void mergeSort(int[] list, int s, int e) {
        if (s < e) {
            int mid = (s + e) / 2;

            mergeSort(list, s, mid);
            mergeSort(list, mid + 1, e);
            merge(list, s, mid, e);
        }
    }

    // upperBound는 key값보다 처음으로 큰 값이 나오는 위치를 리턴
    public static int upperBound(int[] list, int n, int key) {
        int s = 0;
        int e = n;
        int mid;

        while (s < e) {
            mid = (s + e) / 2;

            if (list[mid] <= key)
                s = mid + 1;
            else
                e = mid;
        }
        return e;
    }

    // lowerBound는 데이터내 특정 key값보다 같거나 큰값이 처음 나오는 위치를 리턴
    public static int lowerBound(int[] list, int n, int key) {
        int s = 0;
        int e = n;
        int mid;

        while (s < e) {
            mid = (s + e) / 2;

            if (list[mid] < key)
                s = mid + 1;
            else
                e = mid;
        }
        return e;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n;  // 보유 카드 개수
        int m;  // 찾아야 하는 숫자 개수
        int i;
        int ans;

        // n입력 및 card 배열 초기화
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++) {
            card[i] = Integer.parseInt(st.nextToken());
        }

        // m입력 및 findNum 배열 초기화
        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < m; i++) {
            findNum[i] = Integer.parseInt(st.nextToken());
        }

        mergeSort(card, 0, n - 1); // card 배열 정렬

        // upperBound - lowerBound -> 중복 key 개수 // & 출력
        for (i = 0; i < m; i++) {
            ans = upperBound(card, n, findNum[i]) - lowerBound(card, n, findNum[i]);
            bw.write(String.valueOf(ans) + ' ');
        }
        bw.flush();
        bw.close();
    }
}
