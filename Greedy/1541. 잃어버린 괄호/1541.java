import java.io.*;
import java.util.*;

public class Main {
    // 덧셈 계산을 괄호로 묶어줄 경우 최소의 결과값 도출
    // 수를 스택에 하나씩 넣고
    // 덧셈일 경우 덧셈의 결과를 스택에 push
    // 스택에는 빼야 할 수들만 남게된다.
    // 스택의 첫 요소는 더해줘야 한다.
    public static int calc(String s) {
        Stack<Integer> stack = new Stack<>();
        StringBuilder sb;
        int n1 = 0;
        int n2 = 0;
        int tmp = 0;
        char operator = '-';

        sb= new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                n2 = Integer.parseInt(sb.toString());
                sb = new StringBuilder();

                if (operator == '+') {
                    n1 = stack.pop();
                    stack.push(n1 + n2);
                } else if (operator == '-') {
                    stack.push(n2);
                }
                operator = s.charAt(i);
            } else
                sb.append(s.charAt(i));
        }
        n2 = Integer.parseInt(sb.toString());

        if (operator == '+') {
            n1 = stack.pop();
            stack.push(n1 + n2);
        } else if (operator == '-') {
            stack.push(n2);
        }

        int size = stack.size();
        for (int i = 0; i < size-1; i++) {
            tmp += stack.pop();
        }
        tmp = -tmp + stack.pop();

        return tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String fomula;
        int result;

        fomula = br.readLine();

        result = calc(fomula);

        System.out.println(result);
    }
}