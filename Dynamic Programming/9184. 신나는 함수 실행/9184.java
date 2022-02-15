import java.io.*;
import java.util.*;

public class Main {
    public static final int[][][] memoization = new int[21][21][21];

    public static int w(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0)
            return 1;

        if (a > 20 || b > 20 || c > 20)
            return w(20, 20, 20);

        if (memoization[a][b][c] != 0)
            return memoization[a][b][c];

        if (a < b && b < c)
            return memoization[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else
            return memoization[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int a, b, c;
        int result = 0;

        while (true) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if (a == -1 && b == -1 && c == -1)
                break;

            result = w(a, b, c);
            sb.append("w(" + a + ", " + b + ", " + c + ") = " + result).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}