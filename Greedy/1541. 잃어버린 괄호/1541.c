#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 51

typedef struct {
	int top;
	int list[MAXIMUM];
}Stack;

void init(Stack* s) {
	s->top = -1;
}

void push(Stack* s, int item) {
	if (s->top == MAXIMUM - 1)
		return;
	else 
		s->list[++(s->top)] = item;
}

int pop(Stack* s) {
	if (s->top == -1)
		return NULL;
	else
		return s->list[s->top--];
}

int peek(Stack* s) {
	if (s->top == -1)
		return NULL;

	return s->list[s->top];
}

// 덧셈 계산을 괄호로 묶어줄 경우 최소의 결과값 도출
// 수를 스택에 하나씩 넣고 
// 덧셈일 경우 덧셈의 결과를 스택에 push
// 스택에는 빼야 할 수들만 남게된다.
// 스택의 첫 요소는 더해줘야 한다.
int calc(char s[]) {
	int ntmp;
	Stack stack;

	init(&stack);

	push(&stack, atoi(s));
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '+') {
			ntmp = pop(&stack);
			ntmp += atoi(s + i + 1);
			push(&stack, ntmp);
		}
		else if (s[i] == '-') {
			push(&stack, atoi(s + i + 1));
		}
	}

	ntmp = 0;
	while (stack.top != 0) {
		ntmp += pop(&stack);
	}
	ntmp = -ntmp + pop(&stack);
		
	return ntmp;
}

int main() {
	char fomula[MAXIMUM];	// 식
	int result;

	scanf("%s", fomula);

	result = calc(fomula);

	printf("%d", result);

	return 0;
}