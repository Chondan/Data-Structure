#include <stdio.h>
#include <malloc.h>

// A Tree Node
typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

// OPERATIONS
Node *createNode(int key); // DONE
Node *insert(int key, Node *node); // DONE
Node *search(int key);
void delete(int key);

int main(void) {
	Node *root = NULL;
	root = insert(10, root);
	insert(30, root);
	printf("%d\n", root->right->key);
}

Node *createNode(int key) {
	Node *newNode = malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node *insert(int key, Node *node) {
	if (!node) {
		return createNode(key);
	}
	if (key <= node->key) {
		node->left = insert(key, node->left);
	} else {
		node->right = insert(key, node->right);
	}
}