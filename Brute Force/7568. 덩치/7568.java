import java.util.*;

// 학생들의 덩치의 정보 클래스
class BodySpec {
    private int weight;
    private int height;

    public BodySpec(int weight, int height) {
        this.weight = weight;
        this.height = height;
    }

    public int getWeight() {
        return weight;
    }

    public int getHeight() {
        return height;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();   // 학생들의 수
        int[] rank = new int[n];    // 학생들의 덩치 등수
        BodySpec[] body = new BodySpec[n];  // 학생별 덩치
        int count;
        int i, j;

        // 학생 덩치 입력
        for (i = 0; i < n; i++) {
            body[i] = new BodySpec(sc.nextInt(), sc.nextInt());
        }

        // 학생들의 덩치 등수 구하는 코드
        for (i = 0; i < n; i++) {
            count = 0;
            for (j = 0; j < n; j++) {
                if (body[i].getWeight() < body[j].getWeight() && body[i].getHeight() < body[j].getHeight())
                    count++;
            }
            rank[i] = count + 1;
        }

        // 덩치 등수 출력
        for (i = 0; i < n; i++)
            System.out.printf("%d ", rank[i]);
    }
}
