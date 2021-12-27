import java.io.*;
import java.util.StringTokenizer;

public class Main {
    // 제곱을 계산하기 위한 함수
    public static int squared(int a, int b, int c) {
        if (b <= 1)
            return a % c;

        long result;    // 계산 과정에서 오버플로우 발생할 수 있으므로 long으로 선언

        // 지수가 짝수인 경우
        if (b % 2 == 0) {
            b /= 2;
            result = squared(a, b, c);
            return (int) ((result * result) % c);
        }
        // 지수가 홀수인 경우
        else {
            b /= 2;
            result = squared(a, b, c);
            return (int) ((((result * result) % c) * (a % c)) % c);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());   // a를 b번 곱한 수에 c로 나눈 나머지를 구한다.
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int result;

        result = squared(a, b, c);  //계산 후 결과

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
        br.close();
    }
}
