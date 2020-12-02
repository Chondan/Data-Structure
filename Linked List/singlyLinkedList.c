#include <stdio.h>
#include <malloc.h>

// Struct
typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
} List;

// Operations
void insertAtBeginning(int value, List *list); // DONE
void insertAtEnd(int value, List *list); // DONE
void insertPosition(int value, int pos, List *list); // DONE
void removeBeginning(List *list); // DONE
void removeEnd(List *list); // DONW
void removePosition(int pos, List *list); // DONE
int isEmpty(List *list); // DONE
int isOutOfIndex(int pos, List *list); // DONE
Node *createNode(int value); // DONE
Node *getLastNode(List *list); // DONE
Node *getNodePosition(int post, List *list); // DONE
int getSize(List *list); // DONE
void showList(List *list); // DONE

// PROGRAM
int main(void) {
	List *list = malloc(sizeof(List));
	int choice, value, pos;
	while (1) {
		printf("\n\n----- MENU -----\n");
		printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
		printf("4. Remove at beginning\n5. Remove at end\n6. Remove at position\n");
		printf("7. Get value at position\n8. Get size of the linkedlist\n9. Display\n\n\n");

		printf("\033[1;34m");
		printf("Select choice -> ");
		scanf("%d", &choice);
		printf("\033[0m");
		if ((choice < 1) || (choice > 9)) { continue; }
		printf("\033[1;32m");
		switch (choice) {
			case 1:
				printf("Insert at beginning\n");
				printf("Input value: ");
				scanf("%d", &value);
				insertAtBeginning(value, list);
				break;
			case 2:
				printf("Insert at end\n");
				printf("Input value: ");
				scanf("%d", &value);
				insertAtEnd(value, list);
				break;
			case 3:
				printf("Insert at position\n");
				printf("Input value: ");
				scanf("%d", &value);
				printf("Input pos (from %d to %d): ", 0, getSize(list));
				scanf("%d", &pos);
				insertPosition(value, pos, list);
				break;
			case 4: 
				printf("\033[1;33m");
				printf("Remove at beginning\n");
				removeBeginning(list);
				break;
			case 5:
				printf("\033[1;33m");
				printf("Remove at end\n");
				removeEnd(list);
				break;
			case 6:
				printf("\033[1;33m");
				printf("Remove at position\n");
				printf("Input position (from %d to %d): ", 0, getSize(list) - 1);
				scanf("%d", &pos);
				removePosition(pos, list);
				break;
			case 7:
			    printf("Get the value at position\n");
				if (isEmpty(list)) {
					printf("The linkedlist is empty\n");
					break;
				}
				printf("Input position (from %d to %d): ", 0, getSize(list) - 1);
			    scanf("%d", &pos);
			    Node *x = getNodePosition(pos, list);
			    if (!x) { 
			    	printf("No value at this position\n");
			    	break;
			    }
			    printf("The value at position %d: %d\n", pos, x->value);
			    break;
			case 8:
				printf("Get size of linkedlist\n");
				printf("Size of linkedlist is %d\n", getSize(list));
				break;
			case 9:
				showList(list);
				break;
			default:
				break;
		}
		printf("End\n");
		printf("\033[0m");
	}
	free(list);
}

// LIST OPERATION
int isEmpty(List *list) {
	if (!list->head) { return 1; }
	return 0;
}

int isOutOfIndex(int pos, List *list) {
	int size = getSize(list);
	if ((pos < 0) || (pos >= size)) {
		printf("Out of index.\n");
		return 1;
	}
	return 0;
}

int getSize(List *list) {
	int size = 0;
	Node *head = list->head;
	if (head == NULL) return 0;
	while (head->next) {
		head = head->next;
		size++;
	}
	return size + 1;
}

void showList(List *list) {
	if (isEmpty(list)) {
		printf("The linkedlist is empty.\n");
		return;
	}
	Node *head = list->head;
	int index = 0;
	printf("-----LINKED LIST-----\n");
	while(head->next) {
		printf("%d: %d\n", index, head->value);
		head = head->next;
		index++;
	}
	printf("%d: %d\n",index, head->value);
	printf("---------------------\n");
}

// NODE OPERAION
Node *createNode(int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	return newNode;
}

Node *getLastNode(List *list) {
	if (isEmpty(list)) {
		return NULL;
	}
	Node *head = list->head;
	while(head->next) {
		head = head->next;
	}
	return head;
}

Node *getNodePosition(int pos, List *list) {
	int size = getSize(list);
	if (isOutOfIndex(pos, list)) { return NULL; }
	if (isEmpty(list)) { return NULL; }
	int start = 0;
	Node *head = list->head;
	while(head->next) {
		if (start == pos) {
			break;
		}
		start++;
		head = head->next;
	}
	return head;
}

// INSERT OPERATIONS
void insertAtBeginning(int value, List *list) {
	Node *head = list->head;
	Node *newNode = createNode(value);
	// Inserting the first element
	if (isEmpty(list)) {
		list->head = newNode;
		return;
	} 
	Node *temp = head;
	list->head = newNode;
	newNode->next = temp;
}

void insertAtEnd(int value, List *list) {
	Node *lastNode = getLastNode(list);
	Node *newNode = createNode(value);
	if (isEmpty(list)) {
		list->head = newNode;
		return;
	}
	lastNode->next = newNode;
}

void insertPosition(int value, int pos, List *list) {
	if (isOutOfIndex(pos, list)) { return; }
	if (pos == 0) {
		insertAtBeginning(value, list);
		return;
	} else if (pos == getSize(list)) {
		insertAtEnd(value, list);
		return;
	}
	Node *beforeNode = getNodePosition(pos - 1, list);
	Node *afterNode = getNodePosition(pos + 1, list);
	Node *newNode = createNode(value);
	beforeNode->next = newNode;
	newNode->next = afterNode;
}

// REMOVE OPERATIONS
void removeBeginning(List *list) {
	if (isEmpty(list)) { return; }
	if (getSize(list) == 1) {
		list->head = NULL;
		return;
	}
	Node *temp = list->head->next;
	list->head = temp;
}

void removeEnd(List *list) {
	if (getSize(list) < 2) {
		if (isEmpty(list)) { return; }
		list->head = NULL;
		return;
	}
	Node *lastNode = getLastNode(list);
	Node *newLastNode = getNodePosition(getSize(list) - 2, list);
	newLastNode->next = NULL;
	free(lastNode);
}

void removePosition(int pos, List *list) {
	if (isOutOfIndex(pos, list)) { return; }
	if (isEmpty(list)) { return; }
	if (pos == 0) {
		removeBeginning(list);
		return;
	} else if (pos == getSize(list) - 1) {
		removeEnd(list);
		return;
	}
	Node *beforeNode = getNodePosition(pos - 1, list);
	Node *afterNode = getNodePosition(pos + 1, list);
	beforeNode->next = afterNode;
}