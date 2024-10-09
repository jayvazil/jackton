#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* data;
	int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->data = (int*) malloc(capacity * sizeof(int));
	return queue;
}

int isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

void enqueue(Queue* queue, int item)
{
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->data[queue->rear] = item;
	queue->size++;
}

int dequeue(Queue* queue)
{
	int item = queue->data[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}
typedef struct
{
	Queue* q1;
	Queue* q2;
} MyStack;

MyStack* myStackCreate()
{
	MyStack* stack = (MyStack*) malloc(sizeof(MyStack));
	stack->q1 = createQueue(100);
	stack->q2 = createQueue(100);
	return stack;
}

void myStackPush(MyStack* obj, int x)
{
	enqueue(obj->q2, x);
	while (!isEmpty(obj->q1))
	{
		enqueue(obj->q2, dequeue(obj->q1));
	}
	Queue* temp = obj->q1;
	obj->q1 = obj->q2;
	obj->q2 = temp;
}

int myStackPop(MyStack* obj)
{
	return dequeue(obj->q1);
}

int myStackTop(MyStack* obj)
{
	return obj->q1->data[obj->q1->front];
}

int myStackEmpty(MyStack* obj)
{
	return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj)
{
	free(obj->q1->data);
	free(obj->q2->data);
	free(obj->q1);
	free(obj->q2);
	free(obj);
}

int main()
{
	MyStack* stack = myStackCreate();
	myStackPush(stack, 10);
	myStackPush(stack, 20);
	printf("Top element: %d\n", myStackTop(stack));  // Output: 20
	printf("Popped element: %d\n", myStackPop(stack));  // Output: 20
	printf("Top element: %d\n", myStackTop(stack));  // Output: 10
	printf("Is stack empty? %d\n", myStackEmpty(stack));  // Output: 0 (false)
	myStackFree(stack);
	return 0;
}
