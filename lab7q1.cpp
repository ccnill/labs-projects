#include <iostream>
#include <fstream>
#include <string>
using namespace std;



template<typename T>
class node
{
	T data;
	node *top;
	node *next;

public:
	node() {
		top = NULL;
		next = NULL;
	}
	void minMaxFunction(T val[], string input, ofstream &ofs) {
		node *current = top;
		if (val[0] == NULL) {
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
			{
				if (val[j]>val[j + 1])
				{
					T temp;

					temp = val[j];
					val[j] = val[j + 1];
					val[j + 1] = temp;
				}
			}
		}
		T max = val[0];
		T min = val[0];
		T value[5];
		for (int i = 0; i < 5; i++) {
			push(val[i]);
		}

		if (input == "max") {
			for (int i = 0; i < 5; i++) {
				if (peek() > max) {
					max = peek();
				}
				pop();
			}
			ofs << "Max is: " << max << endl;
			cout << "Max is: " << max << endl;
			for (int i = 0; i < 5; i++) {
				push(val[i]);
			}

		}
		else if (input == "min") {
			for (int i = 0; i < 5; i++) {
				if (peek() <= min) {
					min = peek();
				}
				pop();
			}
			ofs << "Min is: " << min << endl;
			cout << "Min is: " << min << endl;
			for (int i = 0; i < 5; i++) {
				push(val[i]);
			}


		}
		else
			cout << "Error: Invalid Input!" << endl;
	}

	void print(ofstream &ofs) {
		node *current = top;
		while (current != NULL) {
			ofs << "value: " << current->data << endl;
			cout << "value: " << current->data << endl;
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
		top = top->next;
		temp->next = NULL;
		delete temp;
	}

	T peek() {
		if (!top) {
			return NULL;
		}
		else {
			return top->data;
		}
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

	~node() {
		if (top) {
			node* current = top;
			node* next = 0;
			while (current != NULL) {
				next = current->next;
				delete current;
				current = next;
			}
		}
	}
};


int main()
{
	ifstream ins;
	ofstream ofs;
	char value[5];
	string input;
	ofs.open("out.txt");
	ins.open("data.dat");
	if (ins.is_open()) {
		ins.seekg(0, ios::end);
		size_t size = ins.tellg();

		if (size == 0) {
			cout << "Error: File is empty! \n";
			system("pause");
			return 0;
		}
		else if (ins) {
			cout << "File Opened! \n";
			ins.seekg(0, ios::beg);
		}
	}
	else {
		cout << "File DNE! \n";
		system("pause");
		return 0;
	}

	
	for (int i = 0; i < 5; i++) {
		value[i] = NULL;
	}
	int i = 0;
	while (!ins.eof()) {
		ins >> value[i];
		i++;
	}
	node<char> stack;
	bool done = false;
	while (!done) {
		cout << "Do you want the max or min: ";
		cin >> input;
		if (input == "max" || input == "min") {
			done = true;
		}
		else {
			cout << "Invalid Input! \n";
		}
	}
	stack.minMaxFunction(value, input, ofs);
	stack.print(ofs);
	ofs.close();
	ins.close();
	system("pause");
	return 0;
}
/*
if (stack.isFull() == true) {
cout << "Is Full" << endl;
}
else
cout << "is Not Full" << endl;
if (stack.isEmpty() == false) {
cout << "Is Not Empty " << endl;
}
else
cout << "Is Empty" << endl;

*/