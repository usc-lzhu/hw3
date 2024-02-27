#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[]) {
	Stack<int> stack;

	// push 5, 8, 3 and display size
	cout << "size: " << stack.size() << endl;
	cout << "push 5" << endl;
	stack.push(5);
	cout << "size: " << stack.size() << endl;
	cout << "\npush 8" << endl;
	stack.push(8);
	cout << "size: " << stack.size() << endl;
	cout << "\npush 3" << endl;
	stack.push(3);
	cout << "size: " << stack.size() << endl;


	// display top value and size then pop 
	cout << "\ntop: " << stack.top() << endl;

	cout << "\npop" << endl;
	stack.pop();
	cout << "\ntop: " << stack.top() << endl;
	cout << "size: " << stack.size() << endl;

	cout << "\npop" << endl;
	stack.pop();
	cout << "\ntop: " << stack.top() << endl;
	cout << "size: " << stack.size() << endl;


	// push 10 and display size and top value
	cout << "\npush 10" << endl;
	stack.push(10);
	cout << "size: " << stack.size() << endl;
	cout << "\ntop: " << stack.top() << endl;


	// pop and display top value and size
	cout << "\npop" << endl;
	stack.pop();
	cout << "\ntop: " << stack.top() << endl;
	cout << "size: " << stack.size() << endl;


	// pop last value
	cout << "\npop" << endl;
	stack.pop();


	// test underflow error

	// cout << "\npop underflow error" << endl;
	// stack.pop();

	cout << "\ntop underflow error" << endl;
	cout << "top: " << stack.top() << endl;

}