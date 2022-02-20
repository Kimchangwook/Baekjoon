import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 1001;

    public static class Cost {
        public int red;
        public int green;
        public int blue;

        public Cost(int r, int g, int b) {
            red = r;
            green = g;
            blue = b;
        }
    }

    public static Cost[] paintedCost;

    // 뒤에서 부터 최솟값을 계산
    // r -> r + min(g, b)
    // g -> g + min(r, b)
    // b -> b + min(r, g)
    public static int cost(int depth, int N) {
        if (depth == N)
            return 0;

        cost(depth + 1, N);

        if (depth == 0)
            return Math.min(Math.min(paintedCost[depth + 1].red, paintedCost[depth + 1].green), paintedCost[depth + 1].blue);

        paintedCost[depth].red += Math.min(paintedCost[depth + 1].green, paintedCost[depth + 1].blue);
        paintedCost[depth].green += Math.min(paintedCost[depth + 1].red, paintedCost[depth + 1].blue);
        paintedCost[depth].blue += Math.min(paintedCost[depth + 1].red, paintedCost[depth + 1].green);

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N;
        int result;

        N = Integer.parseInt(br.readLine());
        paintedCost = new Cost[N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            paintedCost[i] = new Cost(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        result = cost(0, N);

        bw.write(String.valueOf(result));
        bw.flush();
    }
}