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
    Employee e[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for Employee " << i + 1 << ":\n";
        e[i].getDetails();
    }

    ofstream fout("employee.dat", ios::binary);
    if (!fout)
    {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    fout.write((char *)&e, sizeof(e));
    fout.close();

    ifstream fin("employee.dat", ios::binary);
    if (!fin)
    {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }
    fin.read((char *)&e, sizeof(e));
    for (int i = 0; i < 3; i++)
    {
        e[i].displayDetails();
    }
    fin.close();

    return 0;
}