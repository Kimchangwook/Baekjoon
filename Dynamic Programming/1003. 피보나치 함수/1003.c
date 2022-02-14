#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �Լ��� �����ϱ� ���� �湮�ߴٴ� ������ �����.
// ���� ���� �ߺ����� �Լ��� ȣ���ϴ� ���� ���� �� �ִ�.
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
    int T;  // �׽�Ʈ ���̽� ����
    int N;  // �Ǻ���ġ ������ index
    int visited[2][41] = { 0, };    // �� n�� 0�� 1�� ��µ� Ƚ�� �迭

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        fibonacci(N, visited);
        printf("%d %d\n", visited[0][N], visited[1][N]);
    }

    return 0;
}