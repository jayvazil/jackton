#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
typedef struct
{
	int items[MAX];
	int top;
} Stack;
void initStack(Stack* s)
{
	s->top = -1;
}
bool isEmpty(Stack* s)
{
	return s->top == -1;
}
bool isFull(Stack* s)
{
	return s->top == MAX - 1;
}
void push(Stack* s, int item)
{
	if (!isFull(s))
	{
		s->items[++s->top] = item;
	}
	else
	{
		printf("Stack overflow\n");
	}
}
int pop(Stack* s)
{
	if (!isEmpty(s))
	{
		return s->items[s->top--];
	}
	printf("Stack underflow\n");
	return -1;
}
void buildArrayWithStack(int* elements, int size, int* result)
{
	Stack s;
	initStack(&s);
	for (int i = 0; i < size; i++)
	{
		push(&s, elements[i]);
	}
	for (int i = 0; i < size; i++)
	{
		result[i] = pop(&s);
	}
}

int main()
{
	int elements[] = {1, 2, 3, 4, 5};
	int size = sizeof(elements) / sizeof(elements[0]);
	int result[size];

	buildArrayWithStack(elements, size, result);

	printf("Resulting array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}
