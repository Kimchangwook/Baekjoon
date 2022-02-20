#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
#define MIN(x, y) (((x) < (y))?(x):(y))
#define MIN_(x, y, z) (((((x)<(y))?(x):(y))<(z))?((((x)<(y))?(x):(y))):(z))

typedef struct {
	int red;
	int green;
	int blue;
}Cost;

Cost painted_cost[MAX];

// 뒤에서 부터 최솟값을 계산 
// r -> r + min(g, b)
// g -> g + min(r, b)
// b -> b + min(r, g)
int cost(int depth, int N) {
	if (depth == N)
		return;
	
	cost(depth + 1, N);

	painted_cost[depth].red += MIN(painted_cost[depth + 1].green, painted_cost[depth + 1].blue);
	painted_cost[depth].green += MIN(painted_cost[depth + 1].red, painted_cost[depth + 1].blue);
	painted_cost[depth].blue += MIN(painted_cost[depth + 1].red, painted_cost[depth + 1].green);
	
	if (depth == 0)
		return MIN_(painted_cost[depth + 1].red, painted_cost[depth + 1].green, painted_cost[depth + 1].blue);
}

int main() {
	int N;
	int result = 0;
	int i;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &(painted_cost[i].red), &(painted_cost[i].green), &(painted_cost[i].blue));
	}

	result = cost(0, N);

	printf("%d", result);

	return 0;
}