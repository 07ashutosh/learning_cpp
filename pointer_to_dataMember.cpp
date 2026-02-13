#include <iostream>
using namespace std;
    
class Employee{
public:  
    string Name;
    double basicSalary;
    double hra;
    double bonus;

    void setDetails(string name, double basic, double h, double b){
        this->Name = name;
        this->basicSalary = basic;
        this->hra = h;
        this->bonus = b;
    }

    void updateSalary(double Employee::*ptr, double amount){
        this->*ptr += amount;
    }

    void displayEmployeeDetails(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Basic Salary: "<<basicSalary<<endl;
        cout<<"HRA: "<<hra<<endl;
        cout<<"Bonus: "<<bonus<<endl;
    }
};

int main(){
    Employee emp;
    double Employee::*salaryPtr;   

    emp.setDetails("John", 50000, 10000, 5000);

    int choice;
    cout<<"Enter 1 to update basic salary, 2 to update HRA, 3 to update bonus: ";
    cin>>choice;

    switch(choice){
        case 1:
            salaryPtr = &Employee::basicSalary;
            emp.updateSalary(salaryPtr, 5000);
            break;
        case 2:
            salaryPtr = &Employee::hra;
            emp.updateSalary(salaryPtr, 2000);
            break;
        case 3:
            salaryPtr = &Employee::bonus;
            emp.updateSalary(salaryPtr, 1000);
            break;
        default:
            cout<<"Invalid choice!"<<endl;
    }

    emp.displayEmployeeDetails();
    return 0;
}
