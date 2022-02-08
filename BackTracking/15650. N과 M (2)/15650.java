import java.io.*;
import java.util.*;

public class Main {
    public static final int MAX = 8;

    // DFS를 이용
    // data보다 큰 원소들만 탐색
    // depth == M 일경우 탐색 멈추고 결과 출력
    // 이전 함수로 되돌아 간 후 다음 수 탐색
    public static void DFS(int[] result, int depth, int data, int N, int M, StringBuilder sb) {
        result[depth] = data;

        if (depth == M) {
            for (int i = 1; i <= M; i++)
                sb.append(result[i] + " ");
            sb.append("\n");
        } else {
            for (int i = data + 1; i <= N; i++)
                DFS(result, depth + 1, i, N, M, sb);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        StringBuilder sb;

        int N, M;   // N: 수의 크기, M: 선택해야하는 수의 개수
        int depth;  // 탐색의 깊이 -> 선택한 수의 개수
        int[] result;   // 선택한 수를 저장
        int i;

        // 변수 초기화
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        depth = 0;
        result = new int[MAX + 1];
        sb = new StringBuilder();

        // 탐색
        for (i = 1; i <= N; i++)
            DFS(result, depth + 1, i, N, M, sb);

        // 츌력
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}