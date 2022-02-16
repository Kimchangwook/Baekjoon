import java.io.*;
import java.util.*;

public class Main {
    public static final int DIVISOR = 15746;
    public static int[] memoizaition = new int[1000001];

    // memoization[n] = memoization[n - 1] + memoization[n - 2]
    // N의 범위가 매우 크기 때문에 반복문을 이용.
   public static int tile(int N){
       for (int i = 1; i <= N; i++) {
           if (i == 1)
               memoizaition[i] = 1;
           else if (i == 2)
               memoizaition[i] = 2;
           else
               memoizaition[i] = (memoizaition[i - 1] + memoizaition[i - 2]) % DIVISOR;
       }

       return memoizaition[N];
   }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int cases;

        N = Integer.parseInt(br.readLine());
        cases = 0;

        cases = tile(N);

        bw.write(String.valueOf(cases));
        bw.flush();
        bw.close();
    }
}