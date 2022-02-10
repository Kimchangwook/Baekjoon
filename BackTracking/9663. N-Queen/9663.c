#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 15

// 체크
// 더 낮은 depth의 row, 대각선 체크
// *대각선 체크가 핵심*
// (x, y), (i, j) 두 좌표가 대각선상에 존재한다면 
// |x - i| == |y - j| 임을 이용
int check(int depth, int location_of_queen[]) {
	for (int i = 1; i < depth; i++) {
		if (location_of_queen[depth] == location_of_queen[i] || abs(location_of_queen[depth] - location_of_queen[i]) == depth - i)
			return 0;
	}
	return 1;
}

// 탐색
// queen 배치 -> 적합성 체크 -> 적합하면 다음 함수 호출/ 아니면 다음 col 체크
int search(int depth, int N, int location_of_queen[]) {
	if (depth > N) return 1;

	int count = 0;

	for (int i = 1; i <= N; i++) {
		location_of_queen[depth] = i;

		if (check(depth, location_of_queen)) {
			count += search(depth + 1, N, location_of_queen);
		}
	}

	return count;
}

int main() {
	int N;
	int location_of_queen[MAX + 1];	// queen들의 col위치
	int depth = 0;	// queen을 놓은 개수?
	int count = 0;	// 구해야하는 경우의 수

	scanf("%d", &N);

	//탐색
	count = search(depth + 1, N, location_of_queen);

	printf("%d", count);

	return 0;
}