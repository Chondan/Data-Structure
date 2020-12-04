#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// A Tree Node
typedef struct Node {
	int value;
	struct Node *left, *right;
	bool rightThread;
	// Since right pointer is used for two purposes, the boolean variable rightThread
	// is used to indicate whether right pointer points to right child or inorder successor.
} Node;

// Untility function to find leftmost node in a tree with n
Node *leftMost(Node *node);
// inorder traversal
void inOrder(Node *node);
Node *createNode(int value, bool rthread);


int main(void) {

	Node *root = createNode(6, false);
	root->left = createNode(3, false);
	root->left->left = createNode(1, true);
	root->left->left->right = root->left;
	root->left->right = createNode(5, true);
	root->left->right->right = root;
	inOrder(root);
}

Node *createNode(int value, bool rthread) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->rightThread = rthread;
	return newNode;
}

Node *leftMost(Node *node) {
	if (!node) { return NULL; }
	while (node->left) {
		node = node->left;
	}
	return node;
}

void inOrder(Node *node) {
	Node *cur = leftMost(node);
	while (cur != NULL) {
		printf("%d\n", cur->value);

		if (cur->rightThread) cur = cur->right;
		else cur = leftMost(cur->right);
	}
}
