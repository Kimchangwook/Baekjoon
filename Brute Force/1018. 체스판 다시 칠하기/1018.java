import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int check(char[][] board, int start_row, int start_col) {
        int count1 = 0;
        int count2 = 0;

        // 체스판의 첫 부분이 화이트로 시작하는 경우
        for (int i = start_row; i < start_row + 8; i++) {
            for (int j = start_col; j < start_col + 8; j++) {
                if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 0 && board[i][j] != 'W')
                    count1++;
                else if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 1 && board[i][j] != 'B')
                    count1++;
                else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 0 && board[i][j] != 'B')
                    count1++;
                else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 1 && board[i][j] != 'W')
                    count1++;
            }
        }

        // 체스판의 첫 부분이 블랙으로 시작하는 경우
        for (int i = start_row; i < start_row + 8; i++) {
            for (int j = start_col; j < start_col + 8; j++) {
                if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 0 && board[i][j] != 'B')
                    count2++;
                else if ((i - start_row) % 2 == 0 && (j - start_col) % 2 == 1 && board[i][j] != 'W')
                    count2++;
                else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 0 && board[i][j] != 'W')
                    count2++;
                else if ((i - start_row) % 2 == 1 && (j - start_col) % 2 == 1 && board[i][j] != 'B')
                    count2++;
            }
        }

        return Math.min(count1, count2);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());   // n: 보드의 세로크기
        int m = Integer.parseInt(st.nextToken());   //m: 가로크기
        char[][] board = new char[n][m];	// 보드 배열
        int count = -1;	// 다시 칠해야 하는 사각형의 개수
        int new_count;	// 기존의 개수와 비교하기 위한 변수
        int i, j;

        // 보드 배열 입력
        for (i = 0; i < n; i++) {
            String s = br.readLine();
            //String s = sc.next();
            for (j = 0; j < m; j++) {
                board[i][j] = s.charAt(j);
            }
        }

        // 다시 칠해야 하는 최소 갯수 count 구하는 코드
        for (i = 0; i <= n - 8; i++) {
            for (j = 0; j <= m - 8; j++) {
                new_count = check(board, i, j);
                if (count == -1) {
                    count = new_count;
                    continue;
                }

                if (count > new_count)
                    count = new_count;
            }
        }

        System.out.println(count);
    }
}
