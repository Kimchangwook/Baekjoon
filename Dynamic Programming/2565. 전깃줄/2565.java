import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 100;
    public static int[] d1 = new int[MAX + 1];
    public static int[] d2 = new int[MAX + 1];

    static class Pos implements Comparable {
        int posA;
        int posB;

        public Pos(int a, int b) {
            posA = a;
            posB = b;
        }

        @Override
        public int compareTo(Object o) {
            Pos p = (Pos) o;
            return this.posA - p.posA;
        }
    }

    // LIS -> 나머지는 없애버림
    public static int lis_dp(int n, Pos[] list) {
        int max1 = 1;
        int max2 = 1;

        // 오름 차순
        for (int i = 0; i < n; i++) {
            d1[i] = 1;
            for (int j = 0; j < i; j++) {
                if (list[i].posB > list[j].posB && d1[i] <= d1[j])
                    d1[i] = d1[j] + 1;
            }
            if (max1 < d1[i])
                max1 = d1[i];
        }

        // 내림 차순
        for (int i = 0; i < n; i++) {
            d2[i] = 1;
            for (int j = 0; j < i; j++) {
                if (list[i].posB > list[j].posB && d2[i] <= d2[j])
                    d2[i] = d2[j] + 1;
            }
            if (max2 < d2[i])
                max2 = d2[i];
        }

        // 더 큰 경우를 고름
        if (max1 > max2)
            return n - max1;
        else
            return n - max2;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n;
        Pos[] electricWires;
        int result = 0;

        n = Integer.parseInt(br.readLine());
        electricWires = new Pos[MAX];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            electricWires[i] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        // 한 쪽 전선을 정렬
        Arrays.sort(electricWires, 0, n);

        result = lis_dp(n, electricWires);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}