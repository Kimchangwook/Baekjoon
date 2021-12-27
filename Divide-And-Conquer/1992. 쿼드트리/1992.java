import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static char[] quadtree = new char[10000];	// 영상의 쿼드 트리 
    public static int index = 0;	// quadtree에 값을 넣기 위해 index를 계산을 위한 변수

    // 압축 가능 여부 체크
    private static char check(char[][] video, int startRow, int startCol, int n) {
        char startPoint = video[startRow][startCol];	// 분할된 영상의 첫 점

        for (int i = startRow; i < startRow + n; i++) {
            for (int j = startCol; j < startCol + n; j++) {
                if (startPoint != video[i][j])
                    return '2';	// 압축 불가 -> '2'반환
            }
        }
        return startPoint;	// 압축 가능
    }

    public static void convertToQuadtree(char[][] video, int startRow, int startCol, int n) {
        // 분할 불가능한 크기
        if (n <= 1) {
            quadtree[index++] = video[startRow][startCol];
            return;
        }

        char checkPoint = check(video, startRow, startCol, n);

        //	압축 가능 
        if (checkPoint == '0' || checkPoint == '1') {
            quadtree[index++] = checkPoint;
        }
        // 압축 불가능 -> 분할
        else {
            n /= 2;

            quadtree[index++] = '(';
            convertToQuadtree(video, startRow, startCol, n);
            convertToQuadtree(video, startRow, startCol + n, n);
            convertToQuadtree(video, startRow + n, startCol, n);
            convertToQuadtree(video, startRow + n, startCol + n, n);
            quadtree[index++] = ')';
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());    // 영상 크기
        char[][] video = new char[n][n];    // 영상 배열
        int i, j;

        // 영상 배열 초기화 
        for(i = 0; i < n; i++){
            String s = br.readLine();
            for(j = 0; j < n; j++){
                video[i][j] = s.charAt(j);
            }
        }

        // 영상을 쿼드트리로 압축
        convertToQuadtree(video, 0, 0, n);

        // quadtree 출력
        bw.write(quadtree, 0, index);
        bw.flush();
        bw.close();

    }
}
