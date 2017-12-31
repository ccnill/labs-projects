#include <iostream>
#include <string>
#include <fstream>



class vehicle {
public:
	vehicle() {
		age = 0;
		price = 0;
		headlights = false;
		radio = false;
		speed = 0.0;
		heading = 'N';
		fuel = 0.0;
		off = true;
		
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
	void setHeadlights(bool h) {
		headlights = h;
	}
	bool getHeadlights() {
		return headlights;
	}
	void setRadio(bool r) {
		radio = r;
	}
	bool getRadio() {
		return radio;
	}
	void setSpeed(float s) {
		speed = s;
	}
	float getSpeed() {
		return speed;
	}
	void setHeading(char h) {
		heading = h;
	}
	char getHeading() {
		return heading;
	}
	void setFuel(float f) {
		fuel = f;
	}
	float getFuel() {
		return fuel;
	}
	void setOff(bool o) {
		off = o;
	}
	bool getOff() {
		return off;
	}
private:
	int age;
	float price;
	bool headlights;
	bool radio;
	float speed;
	char heading;
	float fuel;
	bool off;

};

class landVehicle : public vehicle {
private:
	int gear;
	int numPass;
	float mileage;
	float friction;
	bool awd;
	bool tcs;

public:
	landVehicle() {
		gear = 0;
		numPass = 0;
		mileage = 0.0;
		friction = 0.0;
		awd = false;
		tcs = false;
	}
	void setGear(int g) {
		gear = g;
	}
	int getGear() {
		return gear;
	}
	void setNumPass(int p) {
		numPass = p;
	}
	int getNumPass() {
		return numPass;
	}
	void setMileage(float m) {
		mileage = m;
	}
	float getMileage() {
		return mileage;
	}
	void setFriction(float f) {
		friction = f;
	}
	float getFriction() {
		return friction;
	}
	void setAwd(bool a) {
		awd = a;
	}
	bool getAwd() {
		return awd;
	}
	void setTcs(bool t){
		tcs = t;
	}
	bool getTcs() {
		return tcs;
	}

};


class car :public landVehicle {
public:
	car() {
		raceCarStatus = false;
		top = true;
	}
	void setRaceCarStatus(bool status) {
		raceCarStatus = status;
	}
	bool getRaceCarStatus() {
		return raceCarStatus;
	}
	void setTop(bool t) {
		top = t;
	}
	bool getTop() {
		return top;
	}
private:
	bool raceCarStatus;
	bool top;
};

class truck : public landVehicle {
public:
	truck() {
diesleTypeStatus = false;
cargo = false;
capacity = 0.0;
	}
	void setDiesleTypeStatus(bool status) {
		diesleTypeStatus = status;
	}
	bool getDiesleTypeStatus() {
		return diesleTypeStatus;
	}
	void setCargo(bool c) {
		cargo = c;
	}
	bool getCargo() {
		return cargo;
	}
	void setCapacity(float c) {
		capacity = c;
	}
	float getCapacity() {
		return capacity;
	}
private:
	bool diesleTypeStatus;
	bool cargo;
	float capacity;
};

class plane : public vehicle {
private:
	float altitude;
	bool takeOff;
public:
	plane() {
		altitude = 0.0;
		takeOff = false;
	}
	void setAlt(float a) {
		altitude = a;
	}
	float getAlt() {
		return altitude;
	}
	void setTakeOff(bool t) {
		takeOff = t;
	}
	bool getTakeOff() {
		return takeOff;
	}
};

class boat : public vehicle {
private:
	bool anchor;
	bool launch;
public:
	boat() {
		anchor = true;
		launch = false;
	}
	void setAnchor(bool a) {
		anchor = a;
	}
	bool getAnchor() {
		return anchor;
	}
	void setLaunch(bool l) {
		launch = l;
	}
	bool getLaunch() {
		return launch;
	}
};

car c;
truck t;
plane p;
boat b;

void choseTruck(std::ofstream&);
void choseCar(std::ofstream& );
void choseBoat(std::ofstream&);
void chosePlane(std::ofstream&);

int main() {
	bool done = false;
	std::string inputS;
	std::ofstream ofs;
	ofs.open("out.txt");


	while (!done) {
		std::cout << "Which vehicle are you taking(type done if you are done with the trip): ";
		getline(std::cin, inputS);

		if (inputS == "car") {
			choseCar(ofs);
		}
		else if (inputS == "truck") {
			choseTruck(ofs);
		}
		else if (inputS == "plane") {
			chosePlane(ofs);
		}
		else if (inputS == "boat") {
			choseBoat(ofs);
		}
		else if (inputS == "done") {
			std::cout << "Trip ended! \n";
			ofs << "Trip ended! \n";
			done = true;
		}
		else {
			std::cout << "Invalid vehicle! \n";
			std::cout << "Choices are: car, truck, plane, boat \n";
		}
	}
	ofs.close();
	system("pause");
	return 0;
}

void choseCar(std::ofstream& ofs) {

	std::string input;
	char inputC;
	float inputI;
	bool done = false;
	std::cout << "Car selected! \n";
	ofs << "Car selected! \n";
	while (!done) {
		std::cout << "Action: ";
		getline(std::cin, input);

		if (input == "start engine") {
			if (c.getOff() == true) {
				std::cout << "Engine Started! \n";
				ofs << "Engine Started! \n";
				c.setOff(false);
			}
			else {
				std::cout << "Engine is already on! \n";
				ofs << "Engine is already on! \n";
			}
		}
		else if (input == "turn off engine") {
			if (c.getOff() == false) {
				std::cout << "Engine turned off! \n";
				ofs << "Engine turned off! \n";
				c.setOff(true);
			}
			else {
				std::cout << "Engine is already off! \n";
				ofs << "Engine is already off! \n";

			}
		}
		else if (input == "turn on radio") {
			if (c.getRadio() == false) {
				std::cout << "Radio turned on! \n";
				ofs << "Radio turned on! \n";
				c.setRadio(true);
			}
			else {
				std::cout << "Radio is already on! \n";
				ofs << "Radio is already on! \n";
			}
		}
		else if (input == "turn off radio") {
			if (c.getRadio() == false) {
				std::cout << "Radio is already off! \n";
				ofs << "Radio is already off! \n";
			}
			else {
				c.setRadio(false);
				std::cout << "Radio turned off! \n";
				ofs << "Radio turned off! \n";
			}
		}
		else if (input == "set gear") {
			std::cout << "What gear?";
			std::cin >> inputI;
			c.setGear(inputI);
			std::cout << "Gear set to: " << inputI << std::endl;
			ofs << "Gear set to: " << inputI << std::endl;
		}
		else if (input == "get gear") {
			std::cout << "Gear is: " << c.getGear() << "\n";
			ofs << "Gear is: " << c.getGear() << "\n";
		}
		else if (input == "take off top") {
			if (c.getTop() == true) {
				std::cout << "Top is taken off! \n";
				ofs << "Top is taken off! \n";
				c.setTop(false);
			}
			else {
				std::cout << "Top is already off! \n";
				ofs << "Top is already off! \n";
			}
		}
		else if (input == "put top on") {
			if (c.getTop() == true) {
				std::cout << "Top is already on! \n";
				ofs << "Top is already on! \n";
			}
			else {
				c.setTop(true);
				std::cout << "Top put on! \n";
				ofs << "Top put on! \n";
			}
		}
		else if (input == "set speed") {
			if (c.getOff() == true) {
				std::cout << "Car is not on! \n";
				ofs << "Car is not on! \n";
			}
			else {
				std::cout << "Enter speed: ";
				std::cin >> inputI;
				c.setSpeed(inputI);
				std::cout << "Speed set to " << inputI << " mph\n";
				ofs << "Speed set to " << inputI << " mph\n";
			}
		}
		else if (input == "get speed") {
			std::cout << "Speed is: " << c.getSpeed() << " mph \n";
			ofs << "Speed is: " << c.getSpeed() << " mph \n";
		}
		else if (input == "set heading") {
			bool done2 = false;
			while (!done2) {
				std::cout << "What direction? ";
				std::cout << "ex.(N,S,E,W)\n";
				std::cin >> inputC;
				if (inputC == 'N' || inputC == 'S' || inputC == 'E' || inputC == 'W') {
					c.setHeading(inputC);
					std::cout << "Direction set to " << inputC << "\n";
					ofs << "Direction set to " << inputC << "\n";
					done2 = true;
				}
				else {
					std::cout << "Invalid Direction! \n";
				}
			}
		}
		else if (input == "get heading") {
			std::cout << "Heading is: " << c.getHeading() << "\n";
			ofs << "Heading is: " << c.getHeading() << "\n";
		}
		else if (input == "set number of passengers") {
			std::cout << "Enter number of passengers: ";
			std::cin >> inputI;
			c.setNumPass(inputI);
			std::cout << "Number of passengers set to: " << inputI << "\n";
			ofs << "Number of passengers set to: " << inputI << "\n";
		}
		else if (input == "get number of passengers") {
			std::cout << "Number of Passengers is: " << c.getNumPass() << "\n";
			ofs << "Number of Passengers is: " << c.getNumPass() << "\n";
		}
		else if (input == "turn on headlights") {
			if (c.getHeadlights() == false) {
				c.setHeadlights(true);
				std::cout << "Headlights turned on! \n";
				ofs << "Headlights turned on! \n";
			}
			else {
				std::cout << "Headlights already on! \n";
				ofs << "Headlights already on! \n";
			}
		}
		else if (input == "turn off headlights") {
			if (c.getHeadlights() == true) {
				c.setHeadlights(false);
				std::cout << "Headlights turned off! \n";
				ofs << "Headlights turned off! \n";
			}
			else {
				std::cout << "Headlights already on! \n";
				ofs << "Headlights already on! \n";
			}
		}
		else if (input == "set fuel") {
			std::cout << "Enter how many gal: ";
			std::cin >> inputI;
			c.setFuel(inputI);
			std::cout << "Fuel set to: " << inputI << " gallons \n";
			ofs << "Fuel set to: " << inputI << " gallons \n";
		}
		else if (input == "get fuel") {
			std::cout << "Fuel level is: " << c.getFuel() << " gallons \n";
			ofs << "Fuel level is: " << c.getFuel() << " gallons \n";
		}
		else if (input == "set age") {
			std::cout << "Enter age: ";
			std::cin >> inputI;
			c.setAge(inputI);
			std::cout << "Age set to: " << inputI << "\n";
			ofs << "Age set to: " << inputI << "\n";
		}
		else if (input == "get age") {
			std::cout << "Age is: " << c.getAge() << "\n";
			ofs << "Age is: " << c.getAge() << "\n";
		}
		else if (input == "set mileage") {
			std::cout << "Enter mileage: ";
			std::cin >> inputI;
			c.setMileage(inputI);
			std::cout << "Mileage set to: " << inputI << " miles \n";
			ofs << "Mileage set to: " << inputI << " miles \n";
		}
		else if (input == "get mileage") {
			std::cout << "Mileage is: " << c.getMileage() << "miles \n";
			ofs << "Mileage is: " << c.getMileage() << "miles \n";
		}
		else if (input == "turn on awd") {
			if (c.getAwd() == false) {
				c.setAwd(true);
				std::cout << "Awd is turned on! \n";
				ofs << "Awd is turned on! \n";
			}
			else {
				std::cout << "Awd is already on! \n";
				ofs << "Awd is already on! \n";
			}
		}
		else if (input == "turn off awd") {
			if (c.getAwd() == true) {
				c.setAwd(false);
				std::cout << "Awd is turned off! \n	";
				ofs << "Awd is turned off! \n";
			}
			else {
				std::cout << "Awd is already off! \n";
				ofs << "Awd is already off! \n";
			}
		}
		else if (input == "set friction") {
			std::cout << "Enter friction: ";
			std::cin >> inputI;
			c.setFriction(inputI);
			std::cout << "Friction set to: " << inputI << "\n";
			ofs << "Friction set to: " << inputI << "\n";
		}
		else if (input == "get friction") {
			std::cout << "Friction is: " << c.getFriction() << "\n";
			ofs << "Friction is: " << c.getFriction() << "\n";
		}
		else if (input == "turn on tcs") {
			if (c.getTcs() == false) {
				c.setTcs(true);
				std::cout << "Tcs turned on! \n";
				ofs << "Tcs turned on! \n";
			}
			else {
				std::cout << "Tcs is already on! \n";
				ofs << "Tcs is already on! \n";
			}
		}
		else if (input == "turn off tcs") {
			if (c.getTcs() == true) {
				c.setTcs(false);
				std::cout << "Tcs is turned off! \n";
				ofs << "Tcs is turned off! \n";
			}
			else {
				std::cout << "Tcs is already off! \n";
				ofs << "Tcs is already off! \n";
			}
		}
		else if (input == "set race car to true") {
			if (c.getRaceCarStatus() == false) {
				c.setRaceCarStatus(true);
				std::cout << "Car set to race car! \n";
				ofs << "Car set to race car! \n";
			}
			else {
				std::cout << "Car is already a race car! \n";
				ofs << "Car is already a race car! \n";
			}
		}
		else if (input == "set race car to false") {
			if (c.getRaceCarStatus() == true) {
				c.setRaceCarStatus(false);
				std::cout << "Race car set to false! \n";
				ofs << "Race car set to false! \n";
			}
			else {
				std::cout << "Car is already not a race car! \n";
				ofs << "Car is already not a race car! \n";
			}
		}
		else if (input == "set price") {
			std::cout << "Enter price: ";
			std::cin >> inputI;
			c.setPrice(inputI);
			std::cout << "Price set to: " << inputI << " dollars \n";
			ofs << "Price set to: " << inputI << " dollars \n";
		}
		else if (input == "get price") {
			std::cout << "Price is: " << c.getPrice() << " dollars \n";
			ofs << "Price is: " << c.getPrice() << " dollars \n";
		}
		else if (input == "exit car") {
			std::cout << "Exiting car! \n";
			ofs << "Exiting car! \n";
			bool done3 = false;
			while (!done3) {
				std::cout << "Would you like to enter another vehicle? (yes or no): ";
				getline(std::cin, input);
				if (input == "yes") {
					return;
	
				}
				else if (input == "no") {
					return;
				}
				else {
					std::cout << "Invalid Input! \n";
				}
			}
		}
	}
}

void choseTruck(std::ofstream& ofs) {
	std::string input;
	char inputC;
	float inputI;
	bool done = false;
	std::cout << "Truck selected! \n";
	ofs << "Truck selected! \n";
	while (!done) {
		std::cout << "Action: ";
		getline(std::cin, input);

		if (input == "start engine") {
			if (t.getOff() == true) {
				std::cout << "Engine Started! \n";
				ofs << "Engine Started! \n";
				t.setOff(false);
			}
			else {
				std::cout << "Engine is already on! \n";
				ofs << "Engine is already on! \n";
			}
		}
		else if (input == "turn off engine") {
			if (t.getOff() == false) {
				std::cout << "Engine turned off! \n";
				ofs << "Engine turned off! \n";
				t.setOff(true);
			}
			else {
				std::cout << "Engine is already off! \n";
				ofs << "Engine is already off! \n";

			}
		}
		else if (input == "turn on radio") {
			if (t.getRadio() == false) {
				std::cout << "Radio turned on! \n";
				ofs << "Radio turned on! \n";
				t.setRadio(true);
			}
			else {
				std::cout << "Radio is already on! \n";
				ofs << "Radio is already on! \n";
			}
		}
		else if (input == "turn off radio") {
			if (t.getRadio() == false) {
				std::cout << "Radio is already off! \n";
				ofs << "Radio is already off! \n";
			}
			else {
				t.setRadio(false);
				std::cout << "Radio turned off! \n";
				ofs << "Radio turned off! \n";
			}
		}
		else if (input == "set gear") {
			std::cout << "What gear?";
			std::cin >> inputI;
			t.setGear(inputI);
			std::cout << "Gear set to: " << inputI << std::endl;
			ofs << "Gear set to: " << inputI << std::endl;
		}
		else if (input == "get gear") {
			std::cout << "Gear is: " << t.getGear() << "\n";
			ofs << "Gear is: " << t.getGear() << "\n";
		}
		else if (input == "load cargo") {
			if (t.getCargo() == false) {
				t.setCargo(true);
				std::cout << "Cargo is loaded! \n";
				ofs << "Cargo is loaded! \n";
			}
			else {
				std::cout << "There is already cargo in the truck! \n";
				ofs << "There is already cargo in the truck! \n";
			}
		}
		else if (input == "unload cargo") {
			if (t.getCargo() == true) {
				t.setCargo(false);
				std::cout << "Cargo is unloaded! \n";
				ofs << "Cargo is unloaded! \n";
			}
			else {
				std::cout << "No cargo to unload! \n";
				ofs << "No cargo to unload!\n";
			}
		}
		else if (input == "set speed") {
			if (t.getOff() == true) {
				std::cout << "Car is not on! \n";
				ofs << "Car is not on! \n";
			}
			else {
				std::cout << "Enter speed: ";
				std::cin >> inputI;
				t.setSpeed(inputI);
				std::cout << "Speed set to " << inputI << " mph\n";
				ofs << "Speed set to " << inputI << " mph\n";
			}
		}
		else if (input == "get speed") {
			std::cout << "Speed is: " << t.getSpeed() << " mph \n";
			ofs << "Speed is: " << t.getSpeed() << " mph \n";
		}
		else if (input == "set heading") {
			bool done2 = false;
			while (!done2) {
				std::cout << "What direction? ";
				std::cout << "ex.(N,S,E,W)\n";
				std::cin >> inputC;
				if (inputC == 'N' || inputC == 'S' || inputC == 'E' || inputC == 'W') {
					t.setHeading(inputC);
					std::cout << "Direction set to " << inputC << "\n";
					ofs << "Direction set to " << inputC << "\n";
					done2 = true;
				}
				else {
					std::cout << "Invalid Direction! \n";
				}
			}
		}
		else if (input == "get heading") {
			std::cout << "Heading is: " << t.getHeading() << "\n";
			ofs << "Heading is: " << t.getHeading() << "\n";
		}
		else if (input == "set number of passengers") {
			std::cout << "Enter number of passengers: ";
			std::cin >> inputI;
			t.setNumPass(inputI);
			std::cout << "Number of passengers set to: " << inputI << "\n";
			ofs << "Number of passengers set to: " << inputI << "\n";
		}
		else if (input == "get number of passengers") {
			std::cout << "Number of Passengers is: " << t.getNumPass() << "\n";
			ofs << "Number of Passengers is: " << t.getNumPass() << "\n";
		}
		else if (input == "turn on headlights") {
			if (t.getHeadlights() == false) {
				t.setHeadlights(true);
				std::cout << "Headlights turned on! \n";
				ofs << "Headlights turned on! \n";
			}
			else {
				std::cout << "Headlights already on! \n";
				ofs << "Headlights already on! \n";
			}
		}
		else if (input == "turn off headlights") {
			if (t.getHeadlights() == true) {
				t.setHeadlights(false);
				std::cout << "Headlights turned off! \n";
				ofs << "Headlights turned off! \n";
			}
			else {
				std::cout << "Headlights already on! \n";
				ofs << "Headlights already on! \n";
			}
		}
		else if (input == "set fuel") {
			std::cout << "Enter how many gal: ";
			std::cin >> inputI;
			t.setFuel(inputI);
			std::cout << "Fuel set to: " << inputI << " gallons \n";
			ofs << "Fuel set to: " << inputI << " gallons \n";
		}
		else if (input == "get fuel") {
			std::cout << "Fuel level is: " << t.getFuel() << " gallons \n";
			ofs << "Fuel level is: " << t.getFuel() << " gallons \n";
		}
		else if (input == "set age") {
			std::cout << "Enter age: ";
			std::cin >> inputI;
			t.setAge(inputI);
			std::cout << "Age set to: " << inputI << "\n";
			ofs << "Age set to: " << inputI << "\n";
		}
		else if (input == "get age") {
			std::cout << "Age is: " << t.getAge() << "\n";
			ofs << "Age is: " << t.getAge() << "\n";
		}
		else if (input == "set mileage") {
			std::cout << "Enter mileage: ";
			std::cin >> inputI;
			t.setMileage(inputI);
			std::cout << "Mileage set to: " << inputI << " miles \n";
			ofs << "Mileage set to: " << inputI << " miles \n";
		}
		else if (input == "get mileage") {
			std::cout << "Mileage is: " << t.getMileage() << "miles \n";
			ofs << "Mileage is: " << t.getMileage() << "miles \n";
		}
		else if (input == "turn on awd") {
			if (t.getAwd() == false) {
				t.setAwd(true);
				std::cout << "Awd is turned on! \n";
				ofs << "Awd is turned on! \n";
			}
			else {
				std::cout << "Awd is already on! \n";
				ofs << "Awd is already on! \n";
			}
		}
		else if (input == "turn off awd") {
			if (t.getAwd() == true) {
				t.setAwd(false);
				std::cout << "Awd is turned off! \n	";
				ofs << "Awd is turned off! \n";
			}
			else {
				std::cout << "Awd is already off! \n";
				ofs << "Awd is already off! \n";
			}
		}
		else if (input == "set friction") {
			std::cout << "Enter friction: ";
			std::cin >> inputI;
			t.setFriction(inputI);
			std::cout << "Friction set to: " << inputI << "\n";
			ofs << "Friction set to: " << inputI << "\n";
		}
		else if (input == "get friction") {
			std::cout << "Friction is: " << t.getFriction() << "\n";
			ofs << "Friction is: " << t.getFriction() << "\n";
		}
		else if (input == "turn on tcs") {
			if (t.getTcs() == false) {
				t.setTcs(true);
				std::cout << "Tcs turned on! \n";
				ofs << "Tcs turned on! \n";
			}
			else {
				std::cout << "Tcs is already on! \n";
				ofs << "Tcs is already on! \n";
			}
		}
		else if (input == "turn off tcs") {
			if (t.getTcs() == true) {
				t.setTcs(false);
				std::cout << "Tcs is turned off! \n";
				ofs << "Tcs is turned off! \n";
			}
			else {
				std::cout << "Tcs is already off! \n";
				ofs << "Tcs is already off! \n";
			}
		}
		else if (input == "set price") {
			std::cout << "Enter price: ";
			std::cin >> inputI;
			t.setPrice(inputI);
			std::cout << "Price set to: " << inputI << "\n";
			ofs << "Price set to: " << inputI << "\n";
		}
		else if (input == "get price") {
			std::cout << "Price is: " << t.getPrice() << " dollars \n";
			ofs << "Price is: " << t.getPrice() << " dollars \n";
		}
		else if (input == "set diesel type") {
			std::cout << "Is the truck diesel?(yes or no):	";
			getline(std::cin, input);
			if (input == "yes") {
				t.setDiesleTypeStatus(true);
				std::cout << "Truck is set to diesel! \n";
				ofs << "Truck is set to diesel! \n";
			}
			else {
				t.setDiesleTypeStatus(false);
				std::cout << "Truck is set to not diesel! \n";
				ofs << "Truck is set to not diesel! \n";
			}
		}
		else if (input == "set capacity") {
			std::cout << "Enter capacity: ";
			std::cin >> inputI;
			t.setCapacity(inputI);
			std::cout << "Capacity set to: " << inputI << "\n";
			ofs << "Capacity set to: " << inputI << "\n";
		}
		else if (input == "get capacity") {
			std::cout << "Capacity is: " << t.getCapacity() << "\n";
			
			ofs << "Capacity is: " << t.getCapacity() << "\n";
		}
		else if (input == "exit truck") {
			std::cout << "Exiting truck! \n";
			ofs << "Exiting truck! \n";
			bool done3 = false;
			while (!done3) {
				std::cout << "Would you like to enter another vehicle? (yes or no): ";
				getline(std::cin, input);
				if (input == "yes") {
					return;

				}
				else if (input == "no") {
					return;
				}
				else {
					std::cout << "Invalid Input! \n";
				}
			}
		}
	}

}

void choseBoat(std::ofstream& ofs) {
	std::string input;
	char inputC;
	float inputI;
	bool done = false;
	std::cout << "Boat selected! \n";
	ofs << "Boat selected! \n";

	while (!done) {
		std::cout << "Action: ";
		getline(std::cin, input);

		if (input == "start engine") {
			if (b.getOff() == true) {
				std::cout << "Engine Started! \n";
				ofs << "Engine Started! \n";
				b.setOff(false);
			}
			else {
				std::cout << "Engine is already on! \n";
				ofs << "Engine is already on! \n";
			}
		}
		else if (input == "turn off engine") {
			if (b.getOff() == false) {
				std::cout << "Engine turned off! \n";
				ofs << "Engine turned off! \n";
				b.setOff(true);
			}
			else {
				std::cout << "Engine is already off! \n";
				ofs << "Engine is already off! \n";

			}
		}
		else if (input == "turn on radio") {
			if (b.getRadio() == false) {
				std::cout << "Radio turned on! \n";
				ofs << "Radio turned on! \n";
				b.setRadio(true);
			}
			else {
				std::cout << "Radio is already on! \n";
				ofs << "Radio is already on! \n";
			}
		}
		else if (input == "turn off radio") {
			if (b.getRadio() == false) {
				std::cout << "Radio is already off! \n";
				ofs << "Radio is already off! \n";
			}
			else {
				b.setRadio(false);
				std::cout << "Radio turned off! \n";
				ofs << "Radio turned off! \n";
			}
		}
		else if (input == "set fuel") {
			std::cout << "Enter how many gal: ";
			std::cin >> inputI;
			b.setFuel(inputI);
			std::cout << "Fuel set to: " << inputI << " gallons \n";
			ofs << "Fuel set to: " << inputI << " gallons \n";
		}
		else if (input == "get fuel") {
			std::cout << "Fuel level is: " << b.getFuel() << " gallons \n";
			ofs << "Fuel level is: " << b.getFuel() << " gallons \n";
		}
		else if (input == "set age") {
			std::cout << "Enter age: ";
			std::cin >> inputI;
			b.setAge(inputI);
			std::cout << "Age set to: " << inputI << "\n";
			ofs << "Age set to: " << inputI << "\n";
		}
		else if (input == "get age") {
			std::cout << "Age is: " << b.getAge() << "\n";
			ofs << "Age is: " << b.getAge() << "\n";
		}
		else if (input == "set price") {
			std::cout << "Enter price: ";
			std::cin >> inputI;
			b.setPrice(inputI);
			std::cout << "Price set to: " << inputI << "\n";
			ofs << "Price set to: " << inputI << "\n";
		}
		else if (input == "get price") {
			std::cout << "Price is: " << b.getPrice() << " dollars \n";
			ofs << "Price is: " << b.getPrice() << " dollars \n";
		}
		else if (input == "set heading") {
			bool done2 = false;
			while (!done2) {
				std::cout << "What direction? ";
				std::cout << "ex.(N,S,E,W)\n:";
				std::cin >> inputC;
				if (inputC == 'N' || inputC == 'S' || inputC == 'E' || inputC == 'W') {
					b.setHeading(inputC);
					std::cout << "Direction set to " << inputC << "\n";
					ofs << "Direction set to " << inputC << "\n";
					done2 = true;
				}
				else {
					std::cout << "Invalid Direction! \n";
				}
			}
		}
		else if (input == "get heading") {
			std::cout << "Heading is: " << b.getHeading() << "\n";
			ofs << "Heading is: " << b.getHeading() << "\n";
		}
		else if (input == "set speed") {
			if (b.getOff() == true) {
				std::cout << "Boat is not on! \n";
				ofs << "Boat is not on! \n";
			}
			else {
				std::cout << "Enter speed: ";
				std::cin >> inputI;
				b.setSpeed(inputI);
				std::cout << "Speed set to " << inputI << " knots \n";
				ofs << "Speed set to " << inputI << " knots \n";
			}
		}
		else if (input == "get speed") {
			std::cout << "Speed is: " << b.getSpeed() << " knots \n";
			ofs << "Speed is: " << b.getSpeed() << " knots \n";
		}
		else if (input == "lower anchor") {
			if (b.getAnchor() == false) {
				b.setAnchor(true);
				std::cout << "Anchor lowered! \n";
				ofs << "Anchor lowered! \n";
			}
			else {
				std::cout << "Anchor is already lowered! \n";
				ofs << "Anchor is already lowered! \n";
			}
		}
		else if (input == "raise anchor") {
			if (b.getAnchor() == true) {
				b.setAnchor(false);
				std::cout << "Anchor is raised! \n";
				ofs << "Anchor is raised! \n";
			}
			else {
				std::cout << "Anchor is already raised! \n";
				ofs << "Anchor is already raised! \n";
			}
		}
		else if (input == "launch") {
			if (b.getAnchor() == true) {
				std::cout << "Anchor is not raised! \n";
				ofs << "Anchor is not raised! \n";
				if (b.getOff() == true) {
					std::cout << "Boat is off! \n";
					ofs << "Boat is off! \n";
				}
			}
			else {
				b.setLaunch(true);
				std::cout << "Boat is launched! \n";
				ofs << "Boat is launched! \n";
			}
		}
		else if (input == "exit boat") {
			std::cout << "Exiting boat! \n";
			ofs << "Exiting boat! \n";
			bool done3 = false;
			while (!done3) {
				std::cout << "Would you like to enter another vehicle? (yes or no): ";
				getline(std::cin, input);
				if (input == "yes") {
					return;

				}
				else if (input == "no") {
					return;
				}
				else {
					std::cout << "Invalid Input! \n";
				}
			}
		}
	}
}

void chosePlane (std::ofstream& ofs) {
	std::string input;
	char inputC;
	float inputI;
	bool done = false;
	std::cout << "Plane selected! \n";
	ofs << "Plane selected! \n";

	while (!done) {
		std::cout << "Action: ";
		getline(std::cin, input);

		if (input == "start engine") {
			if (p.getOff() == true) {
				std::cout << "Engine Started! \n";
				ofs << "Engine Started! \n";
				p.setOff(false);
			}
			else {
				std::cout << "Engine is already on! \n";
				ofs << "Engine is already on! \n";
			}
		}
		else if (input == "turn off engine") {
			if (p.getOff() == false) {
				std::cout << "Engine turned off! \n";
				ofs << "Engine turned off! \n";
				p.setOff(true);
			}
			else {
				std::cout << "Engine is already off! \n";
				ofs << "Engine is already off! \n";

			}
		}
		else if (input == "turn on radio") {
			if (p.getRadio() == false) {
				std::cout << "Radio turned on! \n";
				ofs << "Radio turned on! \n";
				p.setRadio(true);
			}
			else {
				std::cout << "Radio is already on! \n";
				ofs << "Radio is already on! \n";
			}
		}
		else if (input == "turn off radio") {
			if (p.getRadio() == false) {
				std::cout << "Radio is already off! \n";
				ofs << "Radio is already off! \n";
			}
			else {
				p.setRadio(false);
				std::cout << "Radio turned off! \n";
				ofs << "Radio turned off! \n";
			}
		}
		else if (input == "set fuel") {
			std::cout << "Enter how many gal: ";
			std::cin >> inputI;
			p.setFuel(inputI);
			std::cout << "Fuel set to: " << inputI << " gallons \n";
			ofs << "Fuel set to: " << inputI << " gallons \n";
		}
		else if (input == "get fuel") {
			std::cout << "Fuel level is: " << p.getFuel() << " gallons \n";
			ofs << "Fuel level is: " << p.getFuel() << " gallons \n";
		}
		else if (input == "set age") {
			std::cout << "Enter age: ";
			std::cin >> inputI;
			p.setAge(inputI);
			std::cout << "Age set to: " << inputI << "\n";
			ofs << "Age set to: " << inputI << "\n";
		}
		else if (input == "get age") {
			std::cout << "Age is: " << p.getAge() << "\n";
			ofs << "Age is: " << p.getAge() << "\n";
		}
		else if (input == "set price") {
			std::cout << "Enter price: ";
			std::cin >> inputI;
			p.setPrice(inputI);
			std::cout << "Price set to: " << inputI << "\n";
			ofs << "Price set to: " << inputI << "\n";
		}
		else if (input == "get price") {
			std::cout << "Price is: " << p.getPrice() << " dollars \n";
			ofs << "Price is: " << p.getPrice() << " dollars \n";
		}
		else if (input == "set heading") {
			bool done2 = false;
			while (!done2) {
				std::cout << "What direction? ";
				std::cout << "ex.(N,S,E,W)\n:";
				std::cin >> inputC;
				if (inputC == 'N' || inputC == 'S' || inputC == 'E' || inputC == 'W') {
					p.setHeading(inputC);
					std::cout << "Direction set to " << inputC << "\n";
					ofs << "Direction set to " << inputC << "\n";
					done2 = true;
				}
				else {
					std::cout << "Invalid Direction! \n";
				}
			}
		}
		else if (input == "get heading") {
			std::cout << "Heading is: " << p.getHeading() << "\n";
			ofs << "Heading is: " << p.getHeading() << "\n";
		}
		else if (input == "set speed") {
			if (p.getOff() == true) {
				std::cout << "Plane is not on! \n";
				ofs << "Plane is not on! \n";
			}
			else {
				std::cout << "Enter speed: ";
				std::cin >> inputI;
				p.setSpeed(inputI);
				std::cout << "Speed set to " << inputI << " knots \n";
				ofs << "Speed set to " << inputI << " knots \n";
			}
		}
		else if (input == "get speed") {
			std::cout << "Speed is: " << p.getSpeed() << " knots \n";
			ofs << "Speed is: " << p.getSpeed() << " knots \n";
		}
		else if (input == "set altitued") {
			std::cout << "Enter the altitued that you want to go to: ";
			std::cin >> inputI;
			p.setAlt(inputI);
			std::cout << "Altitude set to: " << inputI << " \n";
			ofs << "Altitude set to: " << inputI << " \n";
		}
		else if (input == "get altitude") {
			std::cout << "Altitude is: " << p.getAlt() << " \n";
			ofs << "Altitude is: " << p.getAlt() << " \n";
		}
		else if (input == "take off") {
			if (p.getOff() == true) {
				std::cout << "Plane is not on! \n";
				ofs << "Plane is not on! \n";
			}
			else {
				p.setTakeOff(true);
				std::cout << "Plane has taken off! \n";
				ofs << "Plane has taken off! \n";
			}
		}
		else if (input == "land") {
			if (p.getTakeOff() == false) {
				std::cout << "Plane is not in the air! \n";
				ofs << "Plane is not in the air! \n";
			}
			else {
				p.setTakeOff(false);
				std::cout << "Plane has landed! \n";
				ofs << "Plane has landed! \n";
			}
		}
		else if (input == "exit plane") {
			std::cout << "Exiting plane! \n";
			ofs << "Exiting plane! \n";
			bool done3 = false;
			while (!done3) {
				std::cout << "Would you like to enter another vehicle? (yes or no): ";
				getline(std::cin, input);
				if (input == "yes") {
					return;

				}
				else if (input == "no") {
					return;
				}
				else {
					std::cout << "Invalid Input! \n";
				}
			}
		}
	}
}