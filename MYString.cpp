
#include <iostream>
#include "MYString.h"

static int currentCount = 0;
static int createdCount = 0;

MYString::MYString() {
	cap = 20;
	end = 0;
	str = new char[cap];
	str[end] = '\0';
	
	currentCount++;
	createdCount++;
}

MYString::MYString(const char* cstr) {
	for (end = 0; cstr[end] != '\0'; ++end);
		//empty loop

	cap = ((end/20)+1)*20;									
	str = new char[cap];

	for (int i = 0; i <= end; ++i){
		str[i] = cstr[i];
	}
}

MYString::MYString(const MYString& mstr) {
	cap = mstr.cap;
	end = mstr.end;
	str = new char[cap];
	for (int i = 0; i <= end; i++) {
		str[i] = mstr.str[i];
	}
	currentCount++;
	createdCount++;
}
	


	MYString::~MYString() {
			delete[] str;
			currentCount--;
	}

int MYString::length() {
	return end;
}

int MYString::capacity() {
	return cap;
}

char MYString::operator[](int index) {
	if (index >= 0 && index < end) {
		return str[index];
	}
	else {
		return '\0';				
	}
}

istream& operator>>(istream& inputStrm, MYString& argStr) {
	char inputWord[100];
	if (inputStrm >> inputWord) {
		for (argStr.end = 0; inputWord[argStr.end] != '\0'; ++argStr.end);
		//empty loop
		if (ispunct(argStr.str[argStr.end] == 0)) {
			argStr.end--;
		}
		argStr.cap = 20;
		//TODO: needs to potentially grow for prog3

		for (int i = 0; i < argStr.end; ++i) {
			argStr.str[i] = inputWord[i];
		}
		argStr.str[argStr.end] = '\0';
	}

	else
		return inputStrm;
}

ostream& operator<<(ostream& outputStrm, MYString& argStr) {
	outputStrm << argStr.str;
	return outputStrm;
}

bool MYString::operator<(const MYString& argStr) {
	int length;
	bool smaller;
	if (argStr.end < end) {
		length = argStr.end;
		smaller = false;
	}
	else {
		length = end;
		smaller = true;
	}
	for (int i = 0; i < length; i++) {
		if (argStr.str[i] == str[i]) {
			continue;
		}
		else if (tolower(argStr.str[i]) < tolower(str[i])) {
			return false;
		}
		else {
			return true;
		}
	}
	return smaller;			
}

bool MYString::operator>(const MYString& argStr) {
	int length;
	bool bigger;
	if (argStr.end < end) {
		length = argStr.end;
		 bigger = true;
	}
	else {
		length = end;
		bigger = false;
	}
	for (int i = 0; i < length; i++) {
		if (tolower(argStr.str[i]) == tolower(str[i])) {
			continue;
		}
		else if (tolower(argStr.str[i]) < tolower(str[i])) {
			return true;
		}
		else {
			return false;
		}
	}
	return bigger;
}

bool MYString::operator==(const MYString& argStr) {
	int length = argStr.end;
	if (argStr.end != end) {
		return false;
	}


	for (int i = 0; i < length; i++) {
		if (tolower(argStr.str[i]) == tolower(str[i])) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

MYString& MYString::operator=(const MYString& argStr) {
	end = argStr.end;
		delete[] str;
		str = new char[argStr.cap];
		cap = argStr.cap;

	for (int i = 0; i <= end; ++i) {
		str[i] = argStr.str[i];
	}
	return *this;
}

MYString MYString::operator+(const MYString& argStr) {
	MYString newString;
	newString.end = end + argStr.end;
	newString.cap = ((newString.end / 20) + 1) * 20;
	
	if (newString.end >= 20) {
		delete[] newString.str;
		newString.str = new char[newString.cap];
	}
	
	int k = end;
	for (int i = 0; i < end; i++) {
		newString.str[i] = str[i];
	}
	for (int i = 0; i <= argStr.end; i++) {
		newString.str[k] = argStr.str[i];
		k++;
	}
	return newString;
}

int MYString::getCurrentCount() {
	cout << "currentCount is: " << currentCount << endl;
	return currentCount;
}

int MYString::getCreatedCount() {
	cout << "CreatedCount is: " << createdCount << endl;
	return createdCount;
}



const char* MYString::c_str() {
	return str;
}
