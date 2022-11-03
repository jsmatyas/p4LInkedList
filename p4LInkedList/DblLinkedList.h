#ifndef DBLLINKEDLIST_H
#define DBLLINKEDLIST_H
#include <istream>
#include "MYString.h"


using namespace std;

class Node {   // fully defined here due to its simplicity
	public:
	Node() {
		next = prev = nullptr;
	}
	Node(string num) {
		data = num;
		next = prev = nullptr;
	}
	MYString data;
	Node *next;
	Node *prev;

};


class DblLinkedList {
  public:
	DblLinkedList();
	DblLinkedList(const DblLinkedList& dll);
	~DblLinkedList();

	bool push_back(const MYString& str);
		
	void resetIterator() const ;
	bool hasMore() const;
	MYString& next() const;

	void testConnections();
	int getCount();

	friend ostream& operator<<(ostream& outputStrm, DblLinkedList& argList);
	DblLinkedList& operator=(DblLinkedList& argList);
	bool insert(const MYString& str);
	bool remove(MYString& str);
	bool hasAlready(const MYString& str);

	



  private:
	Node *head, *tail;
	mutable Node *it;	// mutable says that it can change in a const member function
	int count;
};

#endif
