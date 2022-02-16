import java.io.*;
import java.util.*;

public class Main {
    public static long[] memoization = new long[101];

    public static long P(int N){
        for (int i = 1; i <= N; i++) {
            if (memoization[N] != 0)
                return memoization[N];

            if (i >= 1 && i <= 3)
                memoization[i] = 1;
            else if (i >= 4 && i <= 5)
                memoization[i] = 2;
            else
                memoization[i] = memoization[i - 1] + memoization[i - 5];
        }

        return memoization[N];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int T;  // 테스트 케이스 개수
        int N;  // P(N);
        long length;

        T = Integer.parseInt(br.readLine());
        length = 0;

        for(int i = 0; i < T; i++){
            N = Integer.parseInt(br.readLine());
            length = P(N);
            sb.append(length).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}