import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    // 빨리 끝나는 것부터 선택
    public static int greedy(int n, int[] times){
        int sum  = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                sum += times[j];
            }
        }

        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N;  // num of people
        int[] times;    // times arrays per person
        int result;

        N = Integer.parseInt(br.readLine());
        times = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            times[i] = Integer.parseInt(st.nextToken());

        // 시간이 적게 걸리는 순으로 정렬
        Arrays.sort(times);

        result = greedy(N, times);

        System.out.println(result);
    }
}