#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 함수가 종료하기 전에 방문했다는 흔적을 남긴다.
// 다음 번에 중복으로 함수를 호출하는 것을 피할 수 있다.
void fibonacci(int n, int visited[][41]) {
    if (n == 0) {
        //printf("0");
        visited[0][0] = 1;
    }
    else if (n == 1) {
        //printf("1");
        visited[1][1] = 1;
    }
    else {
        if (visited[0][n - 1] == 0 || visited[1][n - 1] == 0)
            fibonacci(n - 1, visited);
        if (visited[0][n - 2] == 0 || visited[1][n - 2] == 0)
            fibonacci(n - 2, visited);

        visited[0][n] = visited[0][n - 1] + visited[0][n - 2];
        visited[1][n] = visited[1][n - 1] + visited[1][n - 2];
    }
}

int main() {
    int T;  // 테스트 케이스 개수
    int N;  // 피보나치 수열의 index
    int visited[2][41] = { 0, };    // 각 n별 0과 1의 출력된 횟수 배열

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        fibonacci(N, visited);
        printf("%d %d\n", visited[0][N], visited[1][N]);
    }

    return 0;
}