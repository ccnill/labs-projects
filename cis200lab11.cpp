#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream ofs;
struct record {
	int num;
	string name;
	int quant;
	double cost;
};

class unSortedArray {
private:
	record u[100];
	
public:
	unSortedArray() {
		for (int i = 0; i < 100; i++) {
			u[i].num = 0, u[i].name = " ", u[i].quant = 0, u[i].cost = 0;
		}
	}
	void addRecord(record a) {
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (u[i].num == 0) {
				u[i].num = a.num, u[i].name = a.name, u[i].quant = a.quant, u[i].cost = a.cost;
				count++;
				break;
			}
		}
		ofs << "UA add: " << count << endl;
	}
	void printAllRecords() {
		for (int i = 0; i < 100; i++) {
			if (u[i].num != 0) {
				cout << "Record #: " << u[i].num << " Name: " << u[i].name << " Quantity: " << u[i].quant << " Cost: " << u[i].cost << endl;
			}
		}
	}
	void updateRecord(int x) {
		int choice;
		char c;
		bool done2 = false;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (u[i].num == x) {
				bool done = false;
				while (!done) {
					cout << "What would you like to edit: \n" << "(1) Record Number \n" << "(2) Name \n" << "(3) Quantity \n" << "(4) Cost \n";
					cin >> choice;
					switch (choice) {
					case 1:
						cout << "Enter a new record #: ";
						cin >> u[i].num;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}
						break;
					case 2:
						cout << "Enter a new name: ";
						cin >> u[i].name;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}

						break;
					case 3:
						cout << "Enter a new quantity: ";
						cin >> u[i].quant;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}

						break;
					case 4:
						cout << "Enter a new cost: ";
						cin >> u[i].cost;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}
						break;
					default:
						cout << "Ivalid Choice! \n";
						break;
					}
				}
			}
			count++;
		}
		ofs << "UA updateRecord: " << count << endl;
	}
	void deleteRecord(int x) {
		int delete1 = 0;
		int count = 0;
		for (int i = 0; i < 99; i++) {
			if (u[i].num == x) {
				cout << "Record " << u[i].num << " deleted \n";
				delete1 = i;
				break;
			}
			count++;
		}
		ofs << "UA deleteRecord: " << count << endl;
		for (int i = delete1; i < 100; i++) {
			if (u[i].num != 0) {
				u[i] = u[i + 1];
			}
			else
				break;
		}
	}
	void getRecord(int x) {
		bool found = false;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (u[i].num == x) {
				cout << "Record #: " << u[i].num << " Name: " << u[i].name << " Quantity: " << u[i].quant << " Cost: " << u[i].cost << endl;
				found = true;
				break;
			}
			count++;
		}
		ofs << "UA getRecord: " << count << endl;
		if (found == false) {
			cout << "Record not found! \n";
		}
	}
};

class sortedArray {
private:
	record s[100];
public:
	sortedArray() {
		for (int i = 0; i < 100; i++) {
			s[i].num = 0, s[i].name = " ", s[i].quant = 0, s[i].cost = 0;
		}
	}
	void addRecord(record a) {
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (s[i].num == 0) {
				s[i].num = a.num, s[i].name = a.name, s[i].quant = a.quant, s[i].cost = a.cost;
				
				break;
			}
		}
		record temp;
		for (int i = 0; i < 100; i++) {
			for (int j = i; j < 100; j++) {
				if ((s[i].num > s[j].num) && s[i].num != 0 && s[j].num != 0) {
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
					count++;
				}
			}
		}
		ofs << "SA add: " << count << endl;
	}
	
	void printAllRecords() {
		for (int i = 0; i < 100; i++) {
			if (s[i].num != 0) {
				cout << "Record #: " << s[i].num << " Name: " << s[i].name << " Quantity: " << s[i].quant << " Cost: " << s[i].cost << endl;
			}
		}
	}

	void updateRecord(int x) {
		int choice;
		char c;
		bool done2 = false;
		record temp;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (s[i].num == x) {
				bool done = false;
				while (!done) {
					cout << "What would you like to edit: \n" << "(1) Record Number \n" << "(2) Name \n" << "(3) Quantity \n" << "(4) Cost \n";
					cin >> choice;
					switch (choice) {
					case 1:
						cout << "Enter a new record #: ";
						cin >> s[i].num;
						for (int i = 0; i < 100; i++) {
							for (int j = i; j < 100; j++) {
								if (s[i].num > s[j].num) {
									temp = s[i];
									s[i] = s[j];
									s[j] = temp;
								}
							}
						}
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}
						break;
					case 2:
						cout << "Enter a new name: ";
						cin >> s[i].name;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}

						break;
					case 3:
						cout << "Enter a new quantity: ";
						cin >> s[i].quant;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}

						break;
					case 4:
						cout << "Enter a new cost: ";
						cin >> s[i].cost;
						done2 = false;
						while (!done2) {
							cout << "Done editing this account? (y , n): ";
							cin >> c;
							if (c == 'y') {
								done = true;
								done2 = true;
							}
							else if (c == 'n') {
								done = false;
								done2 = true;
							}
							else {
								cout << "Invalid input! \n";
							}
						}
						break;
					default:
						cout << "Ivalid Choice! \n";
						break;
					}
				}
			}
			count++;
		}
		ofs << "SA updateRecord: " << count << endl;
	}
	void deleteRecord(int x) {
		int delete1 = 0;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (s[i].num == x) {
				cout << "Record " << s[i].num << " deleted \n";
				delete1 = i;
				break;
			}
			count++;
		}
		ofs << "SA deleteRecord: " << count << endl;
		for (int i = delete1; i < 99; i++) {
			if (s[i].num != 0) {
				s[i] = s[i + 1];
				s[i + 1].num = 0, s[i + 1].name = " ", s[i + 1].quant = 0, s[i + 1].cost = 0;
			}
			else
				break;
		}	
	}
	void getRecord(int x) {
		bool found = false;
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (s[i].num == x && s[i].num != 0) {
				cout << "Record #: " << s[i].num << " Name: " << s[i].name << " Quantity: " << s[i].quant << " Cost: " << s[i].cost << endl;
				found = true;
				break;
			}
			count++;
		}
		ofs << "SA getRecord: " << count << endl;
		if (found == false) {
			cout << "Record not found! \n";
		}
	}
};

class list {
	struct node {
		record data;
		node* next;
	};
	node *top;
public:
	list() {
		top = nullptr;
		
	}

	void add(const record& x) {
		node *temp = new node;
		temp->data = x;
		temp->next = top;
		top = temp;
		ofs << "LL add: 1 \n";
	}

	void printAll() {
		node *current = top;
		while (current != nullptr) {
			cout << "Record #: " << current->data.num << " Name: " << current->data.name
				<< " Quantity: " << current->data.quant << " Cost: " << current->data.cost << endl;
			current = current->next;
		}
	}

	void updateRecord(int x) {
		node *current = top;
		bool done = false;
		int count = 0;
		while (current->data.num != x) {
			current = current->next;
			if (current == nullptr) {
				done = true;
				break;
			}
			count++;
		}
		if (done == true) {
			cout << "Record not found! \n";
			return;
		}
		ofs << "LL update record: " << count << endl;

		int choice;
		char c;
		done = false;
		bool done2 = false;
		while (!done) {
			cout << "What would you like to edit: \n" << "(1) Record Number \n" << "(2) Name \n" << "(3) Quantity \n" << "(4) Cost \n";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Enter a new record #: ";
				cin >> current->data.num;
				done2 = false;
				while (!done2) {
					cout << "Done editing this account? (y , n): ";
					cin >> c;
					if (c == 'y') {
						done = true;
						done2 = true;
					}
					else if (c == 'n') {
						done = false;
						done2 = true;
					}
					else {
						cout << "Invalid input! \n";
					}
				}
				break;
			case 2:
				cout << "Enter a new name: ";
				cin >> current->data.name;
				done2 = false;
				while (!done2) {
					cout << "Done editing this account? (y , n): ";
					cin >> c;
					if (c == 'y') {
						done = true;
						done2 = true;
					}
					else if (c == 'n') {
						done = false;
						done2 = true;
					}
					else {
						cout << "Invalid input! \n";
					}
				}

				break;
			case 3:
				cout << "Enter a new quantity: ";
				cin >> current->data.quant;
				done2 = false;
				while (!done2) {
					cout << "Done editing this account? (y , n): ";
					cin >> c;
					if (c == 'y') {
						done = true;
						done2 = true;
					}
					else if (c == 'n') {
						done = false;
						done2 = true;
					}
					else {
						cout << "Invalid input! \n";
					}
				}

				break;
			case 4:
				cout << "Enter a new cost: ";
				cin >> current->data.cost;
				done2 = false;
				while (!done2) {
					cout << "Done editing this account? (y , n): ";
					cin >> c;
					if (c == 'y') {
						done = true;
						done2 = true;
					}
					else if (c == 'n') {
						done = false;
						done2 = true;
					}
					else {
						cout << "Invalid input! \n";
					}
				}
				break;
			default:
				cout << "Ivalid Choice! \n";
				break;
			}
		}
	}
	void deleteRecord(int x) {
		node *temp1 = top;
		if (temp1->data.num == x) {
			top = temp1->next;
			delete temp1;
			return;
		}
		int count = 0;
		while (temp1 != nullptr && temp1->data.num != x) {
			temp1 = temp1->next;
			count++;
		}
		ofs << "LL deleteRecord: " << count << endl;
		cout << "Record " << temp1->data.num << " deleted! \n";
		node *prev = new node;
		temp1 = top;
		for (int i = 0; i < count; i++) {
			prev = temp1;
			temp1 = temp1->next;
		}
		prev->next = temp1->next;
		delete temp1;
	}

	void getRecord(int x) {
		node *current = top;
		bool found = false;
		int count = 0;
		while (current != nullptr) {
			if (current->data.num == x) {
				found = true;
				break;
			}
			count++;
			current = current->next;
		}
		if (found == true) {
			cout << "Record #: " << current->data.num << " Name: " << current->data.name
				<< " Quantity: " << current->data.quant << " Cost: " << current->data.cost << endl;
			ofs << "LL getRecord: " << count << endl;
		}
		else {
			cout << "Record not found!\n";
		}
	}
};

int main() {
	ofs.open("out.txt");
	record x[100];
	unSortedArray u;
	sortedArray s;
	list l;
	int num;
	int count = 7;
	for (int i = 0; i < 100; i++) {
		x[i].num = 0, x[i].name = " ", x[i].quant = 0, x[i].cost = 0;
	}
	x[0].num = 3, x[0].name = "Electric_Sander", x[0].quant = 7, x[0].cost = 57.00;
	x[1].num = 17, x[1].name = "Hammer", x[1].quant = 76, x[1].cost = 11.99;
	x[2].num = 24, x[2].name = "Jig_Saw", x[2].quant = 21, x[2].cost = 11.00;
	x[3].num = 39, x[3].name = "Lawn_Mower", x[3].quant = 3, x[3].cost = 79.50;
	x[4].num = 56, x[4].name = "Power_Saw", x[4].quant = 18, x[4].cost = 99.99;
	x[5].num = 68, x[5].name = "Screwdriver", x[5].quant = 106, x[5].cost = 6.99;
	x[6].num = 77, x[6].name = "Sledge_Hammer", x[6].quant = 11, x[6].cost = 21.50;
	x[7].num = 83, x[7].name = "Wrench", x[7].quant = 34, x[7].cost = 7.50;
	for (int i = 0; i < 8; i++) {
		u.addRecord(x[i]);
	}
	for (int i = 0; i < 8; i++) {
		s.addRecord(x[i]);
	}
	for (int i = 0; i < 8; i++) {
		l.add(x[i]);
	}
	
	bool done = false;
	char choice;
	while (!done) {
		cout << "Choose an option: \n";
		cout << "Add Record (a) \n";
		cout << "Delete Record (d) \n";
		cout << "Update Record (u) \n";
		cout << "Print All Records (p) \n";
		cout << "Get a record (g) \n";
		cout << "Quit (q) \n";
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
		case 'a':
			cout << "Enter Record #: ";
			cin >> x[count].num;
			cout << "Enter Record Name: ";
			cin >> x[count].name;
			cout << "Enter Record Quantity: ";
			cin >> x[count].quant;
			cout << "Enter Record Cost: ";
			cin >> x[count].cost;
			u.addRecord(x[count]);
			l.add(x[count]);
			s.addRecord(x[count]);
			break;
		case 'd':
			cout << "Enter the number of the record that you would like to delete: ";
			cin >> num;
			count--;
			u.deleteRecord(num);
			l.deleteRecord(num);
			s.deleteRecord(num);
			break;
		case 'u':
			cout << "Enter the number of the record that you would like to update: ";
			cin >> num;
			u.updateRecord(num);
			l.updateRecord(num);
			s.updateRecord(num);
			break;
		case 'p':
			u.printAllRecords();
			l.printAll();
			s.printAllRecords();
			break;
		case 'q':
			done = true;
			break;
		case 'g':
			cout << "Enter the number of the record that you would like to get: ";
			cin >> num;
			u.getRecord(num);
			l.getRecord(num);
			s.getRecord(num);
			break;
		default:
			cout << "Invalid Input! \n";
			break;
		}
	}


	cout << "Thank you for using the program! \n";
	ofs.close();
	system("pause");
	return 0;
}