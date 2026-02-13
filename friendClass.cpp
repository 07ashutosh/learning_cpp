#include<iostream>
using namespace std;

// displaying student result using friend class and display class
class Student{
    string name;
    int rolno;
    int marks[3];

    friend class Result;

    public:
    void getdata(){
        cout<<"enter the name:"<<endl;
        cin>>name;
        cout<<"enter the roll number:"<<endl;
        cin>>rolno;
        for(int i=0;i<3;i++){
            cout<<"enter marks of subject "<<i+1<<":"<<endl;
            cin>>marks[i];
        }
    }
};

class Result{
    public:
    void display(Student s){
        int totalmarks = 0;
        for (int i=0;i<3;i++){
            totalmarks += s.marks[i];
        }
        double percentage = (totalmarks / 300.0) * 100;
        cout<<"student name:"<<s.name<<endl;
        cout<<"roll number:"<<s.rolno<<endl;
        cout<<"total marks:"<<totalmarks<<endl;
        cout<<"percentage:"<<percentage<<"%"<<endl;
    }
};

int main(){
    Student s;
    Result r;
    s.getdata();
    r.display(s);
    return 0;
}