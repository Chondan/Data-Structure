#include <stdio.h>
#include <malloc.h>

// A Tree Node
typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

// OPERATIONS
Node *createNode(int key); // DONE
Node *insertNode(int key, Node *node); // DONE
Node *search(int key, Node *node); // DONE
Node *leftmost(Node *node); // DONE
Node *deleteNode(int key, Node *node); // DONE
void inorder(Node *node); // DONE
void displayInorder(Node *node); // DONE

int main(void) {
	Node *root = NULL;
	root = insertNode(10, root);
	Node *x = insertNode(5, root);
	Node *a = insertNode(1, root);
	insertNode(11, root);
	deleteNode(11, root);
	insertNode(6, root);
	insertNode(1, root);
	displayInorder(root);
	Node *found = search(6, root);

	Node *left = leftmost(root);
	printf("Leftmost: %d\n", left->key);

	if (found) {
		printf("Found: %d\n", found->key);
	} else {
		printf("Not Found.\n");
	}
}

Node *createNode(int key) {
	Node *newNode = malloc(sizeof(Node));
	newNode->key = key;
	return newNode;
}

Node *insertNode(int key, Node *node) {
	if (!node) { 
		return createNode(key); 
	}
	if (key < node->key) {
		node->left = insertNode(key, node->left);
	} else if (key > node->key) {
		insertNode(key, node->right);
		node->right = insertNode(key, node->right);
	}
	return node;
}

void displayInorder(Node *node) {
	printf("----- BINARY SEARCH TREE -----\n");
	inorder(node);
	printf("------------------------------\n");
}

void inorder(Node *node) {
	if (!node) { return; }
	inorder(node->left);
	printf("%d\n", node->key);
	inorder(node->right);
}

Node *search(int key, Node *node) {
	if (!node) { return NULL; }
	if (key == node->key) { return node; }
	if (key <= node->key) {
		search(key, node->left);
	} else {
		search(key, node->right);
	}
}

Node *leftmost(Node *node) {
	if (!node) { return NULL; }
	if (!node->left) { return node; }
	return leftmost(node->left);
}

Node *deleteNode(int key, Node *node) {
	// Base case
	if (!node) { return NULL; }

	if (key < node->key) {
		node->left = deleteNode(key, node->left);
	} else if (key > node->key) {
		node->right = deleteNode(key, node->right);
	} else {
		// Found the node to be deleted
		// 3 conditions -> one child, two child and no child
		if (!node->left) {
			Node *temp = node->right;
			free(node);
			return temp;
		} else if (!node->right) {
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node *temp = leftmost(node->right);
		node->key = temp->key;
		node->right = deleteNode(temp->key, node->right);

	}
	return node;
}