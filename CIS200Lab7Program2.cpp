#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};

template<class T> class A {
private:
	T valuea;

public:
	T getValuea() const { return valuea; }
	void setValuea(T x) { valuea = x; }
	A() {}
	A(const A &a) :
		valuea(a.valuea) {}
};
template<class T> class B : public A<T> {
private:
	T valueb;
public:
	T getValueb() const { return valueb; }
	void setValueb(T x) { valueb = x; }
	B() {}
	B(const B &b) :
		valueb(b.valueb) {}
};

int main() {
	B<float> flt;
	B<int> integer;
	B<char> character;
	B<string> string1;
	B<Date> date1;
	int choice;
	float inputFloat;
	int inputInt;
	char inputChar;
	string inputString;
	Date inputDate;
	Date valueA, valueB;
	bool done = false;
	ofstream ofs;
	ofs.open("out.txt");
	while (!done) {
		cout << endl;
		cout << "Hello! Welcome to the program my guy! \n";
		cout << "Choose from one of the following choices:\n";
		cout << "Enter an integer for values A and B (1) \n";
		cout << "Enter a float for values A and B (2) \n";
		cout << "Enter a char for values A and B (3) \n";
		cout << "Enter a string for values A and B (4) \n";
		cout << "Enter a Date for values A and B (5) \n";
		cout << "Print integer values for A and B (6) \n";
		cout << "Print float values for A and B (7) \n";
		cout << "Print char values for A and B (8) \n";
		cout << "Print string values for A and B (9) \n";
		cout << "Print Date values for A and B (10) \n";
		cout << "Quit (11) \n \n";
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "Enter integer value for A: ";
			cin >> inputInt;
			integer.setValuea(inputInt);
			cout << "Enter integer value for B: ";
			cin >> inputInt;
			integer.setValueb(inputInt);
			break;
		case 2:
			cout << "Enter float value for A: ";
			cin >> inputFloat;
			flt.setValuea(inputFloat);
			cout << "Enter float value for B: ";
			cin >> inputFloat;
			flt.setValueb(inputFloat);
			break;
		case 3:
			cout << "Enter char value for A: ";
			cin >> inputChar;
			character.setValuea(inputChar);
			cout << "Enter char value for B: ";
			cin >> inputChar;
			character.setValueb(inputChar);
			break;
		case 4:
			cout << "Enter string value for A: ";
			cin >> inputString;
			string1.setValuea(inputString);
			cout << "Enter string value for B: ";
			cin >> inputString;
			string1.setValueb(inputString);
			break;
		case 5:
			cout << "Enter day value for A: ";
			cin >> inputDate.day;
			cout << "Enter month value for A: ";
			cin >> inputDate.month;
			cout << "Enter year value for A: ";
			cin >> inputDate.year;
			date1.setValuea(inputDate);
			cout << "Enter day value for B: ";
			cin >> inputDate.day;
			cout << "Enter month value for B: ";
			cin >> inputDate.month;
			cout << "Enter year value for B: ";
			cin >> inputDate.year;
			date1.setValueb(inputDate);
			break;
		case 6:
			cout << "Integer value for A: " << integer.getValuea() << endl;
			cout << "Integer value for B: " << integer.getValueb() << endl;
			ofs << "Integer value for A: " << integer.getValuea() << endl;
			ofs << "Integer value for B: " << integer.getValueb() << endl;
			break;
		case 7: 
			cout << "Float value for A: " << flt.getValuea() << endl;
			cout << "Float value for B: " << flt.getValueb() << endl;
			ofs << "Float value for A: " << flt.getValuea() << endl;
			ofs << "Float value for B: " << flt.getValueb() << endl;
			break;
		case 8: 
			cout << "Char value for A: " << character.getValuea() << endl;
			cout << "Char value for B: " << character.getValueb() << endl;
			ofs << "Char value for A: " << character.getValuea() << endl;
			ofs << "Char value for B: " << character.getValueb() << endl;
			break;
		case 9:
			cout << "String value for A: " << string1.getValuea() << endl;
			cout << "String value for B: " <<  string1.getValueb() << endl;
			ofs << "String value for A: " << string1.getValuea() << endl;
			ofs << "String value for B: " << string1.getValueb() << endl;
			break;
		case 10:
			valueA = date1.getValuea();
			valueB = date1.getValueb();
			cout << "Date value for A: " <<"Day: " << valueA.day << " Month: " << valueA.month << " Year: " << valueA.year << endl;
			cout << "Date value for B: " << "Day: " << valueB.day << " Month: " << valueB.month << " Year: " << valueB.year << endl;
			ofs << "Date value for A: " << "Day: " << valueA.day << " Month: " << valueA.month << " Year: " << valueA.year << endl;
			ofs << "Date value for B: " << "Day: " << valueB.day << " Month: " << valueB.month << " Year: " << valueB.year << endl;
			break;
		case 11:
			cout << "Thank you for using my program! \n";
			done = true;
			break;
		default:
			cout << "Invalid Input! \n";
		}
	}
	ofs.close();
	system("pause");
	return 0;
}