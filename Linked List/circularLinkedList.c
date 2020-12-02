#include <stdio.h>
#include <malloc.h>

// STRUCT
typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
} List;

// OPERATIONS
void insertAtBeginning(int value, List *list); // DONE
void insertAtEnd(int value, List *list);
void insertAtPosition(int value, int pos, List *list);
void removeAtBeginning(List *list);
void removeAtEnd(List *list);
void removeAtPosition(int pos, List *list);
int isEmpty(List *list);
int getSize(List *list);
Node *createNode(int value);
Node *getNodePosition(int pos, List *list);

int main(void) {
	List *list = malloc(sizeof(list));
	insertAtBeginning(10, list);

	printf("Size: %d\n", getSize(list));
	printf("%d\n", list->head->next->next->value);
}

// LIST OPERATIONS
int isEmpty(List *list) {
	if (!list->head) { return 1; }
	return 0;
}

int getSize(List *list) {
	if (isEmpty(list)) { return 0; }
	int size = 0;
	Node *head = list->head;
	while (head->next != list->head) {
		head = head->next;
		size++;
	}
	return size + 1;
}

int isOutOfIndex(int pos, List *list) {
	if ((pos < 0) || (pos >= getSize(list))) {
		printf("Out of index\n");
		return 1;
	}
	return 0;
}

// NODE OPERATIONS
Node *createNode(int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	return newNode;
}

Node *getNodePosition(int pos, List *list) {
	if (isEmpty(list)) { return NULL; }

}

// INSERT OPERATIONS
void insertAtBeginning(int value, List *list) {
	Node *newNode = createNode(value);
	if (isEmpty(list)) {
		list->head = newNode;
		newNode->next = list->head;
		return;
	}
}

void insertAtEnd(int value, List *list) {
	Node *newNode = createNode(value);
	if (isEmpty(list)) {
		list->head = newNode;
		newNode->next = list->head;
		return;
	}
}