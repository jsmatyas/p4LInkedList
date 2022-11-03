 //#include "pch.h"   // may need this	
#include <iostream>
#include <fstream>
#include "MYString.h"
   // only used temporarily for Lab
#include "DblLinkedList.h"

using namespace std;

int main() {
	DblLinkedList list1;
	DblLinkedList list2;
	DblLinkedList mod1;
	DblLinkedList mod2;

	ifstream fin("infile1.txt");
	if (fin.fail()) {
		cout << "Couldn't open infile1.txt" << endl;
		system("pause");
		exit(1);
	}
	MYString temp;
	while (fin >> temp) {
		list1.insert(temp);
	}

	list1.resetIterator();
	while (list1.hasMore() == true) {
		cout << list1.next();
	}


	return 0;
}
