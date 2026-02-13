#include <iostream>
using namespace std;

// adding two numbers using friend function

// class add{
//  int a,b,c;
//  friend void display(add);
// public:
//     void getdata(){
//         cout<<"enter first number"<<endl;
//         cin>>a;
//         cout<<"enter second number"<<endl;
//         cin>>b;
//     }
// };

// void display(add ab){
//     ab.c = ab.a + ab.b;
//     cout<<"the sum of two numbers is "<<ab.c<<endl;
// }

// int main(){
//     add obj;
//     obj.getdata();
//     display(obj);
//     return 0;
// }

// calculating result of student using friend function 

// class student{
//     string name;
//     int rollNo;
//     int marks1, marks2, marks3;
//     friend void display(student);   
// public:
//     void getdata(){
//         cout<<"enter student name"<<endl;
//         cin>>name;
//         cout<<"enter roll number"<<endl;
//         cin>>rollNo;
//         cout<<"enter marks of subject 1"<<endl;
//         cin>>marks1;
//         cout<<"enter marks of subject 2"<<endl;
//         cin>>marks2;
//         cout<<"enter marks of subject 3"<<endl;
//         cin>>marks3;
//     }
// };

// void display(student s){
//     int totalMarks = s.marks1 + s.marks2 + s.marks3;
//     double percentage = (totalMarks / 300.0) * 100;
//     cout<<"Student Name: "<<s.name<<endl;
//     cout<<"Roll Number: "<<s.rollNo<<endl;
//     cout<<"Total Marks: "<<totalMarks<<endl;
//     cout<<"Percentage: "<<percentage<<"%"<<endl;
// }

// int main(){
//     student s1;
//     s1.getdata();
//     display(s1);
//     return 0;
// }

// calculating result of n student using array and friend function


class student {
    char name[30];
    int rollNo;
    int marks[3];
    friend void display(student s[], int n);

public:
    void getdata() {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollNo;

        for (int i = 0; i < 3; i++) {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];
        }
        cout << endl;
    }
};

void display(student s[], int n) {
    for (int i = 0; i < n; i++) {
        int totalMarks = 0;

        for (int j = 0; j < 3; j++) {
            totalMarks += s[i].marks[j];
        }

        double percentage = (totalMarks / 300.0) * 100;

        cout << "Student Name: " << s[i].name << endl;
        cout << "Roll Number: " << s[i].rollNo << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student* s = new student[n];   

    for (int i = 0; i < n; i++) {
        s[i].getdata();
    }

    display(s, n);

    delete[] s;   
    return 0;
}
