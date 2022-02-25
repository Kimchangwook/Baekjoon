import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 1000001;
    public static int[] memo = new int[MAX];

    // 3가지의 점화식을 갖는다
    // memo[n] = memo[n / 3] + 1
    // memo[n] = memo[n / 2] + 1
    // memo[n] = memo[n - 1] + 1
    // 이 중 최솟값을 갖게 된다.
    public static int search(int N) {
        memo[1] = 0;

        for (int i = 2; i <= N; i++) {
            if (i % 6 == 0)
                memo[i] = 1 + Math.min(Math.min(memo[i / 2], memo[i / 3]), memo[i - 1]);
            else if (i % 3 == 0)
                memo[i] = 1 + Math.min(memo[i / 3], memo[i - 1]);
            else if (i % 2 == 0)
                memo[i] = 1 + Math.min(memo[i / 2], memo[i - 1]);
            else
                memo[i] = 1 + memo[i - 1];
        }

        return memo[N];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int result;

        N = Integer.parseInt(br.readLine());
        result = search(N);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}