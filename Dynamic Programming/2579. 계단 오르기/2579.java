import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 301;
    public static int[] memo = new int[MAX];

    // 2가지 점화식
    // memo[n] = list[n] + memo[n - 2] -> 이전 계단을 밟지 않은 경우
    // memo[n] = list[n] + list[n - 1] + memo[n - 3] -> 이전 계단을 밟은 경우
    public static int dp(int N, int[] list) {
        memo[1] = list[1];
        memo[2] = list[2] + list[1];

        for (int i = 3; i <= N; i++)
            memo[i] = list[i] + Math.max(memo[i - 2], list[i - 1] + memo[i - 3]);

        return memo[N];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int[] stairs;
        int result;

        N = Integer.parseInt(br.readLine());
        stairs = new int[MAX];
        for (int i = 1; i <= N; i++)
            stairs[i] = Integer.parseInt(br.readLine());

        result = dp(N, stairs);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}