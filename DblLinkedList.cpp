#include "DblLinkedList.h"
#include <iostream>


using namespace std;

DblLinkedList::DblLinkedList() {
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}


bool DblLinkedList::push_back(const string& str) {	// write first
	Node* temp;
	temp->data = str;
	if (head == nullptr && tail == nullptr) {
		head = temp;
		tail = temp;
		it = head;
		return true;
		count++;
	}
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	it = temp;
	count++;
	return true;
}

void DblLinkedList::resetIterator() const {			// write second
	it = head;
}

bool DblLinkedList::hasMore() const {				// and so on....
	if (it->next != nullptr) {
		it = it->next;
		return true;
	}
	return false;
}

string DblLinkedList::next() const {
	Node* temp = new Node;
	temp->data = it->data;
	it = it->next;
	// needs to be written: gets the string the it pointer is pointing to
	//   then moves the it pointer to next "node" (could be nullptr)
	return temp->data;
}

void DblLinkedList::testConnections() {	
	if (it == it->next->prev) {
		cout << "TEST CONNECTIONS Passed\n";
	}
	else
	{
		cout << "TEST CONNECTIONS Failed\n";
	}
}

int DblLinkedList::getCount() {
	return count;
}

Node& Node::operator=(Node& argNode) {
	data = argNode.data;
	next = argNode.next;
	prev = argNode.prev;

	return *this;

}

