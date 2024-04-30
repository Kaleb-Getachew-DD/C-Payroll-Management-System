#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Employee {
private:
    string employeeId;
    string name;
    string level;
    double basicSalary;

public:
    Employee() {}

    Employee(const string& id, const string& empName, const string& empLevel, double salary)
        : employeeId(id), name(empName), level(empLevel), basicSalary(salary) {}

    const string& getEmployeeId() const {
        return employeeId;
    }

    const string& getName() const {
        return name;
    }

    const string& getLevel() const {
        return level;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    void setBasicSalary(double salary) {
        basicSalary = salary;
    }

    void setLevel(const string& empLevel) {
        level = empLevel;
    }
    
    void setName(const string& empName) {
        name = empName;
    }

    void displayInfo() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Level: " << level << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
    }
};

class Deduction {
private:
    double pensionRate;
    double taxRate;
    double otherDeduction;

public:
    Deduction() : pensionRate(0.07),taxRate(0.2), otherDeduction(500) {}

    void setPensionRate(double rate) {
        pensionRate = rate;
    }

    void setTaxRate(double rate) {
        taxRate = rate;
    }

    void setOtherDeduction(double deduction) {
        otherDeduction = deduction;
    }

double calculateDeduction(double salary) const {
    	 
        return (salary * pensionRate) + (salary * taxRate) + otherDeduction;
    }
};

void addEmployee(Employee& employee) {
    string id, name, level;
    double salary;

    cout << "Enter employee unique ID (The Id must be Unique): ";
    cin >> id;

    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter employee level(Manager,Supervisor,Opration,Low): ";
    getline(cin, level);

    cout << "Enter employee basic salary: ";
    cin >> salary;
    if (salary>=1000){
    employee = Employee(id, name, level, salary);}
    else{
    cout<<"wrong salary, Salary must be Greater than 1000"<<endl;
    cout << "Enter employee basic salary again: ";
    cin >> salary;
    employee = Employee(id, name, level, salary);
	}
	
}

void displayEmployeeInfo(const Employee& employee, const Deduction& deduction) {
    double basicSalary = employee.getBasicSalary();
    double allowance = 2000 + 1000 + 1000; // Home allowance, Hard allowance, Transportation allowance

    double netSalary = basicSalary + allowance;

    string level = employee.getLevel();
    if (level == "Manager") {
        double bonus = basicSalary * 0.4; // 40% bonus for managers
        netSalary += bonus;
    } else if (level == "Supervisor") {
        double bonus = basicSalary * 0.2; // 20% bonus for supervisors
        netSalary += bonus;
    }else if (level == "Opration") {
        double bonus = basicSalary * 0.1; // 10% bonus for opration
        netSalary += bonus;
    }
    
    double totalDeduction = deduction.calculateDeduction(netSalary);
    netSalary -= totalDeduction;

    cout << "Allowance: $" << allowance << endl;
    cout << "Net Salary: $" << netSalary << endl;
    cout << "Deductions: $" << totalDeduction << endl;
    cout << endl;
}
  
  void calculatetax(){
  	double taxs,salary; 
  	cout<<"Please Enter your Salary:$ ";
  	cin>>salary;
    if (salary>=50000) {
        taxs = salary * 0.35;
    } else if (salary>=20000&&salary<50000) {
        taxs = salary * 0.20;
    }else if (salary>=1000&&salary<20000) {
        taxs = salary * 0.15;
    }else {
    cout<<"wrong salary input Please enter correctly the minimum salary you can enter must be 1000"<<endl<<endl;
    cout<<"Please Enter your Salary:$ ";
  	cin>>salary;
	}
  	cout << "Your Tax might be : $" << taxs <<endl;
  	cout << endl;
  }

bool login() {
    string username, password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    return (username == "admin" && password == "admin");
}

void saveEmployeeData(const Employee& employee) {
    ofstream file("employees.txt", ios::app);

    if (file.is_open()) {
        file << "Employee ID: " << employee.getEmployeeId() << endl;
        file << "Employee Name: " << employee.getName() << endl;
        file << "Employee Level: " << employee.getLevel() << endl;
        file << "Basic Salary: $" << employee.getBasicSalary() << endl;
        file << endl;

        file.close();

    } else {
        cout << "Unable to save employee data to file." << endl;
    }
}

void loadEmployeeData(Employee* employees, int& count) {
    ifstream file("employees.txt");

    if (file.is_open()) {
        string id, name, level, line;
        double salary;

        count = 0;

        while (getline(file, line)) {
            if (line.find("Employee ID: ") != string::npos) {
                stringstream ss1(line.substr(13));
                ss1 >> id;
            } else if (line.find("Employee Name: ") != string::npos) {
                name = line.substr(15);
            } else if (line.find("Employee Level: ") != string::npos) {
                level = line.substr(16);
            } else if (line.find("Basic Salary: $") != string::npos) {
                stringstream ss2(line.substr(15));
                ss2 >> salary;
                employees[count] = Employee(id, name, level, salary);
                count++;
            }
        }
        file.close();
    } else {
        cout << "Unable to load employee data from file." << endl;
    }
}

void calculateDeduction(const Deduction& deduction) {
    double salary;

    cout << "Enter the employee's salary: $";
    cin >> salary;
    if (salary>=1000){
   	double totalDeduction = deduction.calculateDeduction(salary);
   	cout << "Your Total Deduction Might be: $" << totalDeduction << endl;
   	}else{
    cout<<"wrong salary input Please enter correctly the minimum salary you can enter must be 1000"<<endl;
    cout << "Enter the employee's salary: $";
    cin >> salary;
	}
}
    
void displayAllEmployees(const Employee* employees, int count, const Deduction& deduction) {
    if (count == 0) {
        cout << "No employee data found." << endl;
    } else {
        for (int i = 0; i < count; ++i) {
            employees[i].displayInfo();
            displayEmployeeInfo(employees[i], deduction);
        }
    }
}
void description(){
	cout << " This Simple payroll management system created by a Dire Dawa University 2nd year Computer Science Students. "<<endl;
	cout << " This software program help organizations manage employees payroll. It allows to add new employee "<<endl;
	cout << " calculate deduction and displaying salary detail. It also set Login system to secure the management system. "<<endl;
}

void searchEmployee() {
    ifstream file("employees.txt");
    if (!file.is_open()) {
        cout << "Unable to open the file." << endl;
        return;
    }

    string searchId;
    cout << "Enter the Employee ID to search: ";
    cin.ignore();
    getline(cin, searchId);

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find("Employee ID: " + searchId) != string::npos) {
            cout << "Employee Found!" << endl;
            cout << endl;
            cout << line << endl;  // Print the line containing the employee ID
            // Print the remaining information
            for (int i = 0; i < 4; ++i) {
                getline(file, line);
                cout << line << endl;
            }
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee with ID " << searchId << " not found." << endl;
    }
}

void calculateTotalExpense(const Employee* employees, int employeeCount) {
    double totalExpense = 0.0;
    double basicSalary=0;
    for (int i = 0; i < employeeCount; ++i) {
        basicSalary = employees[i].getBasicSalary();
        basicSalary+=basicSalary;}
        double allowance = (2000 + 1000 + 1000)*employeeCount; // Home allowance, Hard allowance, Transportation allowance
        
        double netSalary = basicSalary + allowance;

        totalExpense += netSalary;
        
        cout << "Total Expense of the Organization: $" << totalExpense << endl;
    }
    
void editEmployee(Employee* employees, int employeeCount) {
    string employeeId;
    cout << "Enter employee ID: ";
    cin >> employeeId;
    cout << "-------------------------" << endl;

    bool found = false;
    for (int i = 0; i < employeeCount; ++i) {
        if (employeeId == employees[i].getEmployeeId()) {
            string newLevel;
            double newSalary;

            cout << "Enter new level: ";
            cin.ignore();
            getline(cin, newLevel);

            cout << "Enter new salary: $";
            cin >> newSalary;

            if (newSalary < 1000) {
                cout << "Invalid salary. Salary must be greater than or equal to 1000." << endl;
                return;
            }

            employees[i].setLevel(newLevel);
            employees[i].setBasicSalary(newSalary);

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << employeeId << " not found." << endl;
    } else {
        ofstream tempFile("temp_employees.txt");
        if (tempFile.is_open()) {
            for (int i = 0; i < employeeCount; ++i) {
                tempFile << "Employee ID: " << employees[i].getEmployeeId() << endl;
                tempFile << "Employee Name: " << employees[i].getName() << endl;
                tempFile << "Employee Level: " << employees[i].getLevel() << endl;
                tempFile << "Basic Salary: $" << employees[i].getBasicSalary() << endl;
                tempFile << endl;
            }
            tempFile.close();

            remove("employees.txt");
            rename("temp_employees.txt", "employees.txt");

            cout << "Employee salary and level edited successfully." << endl;
        } else {
            cout << "Unable to open temporary file." << endl;
        }
    }
}

int main() {
    Employee employees[100];
    Deduction deduction;
    
    int choice;
    bool isLoggedIn = false;
    int employeeCount = 0;
    while (true) {
    	cout << "-----------------------------------"<<endl;
        cout << "Payroll Management System" << endl;
        cout << "  Welcome to Our System  " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Managerial Interface" << endl;
        cout << "2. Display all Employee Information" << endl;
        cout << "3. Calculate your Deduction" << endl;
        cout << "4. Calculate your Tax" << endl;
        cout << "5. Description about this system" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login()) {
                    isLoggedIn = true;
                    cout << "Login successful." << endl<<endl;
                    cout <<"----------------------"<<endl;
                    cout << "Managerial Interface" << endl;
                    cout << "---------------------" << endl;
                    cout << "1. Add New Employee Information" << endl;
                    cout << "2. Total Expense of the organization" << endl;
                    cout << "3. Search Employee" << endl;
                    cout << "4. Edit Employee Salary and Level " << endl;
                    cout << "0. Exit" << endl;
                    cout << "------------------------------------" << endl;

                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            addEmployee(employees[employeeCount]);
                            saveEmployeeData(employees[employeeCount]);
                            employeeCount++;
                            break;
                        case 2:
                        	loadEmployeeData(employees, employeeCount);
                        	calculateTotalExpense(employees, employeeCount);
                        	break;
                        case 3:
            	            searchEmployee();
            	            break;
            	        case 4:
            	        	loadEmployeeData(employees, employeeCount);
            	        	editEmployee(employees, employeeCount);
            	        	break;
                        case 0:
                        	break;
                        
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } else {
                    isLoggedIn = false;
                    cout << "Login failed. Invalid credentials." << endl;
                }
                break;
            case 2:
                loadEmployeeData(employees, employeeCount);
                displayAllEmployees(employees, employeeCount, deduction);
                break;
            case 3:
                calculateDeduction(deduction);
                break;
            case 4:
            	calculatetax();
            	break;
            case 5:
            	description();
            	break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}

