#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
	// base case: traversed to end of list
	if (head == nullptr) {
		larger = nullptr;
		smaller = nullptr;
		return;
	}

	// recursive call: traverses to next node
	llpivot(head -> next, smaller, larger, pivot);

	// updates larger or smaller list based on pivot comparison
	if (head -> val > pivot) {
		Node* temp = larger;
		larger = head;
		larger -> next = temp;
	}
	else {
		Node* temp = smaller;
		smaller = head;
		smaller -> next = temp;
	}

	// set initial list to null
	head = nullptr;
}