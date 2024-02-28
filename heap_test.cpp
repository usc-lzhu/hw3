#include <iostream>
#include <functional>
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]) {

	// 3-ary int max heap
	cout << "3-ARY INT MAX HEAP ---------------" << endl;
	Heap<int, greater<int>> heap1(3, greater<int>());

	// push and display size and top value
	cout << "\npush 10" << endl;
	heap1.push(10);
	cout << "size: " << heap1.size() << endl;
	cout << "top: " << heap1.top() << endl;

	cout << "\npush 5" << endl;
	heap1.push(5);
	cout << "size: " << heap1.size() << endl;
	cout << "top: " << heap1.top() << endl;

	cout << "\npush 15" << endl;
	heap1.push(15);
	cout << "size: " << heap1.size() << endl;
	cout << "top: " << heap1.top() << endl;

	// push in more items
	cout << "\npush ";
	for (int i = 0; i < 30; i += 3) {
		cout << i << " ";
		heap1.push(i);
	}
	cout << "\nsize: " << heap1.size() << endl;

	// pop all values until empty
	while (!heap1.empty()) {
		cout << "\ntop: " << heap1.top() << endl;
		cout << "pop" << endl;
		heap1.pop();
	}

	// test underflow error
	// cout << "pop" << endl;
	// heap1.pop();
	// cout << "top: " << heap1.top() << endl;


	// 10-ary char min heap
	cout << "\n\n10-ARY CHAR MIN HEAP ---------------" << endl;
	Heap<char, less<char>> heap2(10, less<char>());

	// push and display size and top value
	cout << "\npush k" << endl;
	heap2.push(10 + 'a');
	cout << "size: " << heap2.size() << endl;
	cout << "top: " << heap2.top() << endl;

	cout << "\npush f" << endl;
	heap2.push(5 + 'a');
	cout << "size: " << heap2.size() << endl;
	cout << "top: " << heap2.top() << endl;

	cout << "\npush p" << endl;
	heap2.push(15 + 'a');
	cout << "size: " << heap2.size() << endl;
	cout << "top: " << heap2.top() << endl;

	// push in more items
	cout << "\npush ";
	for (int i = 0; i < 15; i++) {
		cout << (char) ('a' + i) << " ";
		cout << (char) ('z' - i) << " ";
		heap2.push('a' + i);
		heap2.push('z' - i);
	}
	cout << "\nsize: " << heap2.size() << endl;

	// pop all values until empty
	while (!heap2.empty()) {
		cout << "\ntop: " << heap2.top() << endl;
		cout << "pop" << endl;
		heap2.pop();
	}

}