#include <iostream>
#include <functional>
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]) {

	cout << "3-ARY INT MAX HEAP ---------------" << endl;
	Heap<int, greater<int>> heap(3, greater<int>());

	// push and display size and top value
	cout << "\npush 10" << endl;
	heap.push(10);
	cout << "size: " << heap.size() << endl;
	cout << "top: " << heap.top() << endl;

	cout << "\npush 5" << endl;
	heap.push(5);
	cout << "size: " << heap.size() << endl;
	cout << "top: " << heap.top() << endl;

	cout << "\npush 15" << endl;
	heap.push(15);
	cout << "size: " << heap.size() << endl;
	cout << "top: " << heap.top() << endl;

	// push in more items
	cout << "push ";
	for (int i = 0; i < 30; i += 3) {
		cout << i << " ";
		heap.push(i);
	}
	cout << "\nsize: " << heap.size() << endl;
	cout << "top: " << heap.top() << endl;

	// pop all values until empty
	while (!heap.empty()) {
		cout << "top: " << heap.top() << endl;
		cout << "pop" << endl;
		heap.pop();
	}

	// test underflow error
	// cout << "pop" << endl;
	// heap.pop();
	cout << "top: " << heap.top() << endl;


}