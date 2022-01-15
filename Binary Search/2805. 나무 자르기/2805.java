import java.io.*;
import java.util.*;

public class Main {
    // 탐색 과정 속 결정 함수
    private static int decision(int[] list, int height, int m) {
        long count = 0;

        for (int i = 0; i < list.length; i++) {
            if (list[i] > height)
                count += list[i] - height;
        }

        if (count >= m)
            return 1;
        else
            return 0;
    }

    // 절단기를 설정 할 수 있는 높이를 구하는 탐색(upper bound)
    public static int search(int[] list, int n, int key, int m) {
        int start = 0;
        int end = n + 1;
        int mid;

        while (start < end) {
            mid = (int)(((long)start + (long)end) / 2);

            if (decision(list, mid, m) == key)
                start = mid + 1;
            else
                end = mid;
        }
        return end;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n, m;   // n: 나무의 수, m: 필요한 나무 길이
        int[] tree; // 나무들의 높이 배열
        int maxHeight;  // 설정할 절단기 최대 높이
        int longestTree;    // 나무들 중 최대 높이의 나무 높이
        int i;

        // 변수 n, m 초기화
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // tree 배열 초기화
        tree = new int[n];
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < n; i++)
            tree[i] = Integer.parseInt(st.nextToken());

        // 탐색을 위해 가장 긴 나무길이를 구하기 -> 절단기가 갖을 수 있는 최대 높이
        longestTree = -1;
        for (i = 0; i < n; i++) {
            if (longestTree < tree[i])
                longestTree = tree[i];
        }

        // 탐색
        maxHeight = search(tree, longestTree, 1, m) - 1;

        // 출력
        bw.write(String.valueOf(maxHeight));
        bw.flush();
        bw.close();
    }
}