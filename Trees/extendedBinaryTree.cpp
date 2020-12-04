#include <iostream>
using namespace std;

// A Tree Node
typedef struct Node {
	struct Node *left;
	int value;
	struct Node *right;
} Node;

Node *createNode(int value);
void traverse(Node *root);

int main(void) {
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(5);
	root->right->right = createNode(4);
	traverse(root);
}

Node *createNode(int value) {
	Node *newNode = new Node;
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void traverse(Node *node) {
	if (node != NULL) {
		traverse(node->left);
		cout << node->value << " ";
		traverse(node->right);
	} else {
		node = createNode(-1);
		cout << node->value << " ";
	}
}