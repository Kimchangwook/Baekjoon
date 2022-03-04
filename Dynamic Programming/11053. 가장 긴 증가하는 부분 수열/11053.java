import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 1000;
    public static int[] d = new int[MAX + 1];

    public static int lis_dp(int n, int[] list) {
        int max = 1;

        for (int i = 1; i <= n; i++) {
            d[i] = 1;
            for (int j = 1; j < i; j++) {
                if (list[i] > list[j] && d[i] <= d[j])
                    d[i] = d[j] + 1;
            }
            if (max < d[i])
                max = d[i];
        }

        return max;
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