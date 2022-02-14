import java.io.*;
import java.util.*;

public class Main{
    // 함수가 종료하기 전에 방문했다는 흔적을 남긴다.
    // 다음 번에 중복으로 함수를 호출하는 것을 피할 수 있다.
    public static void fibonacci(int n, int visited[][]) {
        if (n == 0) {
            //printf("0");
            visited[0][0] = 1;
        }
        else if (n == 1) {
            //printf("1");
            visited[1][1] = 1;
        }
        else {
            if (visited[0][n - 1] == 0 && visited[1][n - 1] == 0)
                fibonacci(n - 1, visited);
            if (visited[0][n - 2] == 0 && visited[1][n - 2] == 0)
                fibonacci(n - 2, visited);

            visited[0][n] = visited[0][n - 1] + visited[0][n - 2];
            visited[1][n] = visited[1][n - 1] + visited[1][n - 2];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int T;  // 테스트 케이스의 개수
        int N;  // 수열의 크기
        int[][] visited;    // 각 n별 0과 1의 출력된 횟수 배열

        T =Integer.parseInt(br.readLine());
        visited = new int[2][41];

        for(int i = 0; i < T; i++){
            N = Integer.parseInt(br.readLine());
            fibonacci(N, visited);
            sb.append(visited[0][N] + " " + visited[1][N] + "\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}