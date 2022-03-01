import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 10001;
    public static int[] memo = new int[MAX];

    // 점화식
    // memo[n] = MAX(memo[n - 2], list[n - 1] + memo[n - 3], list[n - 1] + memo[n - 4])
    // result = MAX(memo[n], memo[n - 1])
    public static int dp(int N, int[] list) {
        if (N == 1) {
            memo[1] = list[1];
            return memo[1];
        } else if (N == 2) {
            memo[1] = list[1];
            memo[2] = list[2] + list[1];
            return memo[2];
        } else {
            memo[1] = list[1];
            memo[2] = list[2] + list[1];
            memo[3] = list[3] + Math.max(list[2], list[1]);

            for (int i = 4; i <= N; i++) {
                memo[i] = list[i] + Math.max(Math.max(memo[i - 2], list[i - 1] + memo[i - 3]), list[i - 1] + memo[i - 4]);
            }

            return Math.max(memo[N], memo[N - 1]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int[] wines;
        int result = 0;

        N = Integer.parseInt(br.readLine());
        wines = new int[N + 1];
        for (int i = 1; i <= N; i++)
            wines[i] = Integer.parseInt(br.readLine());

        result = dp(N, wines);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}