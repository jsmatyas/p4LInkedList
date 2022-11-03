////
// Name: Nancy Programmer
// Section: A, B, or S
// Class Name: MYString
//
// Description: A brief description of the class.  What does the 
//  class do (not how it does it: for example, it uses loops)?  Blah
//  blah blah blah blah, blah blah blah blah blah blah blah blah!
////

#ifndef MYSTRING_H
#define MYSTRING_H

#include <istream>

using namespace std;

class MYString {    // You NEED to change the name of the class to reflect your name 
	//   for example Nancy Programmer would use the name NPString 
public:
	MYString();						// default constructor
	MYString(const char* cstr);		// cstring constructor
	MYString(const MYString& mstr);	// copy constructor
	~MYString();					// deconstructor

	int length();
	int capacity();

	static int getCurrentCount();
	static int getCreatedCount();

	char operator[](int index);
	friend istream& operator>>(istream& inputStrm, MYString& argStr);
	friend ostream& operator<<(ostream& outputStrm, MYString& argStr);

	bool operator<(const MYString& argStr);
	bool operator>(const MYString& argStr);
	bool operator==(const MYString& argStr);

	MYString& operator=(const string& str);
	MYString& operator=(const MYString& argStr);
	
	const char* c_str();

	MYString operator+(const MYString& argStr);

private:
	char* str;
	int end;
	int cap;
};

#endif

