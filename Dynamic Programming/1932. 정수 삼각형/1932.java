import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 250 * 501;
    public static int[] triangle = new int[MAX + 1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n;   // 삼각형의 크기
        int index;
        int i, j;

        n = Integer.parseInt(br.readLine());
        for (i = 1; i <= n; i++) {
            index = ((i - 1) * i) / 2;
            st = new StringTokenizer(br.readLine());
            for (j = 1; j <= i; j++) {
                triangle[index + j] = Integer.parseInt(st.nextToken());
            }
        }
        // 삼각형의 밑에서 부터 최댓값을 구하며 올라온다.
        for (i = n - 1; i >= 1; i--) {
            index = ((i - 1) * i) / 2;
            for (j = 1; j <= i; j++) {
                triangle[index + j] += Math.max(triangle[index + j + i], triangle[index + j + i + 1]);
            }
        }

        bw.write(String.valueOf(triangle[1]));
        bw.flush();
        bw.close();
    }
}