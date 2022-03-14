import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 1001;
    public static int[][] d = new int[MAX][MAX];

    public static int dp(String A, String B) {
        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                if (A.charAt(i) == B.charAt(j))
                    d[i + 1][j + 1] = d[i][j] + 1;
                else
                    d[i + 1][j + 1] = Math.max(d[i][j + 1], d[i + 1][j]);
            }
        }

        return d[A.length()][B.length()];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String A;
        String B;
        int result;

        A = br.readLine();
        B = br.readLine();

        result = dp(A, B);
        bw.write(String.valueOf(result));
        bw.flush();
    }
}