#include <iostream>
#include <string>

class Mexceptions {
private:
	std::string message;
public:
	Mexceptions(std::string x) {
		message = x;
	}
	std::string getMessage() {
		return message;
	}
};

class Dexceptions {
private:
	std::string m;
public:
	Dexceptions(std::string y) {
		m = y;
	}
	std::string getM() {
		return m;
	}
};


class setDate {
private:
	int month;
	int day;
	int year;
	bool done1, done2, done3;
public:

	setDate() {
		month = 0;
		day = 0; 
		year = 0;
		done1, done2, done3 = false;
	}
	void setDone1(bool d) {
		done1 = d;
	}
	void setDone2(bool d) {
		done2 = d;
	}
	void setDone3(bool d) {
		done3 = d;
	}
	void setYear(int y) {
		year = y;
	}
	void setDay(int d) {
		day = d;
	}
	void setMonth(int m) {
		month = m;
	}
	bool getDone1() {
		return done1;
	}
	bool getDone2() {
		return done2;
	}

	bool getDone3() {
		return done3;
	}

	std::string getMonth() {
		switch (month) {
		case 1:
			return "January";
			break;
		case 2:
			return "Febuary";
			break;
		case 3:
			return "March";
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
		default:
			return "Error!";
			break;
		}
	}
	int getDay() {
		return day;
	}
	int getYear() {
		return year;
	}
	

	void setValues() {
		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter day: ";
		std::cin >> day;
		std::cout << "Enter year: ";
		std::cin >> year;
		try {
			if (month < 1 || month > 12) {
				throw Mexceptions("Month is out of range! \n");
			}
			
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (day < 1 || day > 31) {
					throw Dexceptions("Day is invalid! \n");
				}
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (day < 1 || day > 30) {
					throw Dexceptions("Day is invalid! \n");
				}
			}
			else {
				if (day < 1 || day > 28) {
					throw Dexceptions("Day is invalid! \n");
				}
			}
			if (year < 1915 || year > 2017) {
				throw year;
			}
		}
		catch (Mexceptions& e) {
			std::cout << e.getMessage();
			std::cout << "Enter month: ";
			std::cin >> month;
		}
		catch (Dexceptions& d) {
			std::cout << d.getM();
			std::cout << "Enter day: ";
			std::cin >> day;
		}
		catch (...) {
			std::cout << "Invalid year! \n";
			std::cout << "Enter year: ";
			std::cin >> year;
		}

	}

};

int main() {
	setDate x;
	int month;
	int day;
	int year;

	x.setValues();

	std::cout << x.getMonth() << " " << x.getDay() << ", " << x.getYear() << "\n";

	system("pause");
	return 0;
}