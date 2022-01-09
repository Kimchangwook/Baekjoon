import java.io.*;
import java.util.*;

public class Main {
    public static int k;    // 보유 중인 랜선 개수
    public static int n;    // 필요한 랜선 개수
    public static int[] LANcable = new int[10000];  // 보유 중인 랜성 길이의 배열
    public static int maxLength;    // 만들 수 있는 랜선의 최대 길이

    // parametric search를 위한 결정 함수
    private static int decision(int length) {
        int count = 0;

        for (int i = 0; i < k; i++)
            count += LANcable[i] / length;

        if (count >= n)
            return 1;
        else
            return 0;
    }

    // Parametric search (upper bound)
    public static int search(int n) {
        int start = 1;
        int end = n + 1;
        int mid;

        while (start < end) {
            mid = (start + end) / 2;

            if (decision(mid) == 1)
                start = mid + 1;
            else
                end = mid;
        }
        return end;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int i;

        // 변수 초기화
        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for (i = 0; i < k; i++)
            LANcable[i] = Integer.parseInt(br.readLine());

        // 가장 긴 랜선 길이를 알기 위해 정렬
        Arrays.sort(LANcable, 0, k);

        // 탐색
        maxLength = search(LANcable[k - 1]) - 1;

        bw.write(String.valueOf(maxLength));
        bw.flush();
        bw.close();
    }
}