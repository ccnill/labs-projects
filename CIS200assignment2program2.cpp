#include <iostream>
#include <string>
using namespace std;
//set the rows and columns constants
const int ROW = 2;
const int COL = 3;

class employee {
public:
	employee() {
		age = 0;
		id = 0;
		salary = 0.0;
		jobTitle = "\O";
		timeOnJob = 0.0;
	}

	void setAge(int ageValue) {
		age = ageValue;
	}

	void setId(int idValue) {
		id = idValue;
	}

	void setSalary(float salaryValue) {
		salary = salaryValue;
	}

	void setJobTitle(string title) {
		jobTitle = title;
	}

	void setTimeOnJob(float time) {
		timeOnJob = time;
	}

	int getAge() {
		return age;
	}

	int getId() {
		return id;
	}

	float getSalary() {
		return salary;
	}

	string getJobTitle() {
		return jobTitle;
	}

	float getTimeOnJob() {
		return timeOnJob;
	}

private:
	int age;
	int id;
	float salary;
	string jobTitle;
	float timeOnJob;
};




class supervisor : public employee {
public:
	supervisor() {
		numberOfTeamsSupervised = 0;
		numberOfEmployeesSupervised = 0;
	}

	void setNumberOfTeamSupervised(int teams) {
		numberOfTeamsSupervised = teams;
	}

	void setNumberOfEmployeesSupervised(int employees) {
		numberOfEmployeesSupervised = employees;
	}

	int getNumberOfTeamsSupervised() {
		return numberOfTeamsSupervised;
	}

	int getNumberOfEmployeesSupervised() {
		return numberOfEmployeesSupervised;
	}

private:
	int numberOfTeamsSupervised;
	int numberOfEmployeesSupervised;
};

class staff : public employee {
public:
staff() {
teamLeader = false;
for (int i = 0; i < 3; i++) {
applicationSupported[i] = "\O";
jobSkill[i] = "\O";
}
}

void setTeamLeader(bool leader) {
teamLeader = leader;
}

void setApplicationSupported(string supp[3]) {
for (int i = 0; i < 3; i++) {
applicationSupported[i] = supp[i];
}
}

void setJobSkill(string skill[3]) {
for (int i = 0; i < 3; i++) {
jobSkill[i] = skill[i];
}
}

void getApplicationSupported() {
for (int i = 0; i < 3; i++) {
cout << applicationSupported[i] << " ";
}
}

void getJobSkill() {
for (int i = 0; i < 3; i++) {
cout << jobSkill[i] << " ";
}
}

private:
bool teamLeader;
string applicationSupported[3];
string jobSkill[3];
};


//fcn to print each employee, avg age, and avg salary
void printEmployee(employee companyEmployee[ROW][COL], int first, int second) {
	float avgSalary = 0;
	int avgAge = 0;
	int numEmployee = 0;
	for (int i = 0; i < first; i++) {
		for (int j = 0; j < second; j++) {
			cout << "Age: " << companyEmployee[i][j].getAge() << " ID: " << companyEmployee[i][j].getId()
				<< "\n Salary: " << companyEmployee[i][j].getSalary() << " Job Title: " << companyEmployee[i][j].getJobTitle()
				<< "\n Time on Job: " << companyEmployee[i][j].getTimeOnJob() << endl;
			avgSalary += companyEmployee[i][j].getSalary();
			avgAge += companyEmployee[i][j].getAge();
			numEmployee++;
		}
	}
	cout << "Average Salary: " << avgSalary / numEmployee << endl;
	cout << "Average age: " << avgAge / numEmployee << endl;
}

int main() {
	int age;
	int id;
	float salary;
	float timeOnJob;
	int supervisedEmployees;
	int supervisedTeams;
	int first = 2;
	int second = 3;
	bool done = false, done2 = false;
	char leader;
	int choice;
	string title;
	string applications[3], skills[3];
	employee companyEmployees[ROW][COL];
	staff x;
	supervisor y;

	while (!done2) {
		cout << "\nChose from the following:  \n";
		cout << "Enter staff member data (1) \n";
		cout << "Enter supervisor data (2) \n";
		cout << "Enter employees data (3) \n";
		cout << "Print staff member data (4) \n";
		cout << "Print supervisor data (5) \n";
		cout << "Print employee data (6) \n";
		cout << "Quit (7) \n";
		cout << "Enter choice: "; 
		cin >> choice;
		cout << "\n";

		switch (choice) {

		case 1: 
			cout << "Enter staff member age: ";
			cin >> age;
			x.setAge(age);

			cout << "Enter staff member ID: ";
			cin >> id;
			x.setId(id);

			cout << "Enter staff member salary: ";
			cin >> salary;
			x.setSalary(salary);

			cout << "Enter staff member job title: ";
			cin >> title;
			x.setJobTitle(title);

			cout << "Enter staff member real time on job: ";
			cin >> timeOnJob;
			x.setTimeOnJob(timeOnJob);

			while (!done) {
				cout << "Is staff member a team leader? (y , n): ";
				cin >> leader;
				if (leader == 'y') {
					cout << "Staff member is set to leader! \n";
					x.setTeamLeader(true);
					done = true;
				}
				else if (leader == 'n') {
					cout << "Staff member is set to not a leader! \n";
					x.setTeamLeader(false);
					done = true;
				}
				else {
					cout << "Error: Invalid input! \n";
				}
			}

			cout << "Enter employees applications supported: ";
			for (int i = 0; i < 3; i++) {
				cin >> applications[i];
			}
			x.setApplicationSupported(applications);
			cout << "Enter employees job skills: ";
			for (int i = 0; i < 3; i++) {
				cin >> skills[i];
			}
			x.setJobSkill(skills);
			break;

		case 2:
			cout << "Enter supervisor age: ";
			cin >> age;
			y.setAge(age);

			cout << "Enter supervisor ID: ";
			cin >> id;
			y.setId(id);

			cout << "Enter supervisor salary: ";
			cin >> salary;
			y.setSalary(salary);

			cout << "Enter supervisor job title: ";
			cin >> title;
			y.setJobTitle(title);

			cout << "Enter supervisor real time on job: ";
			cin >> timeOnJob;
			y.setTimeOnJob(timeOnJob);

			done = false;
			while (!done) {
				cout << "Enter number of employees supervised: ";
				cin >> supervisedEmployees;

				if (supervisedEmployees < 0) {
					cout << "Error: Invalid input! \n";
				}
				else {
					cout << "Number of employees supervised set! \n";
					y.setNumberOfEmployeesSupervised(supervisedEmployees);
					done = true;
				}
			}

			done = false;
			while (!done) {
				cout << "Enter number of teams supervised: ";
				cin >> supervisedTeams;

				if (supervisedTeams < 0) {
					cout << "Error: Invalid input! \n";
				}
				else {
					cout << "Number of teams supervised set! \n";
					y.setNumberOfTeamSupervised(supervisedTeams);
					done = true;
				}
			}

			break;

		case 3: 

			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					cout << " \nEmployee: " << j + 1 << endl;
					cout << "Enter age: ";

					cin >> age;
					companyEmployees[i][j].setAge(age);
					cout << "Enter ID: ";
					cin >> id;
					companyEmployees[i][j].setId(id);
					cout << "Enter salary: ";
					cin >> salary;
					companyEmployees[i][j].setSalary(salary);
					cout << "Enter job title: ";
					cin >> title;
					companyEmployees[i][j].setJobTitle(title);
					cout << "Enter time on job: ";
					cin >> timeOnJob;
					companyEmployees[i][j].setTimeOnJob(timeOnJob);
				}
			}
			break;

		case 4:
			cout << "Age: " << x.getAge() << endl << "ID: " << x.getId() << endl;
			cout << "Salary: " << x.getSalary() << endl << "Job Title: " << x.getJobTitle() << endl << "Time on job: " << x.getTimeOnJob() << endl;
			cout << "Applications supported: ";
			x.getApplicationSupported();
			cout << endl << "Job Skills: ";
			x.getJobSkill();
			cout << endl;

			break;

		case 5:
			cout << "Age: " << y.getAge() << endl << "ID: " << y.getId() << endl;
			cout << "Salary: " << y.getSalary() << endl << "Job title:	" << y.getJobTitle() << endl << "Time on job: " << y.getTimeOnJob() << endl;
			cout << "Number of Employees supervised: " << y.getNumberOfEmployeesSupervised() << endl;
			cout << "Number of teams supervised: " << y.getNumberOfTeamsSupervised() << endl;

			break;

		case 6: 
			printEmployee(companyEmployees, first, second);

			break;

		case 7:
			cout << "Thanks for using my program! \n";
			done2 = true;

			break;

		default:
			cout << "Error: Invalid Input! \n";
		}

	}

	
	system("pause");
	return 0;
}
