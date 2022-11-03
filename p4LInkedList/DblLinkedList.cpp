#include "DblLinkedList.h"
#include <iostream>


using namespace std;

DblLinkedList::DblLinkedList() {
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}
DblLinkedList::DblLinkedList(const DblLinkedList& dll) {
	head = dll.head;
	tail = dll.tail;
	it = head;
	dll.resetIterator();
	while (dll.hasMore() == true) {
		this->push_back(it->data);
		next();
	}
}

DblLinkedList::~DblLinkedList() {
	while (this->hasMore()) {
		delete this->it->prev;
	}
	delete it;
}

bool DblLinkedList::push_back(const MYString& str) {	// write first
	Node* temp = new Node();
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
	count++;
	return true;
}

void DblLinkedList::resetIterator() const {			// write second
	it = head;
}

bool DblLinkedList::hasMore() const{// and so on....
	if (it == nullptr) {
		return false;
	}
	//if (it->next != nullptr) {
		//return true;
	//}
	return true;
}

MYString& DblLinkedList::next() const {
	Node* temp = new Node();
	temp->data = it->data;
	it = it->next;
	// needs to be written: gets the string the it pointer is pointing to
	//   then moves the it pointer to next "node" (could be nullptr)
	return temp->data;
}

void DblLinkedList::testConnections() {	
	resetIterator();
	if (head == nullptr) {
		cout << "empty list";
		
	}
	if (it == head) {
		if (head->prev != nullptr) {
			cout << "head is pointing to previous";
		}
	}
	while (this->hasMore()) {
		if (it == tail) {
			if (it->next == nullptr) {
				cout << "TEST CONNECTIONS Passed\n";
				
			}
			else {
				cout << "TEST CONNECTIONS Failed\n";
				
			}
			break;
		}
		 if (it == it->next->prev) {
			cout << "TEST CONNECTIONS Passed\n";
			next();
		}
		else
		{
			cout << "TEST CONNECTIONS Failed\n";
			next();
		}
	}
}

int DblLinkedList::getCount() {
	return count;
}


ostream& operator<<(ostream& outputStrm, DblLinkedList& argList){
	outputStrm << argList.it->data;
	outputStrm << " ";
	return outputStrm;
}

DblLinkedList& DblLinkedList::operator=(DblLinkedList& argList) {
	count = argList.count;
	head = argList.head;
	tail = argList.tail;
	it = argList.it;
	while (argList.hasMore() == true) {
		this->push_back(argList.next());
	}

	return *this;
}

bool DblLinkedList::insert(const MYString& str) {
	this->resetIterator();
	while (this->hasMore() == true) {
		if (this->hasAlready(str) == true) {
			count++;
			return false;
		}
		next();
	}

	this->resetIterator();
	if (it->data < str) {
		next();
	}
	else{
		Node* temp = new Node();
		temp->data = str;
	Node* before = it->prev;
	temp->data = str;

	temp->next = it;
	temp->prev = it->prev;
	if (it->prev == nullptr) {
		head = temp;
	}
	if (it->next == nullptr) {
		tail = temp;
	}
	it->prev = temp;
	before = temp;
	count++;
	return true;
	 }
}

bool DblLinkedList::remove(MYString& str) {
	this->resetIterator();
	while (this->hasMore() == true) {
		if (str == it->data)
		{
			if (it->next == nullptr) {

			}

			it->prev->next = it->next;
			it->next->prev = it->prev;

			delete it;
			this->resetIterator();
			return true;
		}
	}
	return false;
}

bool DblLinkedList::hasAlready(const MYString& str) {
	while (this->hasMore() == true) {
		if (this->it->data == str) {
			return true;
		}
	}
	return false;
}
