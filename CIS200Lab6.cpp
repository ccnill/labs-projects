/*
Creator: Christian Nill
Lab 6
date created: 10/24/17
date last edited: 11/1/17
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct ints {
	int evenas;
	int evends;
	int as;
	int ds;
	int value1;
};
struct node {
	ints value;
	node *next;
};

//works; ascending order
node fromFileAs(vector<int> array) {
	node *head = NULL;
	node *current;
	node *temp;
	node *prior = new node;
	node solution;
	ofstream ofs;
	ofs.open("log.txt");
	ofs << "Welcome to the Log File! \n";
	for (int i = 0; i < array.size(); i++) {
		if (array[i] < 0) {
			ofs << "Error: Negative Number: " << array[i] << endl;
			cout << "Error: Negative Number: " << array[i] << endl;
		}
		else if (head == NULL || array[i] < head->value.as) {
			
			temp = head;
			head = new node;
			head->value.as = array[i];
			head->next = temp;
		}
		else {
			prior = head;
			current = head->next;
			while (current != NULL && array[i] >= current->value.as) {
				prior = current;
				current = current->next;
			}
			if (prior->value.as == array[i]) {
			}
			else {
				temp = new node;
				temp->value.as = array[i];
				temp->next = current;
				prior->next = temp;

			}
		}
	}
	ofs.close();
	solution.next = head->next;
	solution.value.as = head->value.as;
	return solution;

}



node fromFileDs(vector<int> array) {
	node *head = NULL;
	node *current;
	node *temp;
	node *prior = new node;
	node solution;

	for (int i = 0; i < array.size(); i++) {
		if (array[i] < 0) {
		}
		else if (head == NULL || array[i] > head->value.ds) {

			temp = head;
			head = new node;
			head->value.ds = array[i];
			head->next = temp;
		}
		else {
			prior = head;
			current = head->next;
			while (current != NULL && array[i] <= current->value.ds) {
				prior = current;
				current = current->next;
			}
			if (prior->value.ds == array[i]) {
			}
			else {
				temp = new node;
				temp->value.ds = array[i];
				temp->next = current;
				prior->next = temp;

			}
		}
	}
	solution.next = head->next;
	solution.value.ds = head->value.ds;
	return solution;
}

node fromFileEvenAs(vector<int> array) {
	node *head = NULL;
	node *current;
	node *temp;
	node *prior = new node;
	node solution;

	for (int i = 0; i < array.size(); i++) {
		if (array[i] < 0) {
		}
		
		else if (head == NULL || (array[i] < head->value.evenas && array[i] % 2 == 0)) {
			if (array[i] % 2 == 0) {
				temp = head;
				head = new node;
				head->value.evenas = array[i];
				head->next = temp;

			}
		}
		else if(array[i] % 2 == 0) {
			prior = head;
			current = head->next;
			while (current != NULL && array[i] >= current->value.evenas) {
				prior = current;
				current = current->next;
			}
			if (prior->value.as == array[i]) {
			}
			else {
				temp = new node;
				temp->value.evenas = array[i];
				temp->next = current;
				prior->next = temp;

			}
		}
	}
	solution.next = head->next;
	solution.value.evenas = head->value.evenas;
	return solution;

}

node fromFileEvenDs(vector<int> array) {
	node *head = NULL;
	node *current;
	node *temp;
	node *prior = new node;
	node solution;

	for (int i = 0; i < array.size(); i++) {
		if (array[i] < 0) {
		}

		else if (head == NULL || (array[i] > head->value.evends && array[i] % 2 == 0)) {
			if (array[i] % 2 == 0) {
				temp = head;
				head = new node;
				head->value.evends = array[i];
				head->next = temp;

			}
		}
		else if (array[i] % 2 == 0) {
			prior = head;
			current = head->next;
			while (current != NULL && array[i] <= current->value.evends) {
				prior = current;
				current = current->next;
			}
			if (prior->value.as == array[i]) {
			}
			else {
				temp = new node;
				temp->value.evends = array[i];
				temp->next = current;
				prior->next = temp;

			}
		}
	}
	solution.next = head->next;
	solution.value.evends = head->value.evends;
	return solution;

}


void printAs(node list) {
	node *current = list.next;
	cout << list.value.as << endl;
	while (current != NULL) {
		cout << current->value.as << endl;
		current = current->next;
	}
}

void printDs(node list) {
	node *current = list.next;
	cout << list.value.ds << endl;
	while (current != NULL) {
		cout << current->value.ds << endl;
		current = current->next;
	}
}

void printEvenAs(node list) {
	node *current = list.next;
	cout << list.value.evenas << endl;
	while (current != NULL) {
		cout << current->value.evenas << endl;
		current = current->next;
	}
}

void printEvenDs(node list) {
	node *current = list.next;
	cout << list.value.evends << endl;
	while (current != NULL) {
		cout << current->value.evends << endl;
		current = current->next;
	}
}


int main() {
	vector<int> array;
	int integer;
	node aslist;
	node dslist;
	node evenasList;
	node evendsList;
	int input;
	int choice;
	ifstream ins;
	bool done = false;
	ins.open("integer.dat");

	//use to check if file is empty
	streampos current = ins.tellg();
	ins.seekg(0, ins.end);
	bool empty = !ins.tellg(); // true if empty file
	ins.seekg(current, ins.beg); //restore stream position


	if (empty) {
		cout << "No data in file!" << endl;
		system("pause");
		return 0;

	}
	else if (ins.is_open()) {
		cout << "File Successfully Opened! \n \n";
		while (ins >> integer) {
			array.push_back(integer);
		}

	}
	else {
		cout << "No file found!" << endl;
		system("pause");
		return 0;
	}

	cout << "Hey there Josh, I bet you are having fun!.... \n";

	while (!done) {
	cout << "Choose from the list: \n";
	cout << "Print Ascending List (1) \n";
	cout << "Print Descending List (2) \n";
	cout << "Print Ascending Even List (3) \n";
	cout << "Print Descending Even List (4) \n";
	cout << "Insert a value (5) \n";
	cout << "Delete a value (6) \n";
	cout << "Quit (7) \n";
	cout << "Choice: ";
	cin >> choice;

		switch (choice) {
		case 1:
			cout << "Ascending List: " << endl;
			aslist = fromFileAs(array);
			printAs(aslist);
			cout << endl;
			break;
		case 2:
			cout << "Descending List: " << endl;
			dslist = fromFileDs(array);
			printDs(dslist);
			cout << endl;
			break;
		case 3: 
			cout << "Even Ascending List: " << endl;
			evenasList = fromFileEvenAs(array);
			printEvenAs(evenasList);
			cout << endl;
			break;
		case 4: 
			cout << "Even Descending List: " << endl;
			evendsList = fromFileEvenDs(array);
			printEvenDs(evendsList);
			cout << endl;
			break;
		case 5: 
		{
			//add to list
			bool pos = true;
			cout << "Enter an int to add to the list: ";
			cin >> input;
			cout << endl;
			if (input < 0) {
				pos = false;
			}
			bool inList = false;
			for (int i = 0; i < array.size(); i++) {
				if (array[i] == input) {
					inList = true;
				}
			}

			if (inList && pos) {
				cout << "In List Already! \n" << endl;
			}
			else if (pos){
				array.push_back(input);
				cout << "Added to list!" << endl;

				aslist = fromFileAs(array);
				printAs(aslist);
				cout << endl;

			}
			else if (!pos) {
				cout << "Cannot add a negative Number! \n";
			}
		}
			break;
		case 6: 
		{
			cout << "Enter number to delete: ";
			cin >> input;
			int num;
			bool notInList = true;
			for (int i = 0; i < array.size(); i++) {
				if (array[i] == input) {
					num = i;
					notInList = false;
				}
			}

			if (notInList) {
				cout << "Not in List!" << endl;
			}
			else {
				cout << "Deleted!" << endl;
				array.erase(array.begin() + num);
			}
			aslist = fromFileAs(array);
			printAs(aslist);
		}
			break;
			
		case 7:
			cout << "Thank you for using the program! \n ";
			done = true;
			break;
		default:
			cout << "Error: Invlalid Input! \n ";
		}
	}
	ins.close();
	system("pause");
	return 0;
}