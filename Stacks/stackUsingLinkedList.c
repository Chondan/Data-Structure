#include <stdio.h>
#include <malloc.h>

// STRUCT
typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *top;
} Stack;

// OPERATIONS
void push(int value, Stack *stack); // DONE
void pop(Stack *stack); // DONE
void peek(Stack *stack); // DONE
void display(Stack *stack); // DONE
Node *createNode(int value); // DONE
int isEmpty(Stack *stack); // DONE
int getSize(Stack *stack); // DONE

int main(void) {
	Stack *stack = malloc(sizeof(Stack));
	int choice, value, pos;
	while (1) {
		printf("\n\n----- MENU -----\n");
		printf("1. Push\n2. Pop\n3. Peek\n");
		printf("4. Display\n5. Size\n");

		printf("\033[1;34m");
		printf("Select choice -> ");
		scanf("%d", &choice);
		printf("\033[0m");
		if ((choice < 1) || (choice > 5)) { continue; }
		printf("\033[1;32m");
		switch (choice) {
			case 1:
				printf("Push\n");
				printf("Input value: ");
				scanf("%d", &value);
				push(value, stack);
				break;
			case 2:
				printf("\033[1;33m");
				printf("Pop\n");
				pop(stack);
				break;
			case 3:
				printf("Peek\n");
				peek(stack);
				break;
			case 4: 
				printf("Display\n");
				display(stack);
				break;
			case 5:
				printf("Size\n");
				printf("The size of stack is %d.\n", getSize(stack));
				break;
			default:
				break;
		}
		printf("End\n");
		printf("\033[0m");
	}
	free(stack);
}

// STACK OPERATIONS
int isEmpty(Stack *stack) {
	if (!stack->top) { return 1; }
	return 0;
}

int getSize(Stack *stack) {
	if (isEmpty(stack)) { return 0; }
	int size = 0;
	Node *top = stack->top;
	while (top->next) {
		size++;
		top = top->next;
	}
	return size + 1;
}

void display(Stack *stack) {
	if (getSize(stack) == 0) {
		printf("The stack is empty.\n");
		return;
	}
	Node *top = stack->top;
	printf("----- STACK -----\n");
	printf("TOP\n");
	while (top->next) {
		printf("%d\n", top->value);
		top = top->next;
	}
	printf("%d\n", top->value);
	printf("-----------------\n");
}

// NODE OPERATIONS
Node *createNode(int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	return newNode;
}

// DATA OPERATIONS
void push(int value, Stack *stack) {
	Node *newNode = createNode(value);
	if (isEmpty(stack)) {
		stack->top = newNode;
		return;
	}
	Node *top = stack->top;
	newNode->next = top;
	stack->top = newNode;
}

void peek(Stack *stack) {
	if (isEmpty(stack)) {
		printf("The stack is empty.\n");
		return;
	}
	printf("The top element is %d.\n", stack->top->value);
}

void pop(Stack *stack) {
	if (isEmpty(stack)) {
		printf("The stack is empty.\n");
		return;
	}
	Node *top = stack->top;
	stack->top = top->next;
	printf("Popped %d out of the stack.\n", top->value);
	free(top);
}