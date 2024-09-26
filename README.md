# Payroll Management System

## Overview

This project is a simple **Payroll Management System** created in C++. It provides functionalities to manage employees' payrolls, including adding new employees, calculating deductions, displaying salary details, and ensuring secure access through a login system. The system includes various managerial operations to handle employee data efficiently, including salary and deduction calculations, employee searches, and updating employee details.

## Features

- **Employee Management**: Add new employees, store employee data, and edit employee salary or level.
- **Deductions and Tax Calculations**: Automatically compute pension and tax deductions, based on salary, as well as tax estimation.
- **Salary Breakdown**: Calculate net salary after including allowances and bonuses based on employee level (Manager, Supervisor, Operation, etc.).
- **Secure Login**: Admin login required to access managerial functions.
- **File Operations**: Save and load employee data from `employees.txt`.
- **Reports**: Display all employee information and calculate the total payroll expense of the organization.
- **Search Function**: Find employees by their unique ID.
- **Basic Descriptions**: Provides an overview of the system and functionality for the user.

## Getting Started

### Prerequisites

To run the program, you need:

- A C++ compiler (e.g., GCC, Clang, MSVC)
- A text editor or IDE that supports C++ (e.g., VSCode, CLion, Code::Blocks)

### Compilation and Execution

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/payroll-management-system.git
   ```
   
2. **Navigate to the project directory**:
   ```bash
   cd payroll-management-system
   ```

3. **Compile the program**:
   Using g++ (GCC):
   ```bash
   g++ -o payroll main.cpp
   ```

4. **Run the program**:
   ```bash
   ./payroll
   ```

## Usage

The system offers the following operations:

1. **Managerial Interface (requires login)**
   - **Username**: `admin`
   - **Password**: `admin`
   - After logging in, the following options are available:
     - **Add New Employee Information**: Add an employee's details including ID, name, level, and salary.
     - **Calculate Total Organization Expense**: Computes the total payroll expense including allowances.
     - **Search Employee**: Search for an employee using their unique ID.
     - **Edit Employee Salary and Level**: Modify the salary and level of a specific employee.

2. **Display All Employee Information**: Displays the details of all employees stored in the system, along with their salary breakdown and deductions.

3. **Calculate Your Deduction**: Enter the employee’s salary to calculate the total deductions (tax and pension).

4. **Calculate Your Tax**: Input a salary amount to estimate the tax payable based on salary ranges.

5. **System Description**: Displays a short description about the system and its purpose.

6. **Exit**: Exits the program.

## Code Structure

- **Employee Class**: Manages employee data including ID, name, level, and salary.
- **Deduction Class**: Handles pension and tax deductions.
- **Main Functions**:
  - `addEmployee()`: Adds a new employee.
  - `displayEmployeeInfo()`: Displays employee information and calculates their salary and deductions.
  - `calculateTax()`: Estimates tax based on salary.
  - `login()`: Authenticates admin access.
  - `saveEmployeeData()`, `loadEmployeeData()`: Saves and loads employee information from a text file.
  - `searchEmployee()`: Searches for an employee by ID.
  - `editEmployee()`: Allows the manager to edit employee salary and level.
  
## File Storage

- **employees.txt**: Employee information is stored and loaded from this file. Ensure that this file exists or can be created in the program directory.

## Contribution

Feel free to fork this project and contribute by submitting pull requests. Any suggestions or bug fixes are welcome!

1. Fork the repo.
2. Create your feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m 'Add your feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License.

---

*Created by Computer Science students from Dire Dawa University, 2nd year*
