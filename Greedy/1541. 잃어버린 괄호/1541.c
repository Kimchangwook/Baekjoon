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

// ���� ����� ��ȣ�� ������ ��� �ּ��� ����� ����
// ���� ���ÿ� �ϳ��� �ְ� 
// ������ ��� ������ ����� ���ÿ� push
// ���ÿ��� ���� �� ���鸸 ���Եȴ�.
// ������ ù ��Ҵ� ������� �Ѵ�.
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
	char fomula[MAXIMUM];	// ��
	int result;

	scanf("%s", fomula);

	result = calc(fomula);

	printf("%d", result);

	return 0;
}