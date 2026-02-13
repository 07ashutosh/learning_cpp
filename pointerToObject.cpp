#include <iostream>
#include <stdio.h>
using namespace std;
class Employee{
    private:
    string name;
    int empId;
    double hourlyRate;
    int workingHours;

    public:
    Employee(string n, int id, double rate, int hours){
        name = n;
        empId = id;
        hourlyRate = rate;
        workingHours = hours;
    }

    double calculateSalary(){
        return hourlyRate * workingHours;
    }
    void display(){
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee ID: "<<empId<<endl;
        cout<<"Hourly Rate: "<<hourlyRate<<endl;
        cout<<"Working Hours: "<<workingHours<<endl;
        cout<<"Total Salary: "<<calculateSalary()<<endl;
    }
};

int main (){
    Employee emp1("ashu",101,50.0,160);
    Employee *ptr = &emp1;

    cout<<"accessing employee detail using point to object"<<endl;
    ptr-> display();
}