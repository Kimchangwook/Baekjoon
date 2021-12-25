import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;	//n: 카드 개수, m: 한도
        int cardNumber[];	// 카드에 적힌 수
        int sum, newSum;
        int i, j, k;

        n = sc.nextInt();
        m = sc.nextInt();
        cardNumber = new int[n];
        sum = -1;

        for (i = 0; i < n; i++)
            cardNumber[i] = sc.nextInt();
        
        // 세장의 카드 합 비교
        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    newSum = cardNumber[i] + cardNumber[j] + cardNumber[k];
                    if (newSum > m)
                        continue;
                    else if (sum == -1 || sum < newSum)
                        sum = newSum;
                }
            }
        }

        System.out.println(sum);

    }
}
