
/*
#include <iostream>
#include <fstream>
#include <string>

template <class T>
class Stack {
	struct node {
		T data;
		node* next;
	};
	node* top;


private:
	//NodeType<T> *topPtr;
public:
	Stack() {
		top = NULL;
	}

	Stack(const Stack<T> &x) {
		node* temp = x.top;
		node* current = top;
		top = NULL;
		if (temp == NULL) {
			return;
		}

		while (temp != NULL) {
			if (top == NULL) {
				current = new node;

				top = current;
			}
			else {
				current->next = new node;
				current = current->next;


			}
			current->data = temp->data;
			current->next = NULL;
			temp = temp->next;
		}


	}
	void makeEmpty() {
		if (top) {
			node* current = top;
			node* next = 0;
			while (current != NULL) {
				next = current->next;
				delete current;
				current = next;
			}
		}
		top = NULL;
		std::cout << "Stack is now empty! \n";
	}
	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		else
			return false;
	}
	bool isFull() {
		node *current = top;
		int count = 0;
		while (current != NULL) {
			count++;
			current = current->next;
		}
		if (count == 5) {
			return true;
		}
		else
			return false;
	}

	int length() {
		node *current = top;
		int count = 0;
		while (current != NULL) {
			count++;
			current = current->next;
		}
		return count;
	}
	void print() {
		node *current = top;
		while (current != NULL) {
			std::cout << current->data << std::endl;
			current = current->next;
		}

	}
	void push(const T& x) {
		node *temp = new node;
		temp->data = x;
		temp->next = top;
		top = temp;
	}

	void pop() {
		node *temp = top;
		if (temp == NULL) {
			std::cout << "Error: Nothing in stack! \n";
		}
		else {
			top = top->next;
			temp->next = NULL;
			delete temp;
		}
	}
	~Stack() {
		if (top) {
			node* current = top;
			while (current != NULL) {
				node* next = current->next;
				delete current;
				current = next;
			}
			top = NULL;
		}
	}
};


int main() {
	Stack<int> intStack;
	intStack.pop();
	intStack.push(11);
	intStack.push(22);
	std::cout << "int length 1 = " << intStack.length() << std::endl;
	intStack.pop();
	intStack.push(33);
	std::cout << "int length 2 = " << intStack.length() << std::endl;
	intStack.print();
	intStack.push(44);
	intStack.push(55);
	intStack.push(66);
	if (intStack.isFull() == false) {
		std::cout << "The int stack is not full !\n";
	}
	else {
		std::cout << "The int stack is full ! \n";
	}
	Stack<float> floatStack;
	float y;
	floatStack.pop();
	floatStack.push(7.1);
	std::cout << "float length 1 = " << floatStack.length() << std::endl;
	floatStack.push(2.3);
	floatStack.push(3.1);
	std::cout << "float length 2 = " << floatStack.length() << std::endl;
	floatStack.pop();
	std::cout << "The float stack contains: " << std::endl;
	floatStack.print();

	Stack<float> floatStack2 = floatStack;
	std::cout << "The float stack 2 contains: " << std::endl;
	floatStack2.print();
	floatStack.makeEmpty();
	Stack<float> floatS;
	floatS.push(1.1);
	floatS.push(6.6);
	floatS.push(3.3);
	floatS.push(7.7);
	floatS.push(9.9);
	floatS.print();
	Stack<int> test;
	test.pop();
	system("pause");
	return 0;
}
*/

//============================================================================
// Name        : Lab.cpp
// Author      : 
// Date Created: 11/19/17
// Description : Exception Handling
//============================================================================

#include <iostream>
using namespace std;

struct monthStuff
{
	int monthNum, days;
	string name;
};

class tryCatch
{
private:
	int day, year;
	monthStuff month;

public:
	void setMonth(int m)
	{
		month.monthNum = m;
		setMonthDays();
	}
	int getMonthNum()
	{
		return month.monthNum;
	}

	void setDay(int d)
	{
		day = d;
	}
	int getDay()
	{
		return day;
	}

	void setYear(int y)
	{
		year = y;
	}
	int getYear()
	{
		return year;
	}

	void setMonthDays()
	{
		int n = getMonthNum();
		switch (n)
		{
		case 1:
			month.name = "January";
			break;

		case 2:
			month.name = "February";
			break;

		case 3:
			month.name = "March";
			break;

		case 4:
			month.name = "April";
			break;
		case 5:
			month.name = "May";
			break;

		case 6:
			month.name = "June";
			break;

		case 7:
			month.name = "July";
			break;

		case 8:
			month.name = "August";
			break;

		case 9:
			month.name = "September";
			break;

		case 10:
			month.name = "October";
			break;

		case 11:
			month.name = "November";
			break;

		case 12:
			month.name = "December";
			break;

		default:
			cout << "Error";
			break;
		}

		if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		{
			month.days = 31;
		}
		else if (n == 4 || n == 6 || n == 9 || n == 11)
		{
			month.days = 30;
		}
		else if (n == 2)
		{
			month.days = 28;
		}
	}

	void blocks()
	{
		try
		{
			if (day > month.days || day < 1)
			{
				//cout << month.days;
				cout << "Day is invalid.\n";
				throw day;
			}
			if (month.monthNum < 1 || month.monthNum > 12)
			{
				cout << "Month is invalid.\n";
				throw month.monthNum;
			}
			if (year < 1915 || year > 2017)
			{
				cout << "Year is invalid.\n";
				throw year;
			}
		}
		catch (int day)
		{
			cout << "Enter a value for day: ";
			cin >> day;
			setDay(day);
		}
		catch (monthStuff &month)
		{
			cout << "Enter a value for month: ";
			cin >> month.monthNum;
			setMonth(month.monthNum);
		}
		catch (...)
		{
			cout << "Enter a value for year: ";
			cin >> year;
			setYear(year);
		}
	}

	void print()
	{
		//cout << month.name << " " << day << " " << year;
	}
};

int main()
{
	tryCatch date;
	int day, month, year;
	cout << "Enter a value for day: ";
	cin >> day;
	cout << "Enter a value for month: ";
	cin >> month;
	cout << "Enter a value for year: ";
	cin >> year;

	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
	date.blocks();
	date.print();
	system("pause");
	return 0;
}
