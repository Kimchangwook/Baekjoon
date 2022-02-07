import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 8;

    // 깊이 우선 탐색을 이용
    // 모든 수를 탐색
    // pre == m 이면 prev 출력
    // else 방문하지 않은 다음 수를 탐색
    // 가장 최근에 추가한 prev와 visited의 원소 삭제 후 return;
    public static void dfs(int[] prev, int[] visited, int v, int pre, int n, int m, StringBuilder sb) {
        int i;

        pre++;
        prev[pre] = v;
        visited[v] = 1;

        if (pre == m) {
            for (i = 1; i <= m; i++) {
                sb.append(prev[i]).append(' ');
            }
            sb.append("\n");
        } else {
            for (i = 1; i <= n; i++) {
                if (visited[i] == 0)
                    dfs(prev, visited, i, pre, n, m, sb);
            }
        }

        prev[pre] = 0;
        visited[v] = 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int n, m;   // n: 숫자 크기, m: 선택해야할 횟수
        int pre;    // 현재 선택한 횟수
        int[] prev; // 선택한 수를 담는 배열
        int[] visited;  // 특정 수를 방문했는지 표시하는 배열
        int i;

        // 변수 초기화
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        pre = 0;
        prev = new int[MAX + 1];
        visited = new int[MAX + 1];

        // 탐색
        for (i = 1; i <= n; i++)
            dfs(prev, visited, i, pre, n, m, sb);

        // 출력
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}