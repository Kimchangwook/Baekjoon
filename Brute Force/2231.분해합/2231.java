import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ctor = 0;   // 생성자
        int digit = 0;  // n의 자릿수
        int clone = 0;

        // digit 구하는 반복문
        while (n / Math.pow(10.0, digit) >= 10)
            digit++;
        digit++;

        for (int i = n - digit * 9; i <= n; i++) {
            clone = i;
            ctor = i;

            while (ctor != 0) {
                clone += ctor % 10;
                ctor /= 10;
            }

            if (clone == n) {
                ctor = i;
                break;
            }
        }

        if (clone == n)
            System.out.println(ctor);
        else
            System.out.println(0);

    }
}
