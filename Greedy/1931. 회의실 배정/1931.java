import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    // 빨리 끝나는 것부터 선택
    public static int greedy(int n, int[][] meetings){
        int count = 0;
        int lastEnd = 0;

        for(int i = 0; i < n; i++){
            if(meetings[i][0] >= lastEnd){
                count++;
                lastEnd = meetings[i][1];
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N;  // 회의 수
        int[][] meetings;   // 회의 시간 배열
        int result;

        N = Integer.parseInt(br.readLine());
        meetings = new int[N][2];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            meetings[i][0] = Integer.parseInt(st.nextToken());
            meetings[i][1] = Integer.parseInt(st.nextToken());
        }

        // 회의의 끝나는시간의 오름차순 정렬
        Arrays.sort(meetings, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] == o2[1])
                    return o1[0] - o2[0];
                else
                    return o1[1] - o2[1];
            }
        });

        result = greedy(N, meetings);

        System.out.println(result);
    }
}