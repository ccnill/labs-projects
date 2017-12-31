#pragma once
#include <string>
using namespace std;

#ifndef MYSTRING_H
#define MYSTRING_H


class myString {
public:
	myString();
	int size();
	void addStart(myString);
	void addEnd(myString);
	void partString(int, int);
	void replPartString(myString, int);
	void replWholeString(myString);
	void compareString(myString);
	void initString();
	void setString(string);
	void getString();
	void printString();

private:
	char charArray[26] = {};
	int statusError = 0;


};


#endif MYSTRING_H