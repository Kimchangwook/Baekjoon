import java.io.*;
import java.util.*;

public class Main {

    // 매개 변수 탐색을 위한 결정 함수
    // 기준점 공유기로 부터 주어진 간격보다 크거나 같으면
    // 공유기를 설치하고 기준점 이동, count++
    private static int decision(int[] list, int distance, int c) {
        int count = 1;  // 첫 번째 집은 공유기를 무조건 설치한다 가정
        int start = list[0];    // 다음 공유기 설치를 위한 기준점
        int i;

        for (i = 0; i < list.length; i++) {
            if (list[i] - start >= distance) {
                count++;
                start = list[i];
            }
        }

        if (count >= c)
            return 1;
        else
            return 0;
    }

    // 탐색 ( upper bound )
    // t -> f로 바뀌는 상한선을 탐색
    public static int search(int searchSize, int[] list, int c) {
        int start = 1;
        int end = searchSize + 1;
        int mid;

        while (start < end) {
            mid = (start + end) / 2;

            if (decision(list, mid, c) == 1)
                start = mid + 1;
            else
                end = mid;
        }

        return end;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n, c;   // n: 집의 개수, c: 공유기 개수
        int[] locationOfHouse;  // 집들의 위치 배열
        int maxDistance;    // 가장 인접한 공유기가 갖을 수 있는 최대 간격
        int i;

        // 변수 초기화
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        locationOfHouse = new int[n];
        for (i = 0; i < n; i++)
            locationOfHouse[i] = Integer.parseInt(br.readLine());

        // 공유기간 갖을 수 있는 최대 간격 구하기 위한 정렬
        Arrays.sort(locationOfHouse);

        // 탐색
        maxDistance = search(locationOfHouse[n - 1] - locationOfHouse[0], locationOfHouse, c) - 1;

        // 출력
        bw.write(String.valueOf(maxDistance));
        bw.flush();
        bw.close();
    }
}