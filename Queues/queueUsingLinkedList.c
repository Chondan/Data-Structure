#include <stdio.h>
#include <malloc.h>

// STRUCT
typedef struct Node {
	int value;
	struct Node *next;
} Node;
// lastNode->next = NULL

typedef struct Queue {
	Node *front;
	Node *rear;
} Queue;

// OPERATION
void enqueue(int value, Queue *queue); // DONE
void dequeue(Queue *queue); // DONE
void peek(Queue *queue); // DONE
void display(Queue *queue); // DONE
Node *createNode(int value); // DONE
int isEmpty(Queue *queue); // DONE
int getSize(Queue *queue);

int main(void) {
	Queue *queue = malloc(sizeof(Queue));
	int choice, value, pos;
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
int isEmpty(Queue *queue) {
	if ((queue->front == NULL) && (queue->rear == NULL)) { return 1; }
	return 0;
}

void enqueue(int value, Queue *queue) {
	Node *newNode = createNode(value);
	if (isEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
		printf("Inserted %d into the queue.\n", value);
		return;
	}
	Node *lastNode = queue->rear;
	lastNode->next = newNode;
	queue->rear = newNode;
	printf("Inserted %d into the queue.\n", value);
}

void dequeue(Queue *queue) {
	if (isEmpty(queue)) { 
		printf("The queue is empty.\n");
		return;
	}
	Node *front = queue->front;
	Node *newFront = front->next;
	queue->front = newFront;
	if (!newFront) {
		queue->rear = NULL;
	}
	printf("Removed %d from the queue.\n", front->value);
	free(front);
}

void peek(Queue *queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
		return;
	}
	printf("The frist queus if %d.\n", queue->front->value);
}

void display(Queue *queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty.\n");
		return;
	}
	Node *front = queue->front;
	int index = 0;
	printf("----- QUEUES -----\n");
	while (front->next) {
		printf("%d: %d\n", index, front->value);
		front = front->next;
		index++;
	}
	index;
	printf("%d: %d\n", index, front->value);
	printf("------------------\n");
}

int getSize(Queue *queue) {
	if (isEmpty(queue)) {
		return 0;
	}
	Node *front = queue->front;
	int size = 0;
	while (front->next) {
		front = front->next;
		size++;
	}
	return size + 1;
}

// NODE OPERATIONS
Node *createNode(int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	return newNode;
}

