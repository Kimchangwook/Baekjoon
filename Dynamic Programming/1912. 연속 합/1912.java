import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 100000;
    public static int[] d = new int[MAX];

    // 점화식
    // d[i] = Math.max(d[i] + list[i], list[i])
    public static int dp(int n, int[] list) {
        int max;

        d[0] = list[0];
        max = d[0];

        for (int i = 1; i < n; i++) {
            d[i] = Math.max(d[i - 1] + list[i], list[i]);

            if (max < d[i])
                max = d[i];
        }

        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n;
        int[] list;
        int result;

        n = Integer.parseInt(br.readLine());
        list = new int[MAX];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            list[i] = Integer.parseInt(st.nextToken());

        result = dp(n, list);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}