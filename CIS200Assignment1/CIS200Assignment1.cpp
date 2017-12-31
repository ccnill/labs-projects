#include <iostream>
#include "myString.h"
#include <string>
using namespace std;


void printMenu() {
	cout << endl;
	cout << "Choose what you want to do from the list!" << endl;
	cout << "1. See what the size of the current string is" << endl;
	cout << "2. Add to the start of the string" << endl;
	cout << "3. Add to the end of the string" << endl;
	cout << "4. Print the spicified part of the string" << endl;
	cout << "5. Replace part of the string" << endl;
	cout << "6. Replace the whole string" << endl;
	cout << "7. Compare the current string to the one that you input" << endl;
	cout << "8. Enter a new string" << endl;
	cout << "9. Print what is in the current string" << endl;
	cout << "10. Quit" << endl;

}


int main() {

	myString x, y;
	int userChoice;
	int startPos, length;
	x.initString();
	bool done = false;
	string str2;


	while (!done) {

		printMenu();

		cin >> userChoice;
		switch (userChoice) {

			//size
		case 1:
			cout << "Size of the current string is : " << x.size() << endl;
			break;

			//add to start
		case 2:

			cout << "Original string: ";
			x.printString();
			cout << "Enter string that you want to add to the start: ";
			cin >> str2;
			y.setString(str2);
			x.addStart(y);
			break;

			//add end
		case 3:
			cout << "Original string: ";
			x.printString();
			cout << "Enter string that you want to add to the end: ";
			cin >> str2;
			y.setString(str2);
			x.addEnd(y);
			break;

			//print part of string
		case 4:
			cout << "Enter a starting position: ";
			cin >> startPos;
			cout << "Enter a length: ";
			cin >> length;
			x.partString(startPos, length);
			break;

			//replace part of string
		case 5:
			cout << "Enter a starting position: ";
			cin >> startPos;
			cout << "Enter what you want to input: ";
			cin >> str2;
			y.setString(str2);
			x.replPartString(y, startPos);
			break;

			//replace whole string
		case 6:
			cout << "Input the string that you want to replace the current string with: ";
			cin >> str2;
			y.setString(str2);
			x.replWholeString(y);
			break;

			//compare string
		case 7:
			cout << "Enter a string to compare to the current string:" << endl;
			cin >> str2;
			y.setString(str2);
			x.compareString(y);
			break;

			//set string
		case 8:
			cout << "Enter your string: ";
			cin >> str2;
			x.setString(str2);
			break;

			//print string
		case 9:
			cout << "Current string : " << endl;
			x.printString();
			break;

			//end program
		case 10:
			done = true;
			break;

		default:
			cout << "Error: Invalid input!" << endl;
		}

	}

	system("pause");
	return 0;
}