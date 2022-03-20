import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int greedy(int[] coin, int n, int k) {
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (k == 0) return count;

            if (coin[i] <= k) {
                count += k / coin[i];
                k %= coin[i];
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n, k;   // n->동전의 종류, k->가치의 합
        int[] coin; // 동전 배열
        int result;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        coin = new int[n];
        for (int i = 0; i < n; i++)
            coin[i] = Integer.parseInt(br.readLine());

        result = greedy(coin, n, k);

        bw.write(String.valueOf(result));
        bw.flush();
    }
}