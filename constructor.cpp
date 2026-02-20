#include <iostream>
using namespace std;

class Employee{
    private:
    string name;
    int empId;
    int salary;
    string department;

    public:
    // default constructor
    Employee(){
        cout<<"default constructor called"<<endl;

    }

    // parameterized constructor
    Employee(string n,int id,int sal,string dpt){
        name = n;
        empId = id;
        salary = sal;
        department = dpt;
        cout<<"parameterized constructor called"<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"employee id: "<<empId<<endl;
        cout<<"salary: "<<salary<<endl;
        cout<<"department: "<<department<<endl;
    }

    // coppy constructor
    Employee(Employee &emp){
        name = emp.name;
        empId = emp.empId;
        salary = emp.salary;
        department = emp.department;
        cout<<"copy constructor called"<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"employee id: "<<empId<<endl;
        cout<<"salary: "<<salary<<endl;
        cout<<"department: "<<department<<endl;
    }

};

int main(){
    Employee emp1;
    Employee emp2("ashu",101,500000,"IT");
    Employee emp3(emp2);
}