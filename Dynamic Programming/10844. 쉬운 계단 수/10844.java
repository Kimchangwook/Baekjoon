import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 101;
    public static final int DIVISOR = 1000000000;
    public static int[][] memo = new int[MAX][MAX];

    // 점화식
    // i == 0, memo[n][i] = memo[n - 1][i + 1]
    // i == 9, memo[n][i] = memo[n - 1][i - 1]
    // else, memo[n][i] = memo[n - 1][i - 1] + memo[n - 1][i + 1]
    public static int dp(int N) {
        int i, j;
        long result = 0;
        long tmp;

        for (i = 1; i <= 9; i++)
            memo[1][i] = 1;

        for (i = 2; i <= N; i++) {
            for (j = 0; j <= 9; j++) {
                if (j == 0)
                    tmp = memo[i - 1][j + 1];
                else if (j == 9)
                    tmp = memo[i - 1][j - 1];
                else
                    tmp = memo[i - 1][j - 1] + memo[i - 1][j + 1];

                memo[i][j] = (int)(tmp % DIVISOR);
            }
        }

        for(i = 0; i <= 9; i++)
            result += memo[N][i];

        return (int)(result % DIVISOR);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int result = 0;

        N = Integer.parseInt(br.readLine());

        result = dp(N);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}