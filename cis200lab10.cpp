#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

struct clientData {
	int accountNumber;
	char lastName[15];
	char firstName[10];
	float balance;
};

int main() {
	ofstream outCredit("credit.dat", ios::out);
	int num;
	clientData blankClient = { 0,"","",0.0 };
	for (int i = 0; i < 100; i++) {
		outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(clientData));
		outCredit.flush();
	}
	clientData client;
	bool done = false;
	ofstream outCredit1("credit.dat", ios::ate);

	while (!done) {
		cout << "Enter acct number(1-100, 0 to end input): ";
		cin >> num;
		if (num == 0) {
			done = true;
		}
		else if (num > 100) {
			cout << "Invalid input! \n";
		}
		else {
			client.accountNumber = num;
			cout << "Enter first name: ";
			cin >> client.firstName;
			cout << "Enter last name: ";
			cin >> client.lastName;
			cout << "Enter acct balance: ";
			cin >> client.balance;
			outCredit1.seekp((client.accountNumber - 1) * sizeof(clientData));
			outCredit1.write(reinterpret_cast<const char *>(&client), sizeof(clientData));
			outCredit1.flush();
		}
	}
	ifstream inCredit("credit.dat", ios::in);

	int num2;
	done = false;
	while (!done) {
		cout << "Enter acct number (1-100, 0 to end input):	";
		cin >> num2;
		if (num2 == 0) {
			done = true;
		}
		else if (num2 > 100) {
			cout << "Invalid input! \n";
		}
		else if (num2 < 0) {
			cout << "Invalid inupt! \n";
		}
		else {
			client.accountNumber = num2;
			inCredit.seekg((client.accountNumber - 1) * sizeof(clientData));
			inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));
			cout << "\nAct # " << client.accountNumber << " Name: " << client.firstName << " " << client.lastName << " Balance: " << client.balance << endl;
		}
	}

	inCredit.seekg(0);
	inCredit.read(reinterpret_cast<char *> (&client), sizeof(clientData));
	while (inCredit && !inCredit.eof()) {
		if (client.accountNumber != 0) {
			cout << "\nAct # " << client.accountNumber << " Name: " << client.firstName << " " << client.lastName << " Balance: " << client.balance << endl;

		}
		inCredit.read(reinterpret_cast<char *> (&client), sizeof(clientData));

	}

	outCredit.close();
	inCredit.close();
	outCredit1.close();
	system("pause");
	return 0;
}