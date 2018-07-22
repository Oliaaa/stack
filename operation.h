#pragma once
#pragma once
#include <stdio.h>

struct stack
{
	int data;
	stack *next;
};

void create(stack** st)
{
	*st = NULL;
}

int empty(stack* st)						//�������� �� �������
{
	if (!st)
		return 0;
	else
		return 1;
}

stack * pushdstack(char x, stack *st)			//�������� � ����
{
	stack * r;
	r = new stack;
	r->data = x;
	r->next = st;
	return r;
}
int popdstack(char * x, stack **st)			//����� �� �����
{
	stack * r;
	if (*st)
	{
		r = *st;
		*x = (*st)->data;
		*st = (*st)->next;
		delete r;
		return 1;
	}
	return 0;
}

stack* printSt(stack* st)				//�������� ���������� �����
{
	char x;

	if (empty(st))
	{
		stack* temp;
		create(&temp);

		while (empty(st))
		{
			popdstack(&x, &st);
			printf("%c", x);
			temp = pushdstack(x, temp);
		}

		while (empty(st))
		{
			popdstack(&x, &st);
			temp = pushdstack(x, temp);
		}
	}

	return st;
}