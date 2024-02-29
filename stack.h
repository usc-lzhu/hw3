#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};


template <typename T>
Stack<T>::Stack() { }

template <typename T>
Stack<T>::~Stack() { }


template <typename T>
size_t Stack<T>::size() const {
	// returns underlying vectors size
	return std::vector<T>::size();
}

template <typename T>
bool Stack<T>::empty() const {
	// returns true if size is 0
	if (Stack<T>::size() == 0) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::push(const T& item) {
	// pushes item onto vector
	std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
	// throw underflow error if empty
	if (Stack<T>::empty()) {
		throw std::underflow_error("pop: underflow error");
	}
	// pops item off vector
	std::vector<T>::pop_back();
}

template <typename T>
T const & Stack<T>::top() const {
	// throw underflow error if empty
	if (Stack<T>::empty()) {
		throw std::underflow_error("top: underflow error");
	}
	// returns last item of vector
	return std::vector<T>::back();
}

#endif