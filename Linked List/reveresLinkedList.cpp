#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
};

struct LinkedList {
	Node *head;
	LinkedList() { head = NULL; }
	void push(int value) {
		Node *newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	void reverse() {

		// NULL -> 1 -> 2 -> 3 -> NULL reverse to 3 -> 2 -> 1 -> NULL
		Node *cur = head; // 1
		Node *prev = NULL, *next = NULL;

		while (cur != NULL) {
			next = cur->next; // 2
			cur->next = prev; // 1 -> NULL
			prev = cur; // 1
			cur = next; // 2
		}
		head = prev;
	}
	void print() {
		Node *cur = head;
		while (cur != NULL) {
			cout << cur->value << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main(void) {

	LinkedList l;
	l.push(10);
	l.push(15);
	cout << "Given linked list" << endl;
	l.print();

	cout << "Reversed linked list" << endl;
	l.reverse();
	l.print();
}