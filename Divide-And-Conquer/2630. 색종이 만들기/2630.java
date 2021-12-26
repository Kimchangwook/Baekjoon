import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int white = 0;    // num of white paper
    public static int blue = 0;    // num of blue paper

    // 색종이가 만들어 지는지 확인하는 함수
    public static int check(int[][] paper, int start_row, int start_col, int n) {
        int i, j;
        int start_num = paper[start_row][start_col]; // 종이의 첫번째 색

        for (i = start_row; i < start_row + n; i++) {
            for (j = start_col; j < start_col + n; j++) {
                if (start_num != paper[i][j])
                    return -1;    // 색종이가 안만들어지므로 -1 반환
            }
        }
        return start_num;    // 색종이의 색 반환
    }


    // 종이 분할
    public static void cut_paper(int[][] paper, int start_row, int start_col, int n) {
        // 더이상 쪼갤수 없는 크기
        if (n <= 1 && paper[start_row][start_col] == 0) {
            white++;
            return;
        }
        else if (n <= 1 && paper[start_row][start_col] == 1) {
            blue++;
            return;
        }

        // 색종이가 무슨색으로 만들어 지는지의 종류, -1: 색종이x, 0: 화이트, 1: 블루
        int check_point = check(paper, start_row, start_col, n);

        if (check_point == 0) {    // 화이트 색종이
            white++;
            return;
        }
        else if (check_point == 1) {    // 블루 색종이
            blue++;
            return;
        }
        else {    // 색종이가 안만들어 지는 경우 -> 분할
            n /= 2;
            cut_paper(paper, start_row, start_col, n);
            cut_paper(paper, start_row, start_col + n, n);
            cut_paper(paper, start_row + n, start_col, n);
            cut_paper(paper, start_row + n, start_col + n, n);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());    // 전체 종이의 크기
        int[][] paper = new int[n][n];  // 전체 종이 배열
        int i, j;

        // 종이 배열 입력 및 초기화
        for (i = 0; i < n; i++) {
            String s = br.readLine();
            st = new StringTokenizer(s);
            for (j = 0; j < n; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 종이 분할
        cut_paper(paper, 0, 0, n);

        // 색별 색종이 개수 출력
        System.out.println(white);
        System.out.println(blue);

    }
}
