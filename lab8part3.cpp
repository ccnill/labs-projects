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
	void makeEmpty(std::ofstream& ofs) {
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
		ofs << "Stack is now empty! \n";
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
	void print(std::ofstream& ofs) {
		node *current = top;
		while (current != NULL) {
			std::cout << current->data << std::endl;
			ofs << current->data << std::endl;
			current = current->next;
		}

	}
	void push(const T& x, std::ofstream& ofs) {
		node *temp = new node;
		temp->data = x;
		temp->next = top;
		top = temp;
		std::cout << "Pushed: " << x << "\n";
		ofs << "Pushed: " << x << "\n";
	}

	void pop(std::ofstream& ofs) {
		node *temp = top;
		if (temp == NULL) {
			std::cout << "Error: Nothing in stack! \n";
			ofs << "Error: Nothing in stack! \n";
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
template<class T>
class Queue {
	struct node {
		T data;
		node* next;
	};
	node* top;
	node *front;
	node *rear;
	node *next;
private:
	//NodeType<T>* front;
	//NodeType<T>* rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
		next = NULL;
	}
	Queue(const Queue<T> &x) {
		node* saveFront;
		node* temp;
		front = x.front;
		temp = new node;
		temp->data = front->data;
		saveFront = temp;

		while (front->next != NULL) {
			temp->next = new node;
			temp->next->data = front->next->data;
			temp = temp->next;
			front = front->next;
		}
		temp->next = NULL;
		front = saveFront;


	}

	void MakeEmpty(std::ofstream& ofs) {
		if (front) {
			node* current = front;
			node* next = 0;
			while (current != NULL) {
				next = current->next;
				delete current;
				current = next;
			}
		}
		rear = NULL;
		std::cout << "Queue is empty! \n";
		ofs << "Queue is empty! \n";

	}
	bool IsEmpty() {
		if (front == NULL) {
			return true;
		}
		else
			return false;
	}
	bool IsFull() {
		if (length() == 5) {
			return true;
		}
		else
			return false;
	}
	int length() {
		int count = 0;
		node *temp = front;

		if (rear == NULL) {
			return count;
		}
		else {
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			return count;

		}
	}
	void print(std::ofstream& ofs) {
		if (rear == NULL) {
			std::cout << "No data in Queue \n";
			ofs << "No data in Queue \n";
		}
		node *temp = front;
		while (temp != NULL) {
			std::cout << temp->data << " \n";
			ofs << temp->data << " \n";

			temp = temp->next;
		}

	}
	void Enqueue(const T x, std::ofstream& ofs) {
		node* temp = new node;
		temp->data = x;
		temp->next = NULL;
		if (front == NULL) {
			front = rear = temp;
			std::cout << x << " has been inserted successfully! \n";
			ofs << x << " has been inserted successfully! \n";
		}
		else {
			rear->next = temp;
			std::cout << x << " has been inserted successfully! \n";
			ofs << x << " has been inserted successfully! \n";
		}
		rear = temp;
	}
	void Dequeue(T &x, std::ofstream& ofs) {
		if (front == NULL) {
			ofs << "Empty Queue! \n";
			std::cout << "Empty Queue! \n";
			return;
		}
		if (front == rear) {
			front = rear = NULL;
		}
		else
			front = front->next;
	}
	
	~Queue() {
		if (front) {
			node* current = front;
			node* next = 0;
			while (current != NULL) {
				next = current->next;
				delete current;
				current = next;
			}
		}
	}

};

template<typename T>
void order(T arr[5]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}
}


int main() {
	std::ofstream ofs;
	std::ifstream ins;
	std::string input;
	Queue<int> intQ;
	Queue<float> floatQ;
	Queue<char> charQ;
	Stack<int> intS;
	Stack<float> floatS;
	Stack<char> charS;
	int itemp[5];
	float ftemp[5];
	char ctemp[5];
	int i;
	char c;
	float f;

	ofs.open("out.txt");
	std::cout << "Input file name: ";
	getline(std::cin, input);
	ins.open(input.c_str());

	ins >> input;

	if (input == "I") {
		for (int j = 0; j < 5; j++) {
			ins >> i;
			intS.push(i, ofs);
			itemp[j] = i;
		}
		order<int>(itemp);
		for (int i = 0; i < 5; i++) {
			intQ.Enqueue(itemp[i], ofs);
		}
		for (int i = 0; i < 5; i++) {
			std::cout << itemp[i] << "\n";
		}
		std::cout << "\n";

	}
	else if (input == "C") {
		for (int j = 0; j < 5; j++) {
			ins >> c;
			charS.push(c, ofs);
			ctemp[j] = c;
		}
		order<char>(ctemp);
		for (int i = 0; i < 5; i++) {
			charQ.Enqueue(ctemp[i], ofs);
		}
		for (int i = 0; i < 5; i++) {
			std::cout << ctemp[i] << "\n";
		}
		std::cout << "\n";

	}
	else if (input == "F") {
		for (int j = 0; j < 5; j++) {
			ins >> f;
			floatS.push(f, ofs);
			ftemp[j] = f;
		}
		order<float>(ftemp);
		for (int i = 0; i < 5; i++) {
			floatQ.Enqueue(ftemp[i], ofs);
		}
		for (int i = 0; i < 5; i++) {
			std::cout << ftemp[i] << "\n";
		}
		std::cout << "\n";

	}
	else {
		std::cout << "No identifier found! \n";
		ofs << "No identifier found! \n";
	}

	ins.close();
	ofs.close();
	system("pause");
	return 0;
}