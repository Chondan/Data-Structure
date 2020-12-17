#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> *x = new list<int>[2];

	// (x + 1)->push_back(10);
	x[1].push_back(20);

	list<int>::iterator i;
	i = (x + 1)->begin();

	cout << *i;

}