#include <iostream>	
#include <sstream>
#include <math.h>
using namespace std;

class account {
protected:
	long acctNum;
	double balance;
public:
	account(long acct, double bal) {
		balance = bal;
		acctNum = acct;
	}
	long getAcct() {
		return acctNum;
	}
	double getBalance() {
		return balance;
	}
	void setAcct(long a) {
		acctNum = a;
	}
	void setBalance(double b) {
		balance = b;
	}
	virtual void setRate(int r) {
	}
	virtual double getRate() {
		return 0;
	}
	virtual double computeIntr(int years) {
		return 0;
	}
	virtual double getMinIntrBalance() {
		return 0;
	}
	virtual void setMinIntrBalance(double lowestBalance) {
	}
	account() {
		balance = 0.0;
		acctNum = 0;
	}
	virtual string toString() {
		
		return NULL;
	}
	virtual bool checkBalRate(double r) {
		return true;
	}
	virtual bool checkRate(int r) {
		return true;
	}


};
//100 - 200
class checking : public account {
protected:
	double minIntrbalance;
	int rate;
public:
	checking() {
		rate = 0;
		minIntrbalance = 0;
	}
	checking(long acct, double bal) {
		acctNum = acct;
		balance = bal;
	}
	double getMinIntrBalance() {
		return minIntrbalance;
	}
	void setMinIntrBalance(double lowestBalance) {
		minIntrbalance = lowestBalance;
	}
	double getRate() {
		return rate;
	}
	void setRate(int r) {
		try {
			if (r < 0) {
				throw 10;
			}
			else {
				rate = r;
			}
		}
		catch (int x) {
			cout << "Interest rate cannot be negative! \n";
		}
	}
	bool checkRate(int r) {
		try {
			if (r < 0) {
				throw 10;
			}
			else
				return true;
		}
		catch (int x) {
			return false;
		}
	}
	double computeIntr(int years) {
		double b = balance - minIntrbalance;
		
		double intr;
		double rt = (rate * 0.01);
		double rtxb = (rt * b);
		intr = (rtxb * years);
		return intr;
	}

	bool checkBalRate(double r) {
		try {
			if (r < 0) {
				throw 10;
			}
			else
				return true;
		}
		catch (int x) {
			return false;
		}
	}

	string toString() {
		string a = "Checking Account # = ";
		string num = to_string(acctNum);
		string b = a + num;
		string bal = to_string(balance);
		string c = " Balance = ";
		string d = c + bal;
		string z = " Rate = ";
		string x = to_string(rate);
		string y = to_string(minIntrbalance);
		string h = " Min intrest bal: ";
		string e = b + d + z + x + h + y;
		return e;
	}
};

//200 - 300
class savings : public account {
protected:
	double intRate;
public:
	savings() {
		acctNum = 0;
		balance = 0.0;
	}
	savings(long acct, double bal) {
		acctNum = acct;
		balance = bal;
	}
	double getRate(){
		return intRate;
	}
	void setRate(int r) {
		intRate = r;
	}
	bool checkRate(int r) {
		try {
			if (r < 0) {
				throw 10;
			}
			else
				return true;
		}
		catch (int x) {
			return false;
		}
	}

	double computeIntr(int years) {
		double y, x;
		y = pow((1 + (intRate * .01)), years);
		x = (y * balance) - balance;
		return x;
	}
	string toString() {
		string a = "Savings Account # = ";
		string num = to_string(acctNum);
		string b = a + num;
		string bal = to_string(balance);
		string c = " Balance = ";
		string d = c + bal;
		string z = " Rate = ";
		string x = to_string(intRate);
		string e = b + d + z + x;
		return e;
	}

};

int main() {
	int count = 9;
	bool done2 = false;
	account *a[100];
	checking x0(100, (1000 + (10 * 100))),
		x1(101, (1000 + (10 * 101))),
		x2(102, (1000 + (10 * 102))),
		x3(103, (1000 + (10 * 103))),
		x4(104, (1000 + (10 * 104)));
	a[0] = &x0, a[1] = &x1, a[2] = &x2, a[3] = &x3, a[4] = &x4;
	savings z0(200, (200 + (10 * 200))),
		z1(201, (201 + (10 * 201))),
		z2(202, (202 + (10 * 202))),
		z3(203, (203 + (10 * 203))),
		z4(204, (204 + (10 * 204)));
	z0.setRate(3), z1.setRate(3), z2.setRate(3), z3.setRate(3), z4.setRate(3);
	a[5] = &z0, a[6] = &z1, a[7] = &z2, a[8] = &z3, a[9] = &z4;

	bool dn = false;
	int act1 = -1;
	char input;
	bool done = false;
	savings cx;
	checking xd;
	int rte;
	int years;
	double bal;
	double minBal;
	cout << "\nWelcome to the bank!(I think)\n";
	cout << "\nHere are your choices:	\n";
	cout << "Add Account(a) \n" << "Remove account(r) \n"
		<< "Get Account(g) \n" << "Set Balance(b) \n"
		<< "Set Interest(i) \n" << "Display toString fcn (d) \n"
		<< "Input years and compute interest(c) \n"
		<< "Quit Processing this Acct(q) \n" << "Set min intrest balance(s) \n"
		<< "Quit Program(0) \n";

	while (!done) {
		cout << "Choice: ";
		cin >> input;
		switch (input) {
		case 'a':
			char x;
			dn = false;
			while (!dn) {
				cout << "Savings or checking? (s,c): ";
				cin >> x;
				switch (x) {
				case 's':
					long act;
					double bal;

					cout << "Enter act number (200 - 299): ";
					cin >> act;
					cx.setAcct(act);
					cout << "Enter act balance:	";
					cin >> bal;
					cx.setBalance(bal);
					done2 = false;
					while (!done2) {
						cout << "Enter act intrest rate: ";
						cin >> rte;
						if (cx.checkRate(rte) == false) {
							cout << "ERROR: CAN NOT HAVE NEGATIVE INTEREST RATE!\n";
						}
						else {
							cx.setRate(rte);
							done2 = true;
						}
					}
					a[count] = &cx;
					count++;
					dn = true;
					break;
				case 'c':
					cout << "Enter act number (100 - 199): ";
					cin >> act;
					xd.setAcct(act);
					cout << "Enter act balance: ";
					cin >> bal;
					xd.setBalance(bal);
					done2 = false;
					while (!done2) {
						cout << "Enter act intrest rate: ";
						cin >> rte;
						if (xd.checkRate(rte) == false) {
							cout << "ERROR: CAN NOT HAVE NEGATIVE INTEREST RATE!\n";
						}
						else {
							xd.setRate(rte);
							done2 = true;
						}
					}
					done2 = false;
					while (!done2) {
						cout << "Input min interest balance: ";
						cin >> minBal;
						if (xd.checkBalRate(minBal) == false) {
							cout << "ERROR: CAN NOT HAVE NEGATIVE MIN INTEREST BALANCE! \n";
						}
						else {
							xd.setMinIntrBalance(minBal);
							done2 = true;
						}
					}

					a[count] = &xd;
					count++;
					dn = true;
					break;
				default:
					cout << "Invalid!\n";
					break;
				}

			}
			break;
		case 's':
			done2 = false;

			if (act1 == -1) {
				cout << "Must select an account first! \n";
			}
			else if (a[act1]->getAcct() < 200) {
				while (!done2) {
					cout << "Input min interest balance: ";
					cin >> minBal;
					if (a[act1]->checkBalRate(minBal) == false) {
						cout << "ERROR: CAN NOT HAVE NEGATIVE MIN INTEREST BALANCE! \n";
					}
					else {
						a[act1]->setMinIntrBalance(minBal);
						done2 = true;
					}
				}
			}
			else {
				cout << "Must be a checking account!\n";
			}
			break;
		case 'r':
			long r;
			done2 = false;
			cout << "Enter account that you want to delete: ";
			cin >> r;
			for (int i = 0; i < count; i++) {
				if (a[i]->getAcct() == r) {
					a[i]->setAcct(0);
					a[i]->setBalance(0.0);
					cout << "\nAccount: " << r << " deleted! \n";
					done2 = true;
					count--;
				}
			}
			if (done2 == false) {
				cout << "Account: " << r << " was not found! \n";
			}
			break;
		case 'g':
			cout << "Enter acct to get: ";
			long d;
			cin >> d;
			done2 = false;
			for (int i = 0; i <= count; i++) {
				if (a[i]->getAcct() == d) {
					cout << "Acct: " << a[i]->getAcct() << " found! \n \n";
					act1 = i;
					done2 = true;
					break;
				}
			}
			if (done2 == false) {
				cout << "Account does not exist! \n";
			}
			break;
		case 'b':
			if (act1 == -1) {
				cout << "select an account first! \n";
			}
			else {
				long balance;
				cout << "Enter balance: ";
				cin >> balance;
				a[act1]->setBalance(balance);
			}
			break;
		case 'd':
			if (act1 == -1) {
				cout << "Select an account first! \n";
			}
			else {
				cout << a[act1]->toString() << endl;
			}
			break;
		case 'i':
			done2 = false;
			int interest;
			if (act1 == -1) {
				cout << "Select an account first! \n";
			}
			else {
				while (!done2) {
					cout << "Enter interest: ";
					cin >> interest;
					if (a[act1]->checkRate(interest) == false) {
						cout << "ERROR: CAN NOT HAVE A NEGATIVE RATE! \n";
					}
					else {
						a[act1]->setRate(interest);
						done2 = true;
					}

				}
			}
			break;
		case 'c':
			//checking
			if (act1 == -1) {
				cout << "Select an account first! \n";
			}
			else if (a[act1]->getAcct() < 200) {
				done2 = false;

				if (a[act1]->getMinIntrBalance() < 0) {
					while (!done2) {
						cout << "Input min interest balance: ";
						cin >> minBal;
						if (a[act1]->checkBalRate(minBal) == false) {
							cout << "ERROR: CAN NOT HAVE NEGATIVE MIN INTEREST BALANCE! \n";
						}
						else {
							a[act1]->setMinIntrBalance(minBal);
							done2 = true;
						}
					}
				}
				if (a[act1]->getRate() < 0) {
					done2 = false;
					while (!done2) {
						cout << "Enter interest: ";
						cin >> rte;
						if (a[act1]->checkRate(rte) == false) {
							cout << "ERROR: CAN NOT HAVE A NEGATIVE RATE! \n";
						}
						else {
							a[act1]->setRate(rte);
							done2 = true;
						}

					}
				}
				cout << "Input years: ";
				cin >> years;
				cout << "Interest is: " << a[act1]->computeIntr(years) << "\n";
			}
			//savings
			else {
				cout << "Input years: ";
				cin >> years;
				cout << "Interest: " << a[act1]->computeIntr(years) << "\n";
			}
			break;
		case 'q':
			cout << "Done processing act! \n";
			act1 = -1;
			break;
		case '0':
			done = true;
			break;
		default:
			cout << "Invalid input! \n";
			break;
		}


	}
	cout << "Thank you for using the program my dude, you will be one of the only ppl that see this. \n";

	system("pause");
	return 0;
}