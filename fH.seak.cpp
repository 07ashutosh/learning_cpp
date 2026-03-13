#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
public:
    int empId;
    string name;
    double salary;

public:
    void getDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void displayDetails()
    {
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main()
{
    Employee e;
    fstream file("employee.dat", ios::out | ios::binary | ios::in);
    if(!file){
        cout << "Error opening file!" << endl;
        return 1;
    }

    // moving the pointer to the third position(index 2)
    file.seekg(2 * sizeof(e), ios::beg);
    file.read((char *)&e, sizeof(e));
    cout << "Details of the employee at index 2:" << endl;
    e.displayDetails();

    cout<<"updating the details of the employee at index 2:"<<endl;
    e.getDetails();
    file.seekp(2* sizeof(e),ios::beg);
    file.write((char *)&e, sizeof(e));
    e.displayDetails();
    file.close();

    return 0;
}