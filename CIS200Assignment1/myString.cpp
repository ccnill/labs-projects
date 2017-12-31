#include "myString.h"	
#include <iostream>

myString::myString() {
	int length = 0;
	int startPos = 0;
	for (int i = 0; i < 26; i++) {
		charArray[i] = '\0';
	}
}

int myString::size() {
	int size = 0;
	for (int i = 0; i < 25; i++) {
		if (charArray[i] != '\0') {
			size++;
		}
	}
	return size;
}

void myString::addStart(myString str) {
	int size = 0;
	char tempString[25] = {};

	for (int i = 0; i < 25; i++) {
		tempString[i] = str.charArray[i];
	}

	for (int i = 0; i < tempString[i]; i++) {
		size++;
	}

	for (int i = 0; i < charArray[i]; i++) {
		tempString[size] = charArray[i];
		size++;
	}

	if (size + str.size() > 25) {
		statusError = -1;
		cout << "Error: too many values entered!" << endl;
		return;
	}


	for (int i = 0; i < tempString[i]; i++) {
		charArray[i] = tempString[i];
	}
}

void myString::addEnd(myString str) {
	char tempString[25] = {};
	int size = 0;

	for (int i = 0; i < 25; i++) {
		tempString[i] = str.charArray[i];
	}

	for (int i = 0; i < charArray[i]; i++) {
		size++;
	}

	if (size + str.size() > 25) {
		statusError = -1;
		cout << "Error: too many values entered!" << endl;
		return;
	}

	for (int i = 0; i < tempString[i]; i++) {
		charArray[size] = tempString[i];
		size++;

	}

}

void myString::partString(int startPos, int length) {

	if (startPos < 0 || startPos > 25) {
		statusError = -1;
		cout << "Error: cannot start at a negative index!" << endl;
	}

	for (int i = startPos - 1; i < length; i++) {
		cout << charArray[i];
	}

}

void myString::replPartString(myString str, int startPos) {

	if (str.size() + size() > 25) {
		statusError = -1;
		cout << "Error: too many values entered!" << endl;
		return;
	}

	int j = 0;

	for (int i = startPos - 1; i < str.size(); i++) {
		charArray[i] = str.charArray[j];
		j++;
	}

}

void myString::replWholeString(myString str) {

	if (str.size() > 25) {
		statusError = -1;
		cout << "Error: too many values entered!" << endl;
		return;
	}

	initString();

	for (int i = 0; i < str.size(); i++) {
		charArray[i] = str.charArray[i];
	}

}

void myString::compareString(myString str) {
	char tempString[25] = {};
	bool same = true;
	cin >> tempString;

	for (int i = 0; i < 25; i++) {
		if (charArray[i] != tempString[i]) {
			same = false;
		}
	}
	if (!same) {
		cout << "Strings are not the same!" << endl;
	}
	else
		cout << "Strings are the same!" << endl;

}



void myString::initString() {
	for (int i = 0; i < 25; i++) {
		charArray[i] = '\0';
	}

}

void myString::setString(string userinput) {

	for (int i = 0; i < userinput.length(); i++) {
		charArray[i] = userinput[i];
	}


}

void myString::getString() {
	for (int i = 0; i < charArray[i]; i++) {
		cout << charArray[i];
	}
}


void myString::printString() {
	int size = 0;
	for (int i = 0; i < charArray[i]; i++) {
		size++;
	}

	for (int i = 0; i < size; i++) {
		cout << charArray[i];
	}
	cout << endl;
}
