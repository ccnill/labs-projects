#include <iostream>
using namespace std;

class vehicle {
public:
	vehicle() {
		age = 0;
		price = 0;
	}
	void setAge(int age1) {
		age = age1;
	}
	void setPrice(float price1) {
		price = price1;
	}
	int getAge() {
		return age;
	}
	float getPrice() {
		return price;
	}

private:
	int age;
	float price;
};

class car :public vehicle {
public:
	car() {
		raceCarStatus = false;
	}
	void setRaceCarStatus(bool status) {
		raceCarStatus = status;
	}
	bool getRaceCarStatus() {
		return raceCarStatus;
	}

private:
	bool raceCarStatus;
};

class truck : public vehicle {
public:
	truck() {
		diesleTypeStatus = false;
	}
	void setDiesleTypeStatus(bool status) {
		diesleTypeStatus = status;
	}
	bool getDiesleTypeStatus() {
		return diesleTypeStatus;
	}
private:
	bool diesleTypeStatus;
};

int main() {
	int age;
	float price;
	bool status2;
	bool done = false, done2 = false;
	char status;
	int choice;
	truck x;
	car y;
	vehicle z;

	while (!done2) {
		cout << "\n Choose an option from the list: \n";
		cout << "Set Vehicle Stats (1) \n";
		cout << "Set Car Stats (2) \n";
		cout << "Set Truck Stats (3) \n";
		cout << "Print Vehicle Stats (4) \n";
		cout << "Print Car Stats (5) \n";
		cout << "Print Truck Stats (6) \n";
		cout << "Print All Stats (7) \n";
		cout << "Exit Program (8) \n";
		cout << "Enter choice (1 - 8): ";
		cin >> choice;
		cout << "\n";

		switch (choice) {

		case 1:
			done = false;
			while (!done) {
				cout << "Enter age for the vehicle: ";
				cin >> age;
				if (age < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Age was set successfully!" << endl;
					z.setAge(age);
					done = true;
				}
			}
			done = false;
			while (!done) {
				cout << "Enter price for the vehicle: ";
				cin >> price;
				if (price < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Price was set successfully!" << endl;
					z.setPrice(price);
					done = true;
				}

			}
			break;

		case 2:
			done = false;
			while (!done) {
				cout << "Enter age for the car: ";
				cin >> age;
				if (age < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Age was set successfully!" << endl;
					y.setAge(age);
					done = true;
				}
			}
			done = false;
			while (!done) {
				cout << "Enter price for the car: ";
				cin >> price;
				if (price < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Price was set successfully!" << endl;
					y.setPrice(price);
					done = true;
				}

			}

			done = false;
			while (!done) {
				cout << "Race car? ('y' , 'n'): ";
				cin >> status;
				if (status == 'y') {
					cout << "Race car status set to true!" << endl;
					y.setRaceCarStatus(true);
					done = true;
				}
				else if (status == 'n') {
					cout << "Race car status set to false!" << endl;
					y.setRaceCarStatus(false);
					done = true;
				}
				else {
					cout << "Error: Invalid Input!" << endl;
				}
			}

			break;
		case 3:
			done = false;
			while (!done) {
				cout << "Enter age for the truck: ";
				cin >> age;
				if (age < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Age was set successfully!" << endl;
					x.setAge(age);
					done = true;
				}
			}
			done = false;
			while (!done) {
				cout << "Enter price for the truck: ";
				cin >> price;
				if (price < 0) {
					cout << "Error: Invalid Input!" << endl;
				}
				else {
					cout << "Price was set successfully!" << endl;
					x.setPrice(price);
					done = true;
				}

			}

			done = false;
			while (!done) {
				cout << "Diesle? ('y' , 'n'): ";
				cin >> status;
				if (status == 'y') {
					cout << "Diesle status set to true!" << endl;
					x.setDiesleTypeStatus(true);
					done = true;
				}
				else if (status == 'n') {
					cout << "Diesle status set to false!" << endl;
					x.setDiesleTypeStatus(false);
					done = true;
				}
				else {

					cout << "Error: Invalid Input!" << endl;
				}
			}

			break;

		case 4: 
			cout << "Vehicle is " << z.getAge() << " years old." << endl;
			cout << "Vehicle is " << z.getPrice() << " dollars." << endl;
			break;

		case 5: 
			cout << "Car is " << x.getAge() << " years old." << endl;
			cout << "Car is " << x.getPrice() << " dollars." << endl;
			if (y.getRaceCarStatus() == true) {
				cout << "Car is a race car!" << endl;
			}
			else {
				cout << "Car is not a race car!" << endl;
			}
			break;
			
		case 6:
			cout << "Truck is " << x.getAge() << " years old." << endl;
			cout << "Truck is " << x.getPrice() << " dollars." << endl;
			if (x.getDiesleTypeStatus() == true) {
				cout << "Truck is diesle!" << endl;
			}
			else {
				cout << "Truck is not diesle!" << endl;
			}
			break;
			
		case 7:
			cout << "Vehicle is " << z.getAge() << " years old." << endl;
			cout << "Vehicle is " << z.getPrice() << " dollars." << endl;

			cout << "Car is " << x.getAge() << " years old." << endl;
			cout << "Car is " << x.getPrice() << " dollars." << endl;
			if (y.getRaceCarStatus() == true) {
				cout << "Car is a race car!" << endl;
			}
			else {
				cout << "Car is not a race car!" << endl;
			}

			cout << "Truck is " << x.getAge() << " years old." << endl;
			cout << "Truck is " << x.getPrice() << " dollars." << endl;
			if (x.getDiesleTypeStatus() == true) {
				cout << "Truck is diesle!" << endl;
			}
			else {
				cout << "Truck is not diesle!" << endl;
			}
			break;

		case 8:
			cout << "Thank you for using the program! \n";
			done2 = true;
			break;

		default:
			cout << "Error: Invalid input!" << endl;
			break;
		}

	}

	system("pause");
	return 0;
}

/*
int main() {
int age;
int price;
bool diesle;
bool done = false;
char diesleStatus;
truck x;

while (!done) {
cout << "Enter age for the truck: ";
cin >> age;
if (age < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Age was set successfully!" << endl;
x.setAge(age);
done = true;
}
}
done = false;
while (!done) {
cout << "Enter price for the truck: ";
cin >> price;
if (price < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Price was set successfully!" << endl;
x.setPrice(price);
done = true;
}

}

done = false;
while (!done) {
cout << "Diesle? ('y' , 'n'): ";
cin >> diesleStatus;
if (diesleStatus == 'y') {
cout << "Diesle status set to true!" << endl;
x.setDiesleTypeStatus(true);
done = true;
}
else if (diesleStatus == 'n') {
cout << "Diesle status set to false!" << endl;
x.setDiesleTypeStatus(false);
done = true;
}
else {
cout << "Error: Invalid Input!" << endl;
}
}


cout << "Truck is " << x.getAge() << " years old." << endl;
cout << "Truck is " << x.getPrice() << " dollars." << endl;
if (x.getDiesleTypeStatus() == true) {
cout << "Truck is diesle!" << endl;
}
else {
cout << "Truck is not diesle!" << endl;
}




system("pause");
return 0;
}

*/

/*
int main() {
int age;
int price;
bool raceCar;
bool done = false;
char raceCarStatus;
car x;

while (!done) {
cout << "Enter age for the car: ";
cin >> age;
if (age < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Age was set successfully!" << endl;
x.setAge(age);
done = true;
}
}
done = false;
while (!done) {
cout << "Enter price for the car: ";
cin >> price;
if (price < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Price was set successfully!" << endl;
x.setPrice(price);
done = true;
}

}

done = false;
while (!done) {
cout << "Race car? ('y' , 'n'): ";
cin >> raceCarStatus;
if (raceCarStatus == 'y') {
cout << "Race car status set to true!" << endl;
x.setRaceCarStatus(true);
done = true;
}
else if (raceCarStatus == 'n') {
cout << "Race car status set to false!" << endl;
x.setRaceCarStatus(false);
done = true;
}
else {
cout << "Error: Invalid Input!" << endl;
}
}


cout << "Car is " << x.getAge() << " years old." << endl;
cout << "Car is " << x.getPrice() << " dollars." << endl;
if (x.getRaceCarStatus() == true) {
cout << "Car is a race car!" << endl;
}
else {
cout << "Car is not a race car!" << endl;
}




system("pause");
return 0;
}

*/


/*
int main() {
float price;
int age;
bool done = false;
vehicle x;

while (!done) {
cout << "Enter age for the vehicle: ";
cin >> age;
if (age < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Age was set successfully!" << endl;
x.setAge(age);
done = true;
}
}
done = false;
while (!done) {
cout << "Enter price for the vehicle: ";
cin >> price;
if (price < 0) {
cout << "Error: Invalid Input!" << endl;
}
else {
cout << "Price was set successfully!" << endl;
x.setPrice(price);
done = true;
}

}

cout << "Vehicle is " << x.getAge() << " years old." << endl;
cout << "Vehicle is " << x.getPrice() << " dollars." << endl;



system("pause");
return 0;
}

*/
