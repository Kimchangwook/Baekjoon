#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 100000

typedef struct {
	int start;
	int end;
}Meeting;

int compare(const void* pa, const void* pb) {
	Meeting* a = (Meeting*)pa;
	Meeting* b = (Meeting*)pb;

	if (a->end == b->end)
		return a->start - b->start;
	else
		return a->end - b->end;
}

// 빨리 끝나는 것부터 선택
int greedy(int n, Meeting meetings[]) {
	int cnt = 0;
	int last_end = 0;

	for (int i = 0; i < n; i++) {
		if (meetings[i].start >= last_end) {
			cnt++;
			last_end = meetings[i].end;
		}
	}

	return cnt;
}


int main() {
	int N;	// 회의 수
	Meeting* meetings;
	int result;

	scanf("%d", &N);
	meetings = malloc(sizeof(Meeting) * N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &meetings[i].start, &meetings[i].end);

	// 회의의 끝나는시간의 오름차순 정렬
	qsort(meetings, N, sizeof(Meeting), compare);

	result = greedy(N, meetings);

	printf("%d", result);

	return 0;
}