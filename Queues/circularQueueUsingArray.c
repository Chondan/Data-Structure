#include <stdio.h>
#include <malloc.h>

// STRUCT
typedef struct Queue {
	int front;
	int rear;
	int maxSize;
	int *arr;
} Queue;

// OPERATIONS
Queue *createQueue(int size); // DONE
void enqueue(int value, Queue *queue); // DONE
void dequeue(Queue *queue); // DONE
void peek(Queue *queue);  
int isEmpty(Queue *queue); // DONE
int isFull(Queue *queue); // DONE 
void display(Queue *queue); // DONE
int getSize(Queue *queue); // DONE

int main(void) {
	Queue *queue = createQueue(10);
	int choice, value;
	while (1) {
		printf("\n\n----- MENU -----\n");
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n");
		printf("4. Display\n5. Size\n");

		printf("\033[1;34m");
		printf("Select choice -> ");
		scanf("%d", &choice);
		printf("\033[0m");
		if ((choice < 1) || (choice > 5)) { continue; }
		printf("\033[1;32m");
		switch (choice) {
			case 1:
				printf("Enqueue\n");
				printf("Input value: ");
				scanf("%d", &value);
				enqueue(value, queue);
				break;
			case 2:
				printf("\033[1;33m");
				printf("Dequeue\n");
				dequeue(queue);
				break;
			case 3:
				printf("Peek\n");
				peek(queue);
				break;
			case 4: 
				printf("Display\n");
				display(queue);
				break;
			case 5:
				printf("Size\n");
				printf("The size of queue is %d.\n", getSize(queue));
				break;
			default:
				break;
		}
		printf("End\n");
		printf("\033[0m");
	}
	free(queue);
}

// QUEUE OPERATIONS
Queue *createQueue(int size) {
	Queue *queue = malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	queue->maxSize = size;
	queue->arr = malloc(sizeof(int) * size);
	return queue;
}

int isEmpty(Queue *queue) {
	if ((queue->front == -1) && (queue->rear == -1)) { return 1; }
	return 0;
}

int isFull(Queue *queue) {
	if (queue->rear == queue->maxSize - 1) {
		if (queue->front == 0) {
			return 1;
		}
		return 0;
	} else {
		if (queue->rear + 1 == queue->front) {
			return 1;
		}
		return 0;
	}
}

int getSize(Queue *queue) {
	int start;
	if (isEmpty(queue)) { return 0; }
	if (isFull(queue)) { return queue->maxSize; }
	if (queue->front < queue->rear) {
		return queue->rear - queue->front + 1;
	}
	return (queue->maxSize - queue->front + 1) + (queue->rear + 1);
}

void display(Queue *queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
	}
	int start = queue->front;
	int index = 0;
	printf("----- QUEUES -----\n");
	while (1) {
		if (start == queue->rear) {
			break;
		}
		printf("%d: %d\n",index, queue->arr[start]);
		start++;
		index++;
		if (start == queue->maxSize) {
			start = 0;
		}
	}
	printf("%d: %d\n",index, queue->arr[start]);
	printf("------------------\n");
}

void enqueue(int value, Queue *queue) {
	if (isFull(queue)) {
		printf("The queue is full.\n");
		return;
	}
	if (isEmpty(queue)) {
		queue->front++;
		queue->rear++;
		queue->arr[queue->front] = value;
		return;
	}
	if (queue->rear == queue->maxSize - 1) {
		queue->rear = 0;
		queue->arr[queue->rear] = value;
		return;
	}
	queue->rear++;
	queue->arr[queue->rear] = value;
}

void dequeue(Queue *queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
		return;
	}
	int temp = queue->arr[queue->front];
	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else if (queue->front == queue->maxSize - 1) {
		queue->front = 0;
	} else {
		queue->front++;
	}
	printf("Removed %d from the queue.\n", temp);
}

void peek(Queue *queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
		return;
	}
	printf("The first queue is %d.\n", queue->arr[queue->front]);
}