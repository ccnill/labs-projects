#include <iostream>

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
	Queue(const Queue<T> &x){
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

	void MakeEmpty() {
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
	void print() {
		if (rear == NULL) {
			std::cout << "No data in Queue \n";
		}
		node *temp = front;
		while (temp != NULL) {
			std::cout << temp->data << " \n";
			temp = temp->next;
		}

	}
	void Enqueue(const T x) {
		node* temp = new node;
		temp->data = x;
		temp->next = NULL;
		if (front == NULL) {
			front = rear = temp;
			std::cout << x << " has been inserted successfully! \n";
		}
		else {
			rear->next = temp;
			std::cout << x << " has been inserted successfully! \n";
		}
		rear = temp;
	}
	void Dequeue(T &x) {
		if (front == NULL) {
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

int main() {
	Queue<int>intQ;
	int x;
	intQ.MakeEmpty();
	intQ.Dequeue(x);

	intQ.Enqueue(10);
	intQ.Enqueue(20);

	intQ.Enqueue(30);
	intQ.Enqueue(40);
	std::cout << "int length 3 = " << intQ.length() << " \n";

	intQ.Dequeue(x);
	std::cout << "int length 4 = " << intQ.length() << " \n";
	std::cout << "The int Queue contains: " << " \n";
	intQ.print();

	if (intQ.IsFull() == false) {
		std::cout << "The int queue is not full! \n";
	}
	else
		std::cout << "The int queue is full! \n";
	float y;
	Queue<float>floatQ;
	floatQ.MakeEmpty();
	floatQ.Dequeue(y);
	floatQ.Enqueue(7.1);
	std::cout << "Float length 3: " << floatQ.length() << " \n";
	floatQ.Dequeue(y);
	std::cout << "Float length 3: " << floatQ.length() << " \n";
	floatQ.Enqueue(2.3);
	floatQ.Enqueue(2.3);
	std::cout << "Float length 4: " << floatQ.length() << " \n";
	floatQ.Enqueue(3.1);
	floatQ.Dequeue(y);
	std::cout << "The float queue contains: \n";
	floatQ.print();
	Queue<float>floatQ2(floatQ);
	std::cout << "The float queue 2 contains: \n";
	floatQ2.print();
	floatQ.MakeEmpty();
	std::cout << "The float queue 3 contains: \n";
	floatQ2.print();

	Queue<char> test;
	test.Enqueue('a');
	test.Enqueue('b');
	test.Enqueue('c');
	test.Enqueue('d');
	test.Enqueue('e');
	test.print();
	system("pause");
	return 0;
}