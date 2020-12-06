#include <stdio.h>
#include <malloc.h>

// A Tree Node
typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

// OPERATIONS
Node *createNode(int key);
Node *insertNode(int key, Node *node);
void inorder(Node *node);

int main(void) {
	Node *root = NULL;
	root = insertNode(10, root);
	insertNode(5, root);
	insertNode(11, root);
	insertNode(6, root);
	insertNode(1, root);
	inorder(root);
}

Node *createNode(int key) {
	Node *newNode = malloc(sizeof(Node));
	newNode->key = key;
	return newNode;
}

Node *insertNode(int key, Node *node) {
	if (!node) { return createNode(key); }
	if (key <= node->key) {
		node->left = insertNode(key, node->left);
	} else {
		node->right = insertNode(key, node->right);
	}
	return node;
}

void inorder(Node *node) {
	if (!node) { return; }
	inorder(node->left);
	printf("%d\n", node->key);
	inorder(node->right);
}