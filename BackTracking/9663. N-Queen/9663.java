import java.io.*;

public class Main{
    // 체크
    // 더 낮은 depth의 row, 대각선 체크
    // *대각선 체크가 핵심*
    // (x, y), (i, j) 두 좌표가 대각선상에 존재한다면
    // |x - i| == |y - j| 임을 이용
    private static boolean check(int depth, int[] list){
        for(int i = 1; i < depth; i++){
            if(list[depth] == list[i] || Math.abs(list[depth] - list[i]) == depth - i)
                return false;
        }
        return true;
    }

    // 탐색
    // queen 배치 -> 적합성 체크 -> 적합하면 다음 함수 호출/ 아니면 다음 col 체크
    public static int search(int depth, int N, int[] list){
        if(depth > N) return 1;

        int count = 0;

        for(int i = 1; i <= N; i++){
            list[depth] = i;

            if(check(depth, list))
                count += search(depth+1, N, list);
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        int[] locationOfQueen;
        int depth;
        int count;

        N = Integer.parseInt(br.readLine());
        locationOfQueen = new int[N + 1];
        depth = 0;
        count = 0;

        // 탐색
        count = search(depth+1, N, locationOfQueen);

        bw.write(String.valueOf(count));
        bw.flush();
        bw.close();
    }
}