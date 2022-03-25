import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 100000;

    // 기름을 넣어야 하는 현재 도시부터
    // 앞으로 가야할 도시들 중
    // 기름 가격이 현재 도시보다 작을 때 까지는
    // 현재 도시에서 한번에 넣고 간다.
    public static long f(int n, int[] distance, int[] oilPrice) {
        int L;  // 각 도시에서 구매해야 할 리터 수
        int skipCities;
        long cost = 0;

        for (int i = 0; i < n; i++) {
            L = 0;
            skipCities = 0;
            for (int j = i + 1; j < n; j++) {
                if (oilPrice[i] < oilPrice[j]) {
                    L += distance[j - 1];
                    skipCities++;
                } else {
                    L += distance[j - 1];
                    break;
                }
            }

            cost += (long) L * oilPrice[i];
            i += skipCities;
        }

        return cost;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N;  // num of cities
        int[] distance;
        int[] oilPrice;
        long result;

        N = Integer.parseInt(br.readLine());

        distance = new int[MAX];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N - 1; i++)
            distance[i] = Integer.parseInt(st.nextToken());

        oilPrice = new int[MAX];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            oilPrice[i] = Integer.parseInt(st.nextToken());

        result = f(N, distance, oilPrice);

        System.out.println(result);
    }
}