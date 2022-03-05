import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 1000;
    public static int[] d1 = new int[MAX + 1];
    public static int[] d2 = new int[MAX + 1];

    public static int lis_dp(int n, int[] list) {
        int max = 1;

        // 오름 차순
        for (int i = 1; i <= n; i++) {
            d1[i] = 1;
            for (int j = 1; j < i; j++) {
                if (list[i] > list[j] && d1[i] <= d1[j])
                    d1[i] = d1[j] + 1;
            }
        }

        // 내림 차순
        for (int i = n; i >= 1; i--) {
            d2[i] = 1;
            for (int j = n; j > i; j--) {
                if (list[i] > list[j] && d2[i] <= d2[j])
                    d2[i] = d2[j] + 1;
            }
        }

        max = d1[1] + d2[1];
        for (int i = 2; i <= n; i++)
            if (max < d1[i] + d2[i])
                max = d1[i] + d2[i];

        return --max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N;
        int[] A;
        int result = 0;

        N = Integer.parseInt(br.readLine());
        A = new int[MAX + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            A[i] = Integer.parseInt(st.nextToken());

        result = lis_dp(N, A);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}