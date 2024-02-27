#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct isOdd {
	bool operator()(int val) {
		if (val % 2 == 1) {
			return true;
		}
		return false;
	}
};


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code


		Node* smaller = nullptr;
		Node* larger = nullptr;
		int pivot = 10;
		llpivot(head, smaller, larger, pivot);

    cout << "Pivoted list: " << endl;
		cout << "\tSmaller: ";
    print(smaller);
		cout << "\tLarger: ";
    print(larger);

		isOdd pred;
		Node* evenSmaller = llfilter(smaller, pred);
		cout << "Filtered list: ";
		print(evenSmaller);


		Node* empty = nullptr;
		llpivot(empty, smaller, larger, pivot);

    cout << "\nEmpty pivoted list: " << endl;
		cout << "\tSmaller: ";
    print(smaller);
		cout << "\tLarger: ";
    print(larger);

		Node* evenEmpty = llfilter(empty, pred);
		cout << "Empty filtered list: ";
		print(evenEmpty);

    return 0;

}
