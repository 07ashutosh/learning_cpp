#include <iostream>
using namespace std;

// class Student{
//     private:
//     int roll;
//     string name;
//     public:
//     void getdata(){
//        cout<<"enter roll number"<<endl;
//         cin>>roll;
//         cout<<"enter name"<<endl;
//         cin>>name;
//     }
//     void display(){
//         cout<<"roll number: "<<roll<<endl;
//         cout<<"name: "<<name<<endl;
//     }
// };

// class Result: public Student{
//     private:
//     int marks[3];
//     public:
//     void getmarks(){
//         cout<<"enter marks"<<endl;
//         for(int i=0; i<3; i++){
//             cin>>marks[i];
//         }
//     }
//     void displayresult(){
//         display();
//         cout<<"marks: ";
//         for(int i=0; i<3; i++){
//             cout<<marks[i]<<" ";
//         }
//         cout<<endl;
//     }
// };

// int main(){
//     Result r;
//     r.getdata();
//     r.getmarks();
//     r.displayresult();
//     r.display();
//     return 0;
// }   

// multi level inheritance

// class Library{
//     protected:
//     string bookName;
//     public:
//     void getBookName(){
//         cout<<"enter book name"<<endl;
//         cin>>bookName;
//     }
// };

// class IssueBook: public Library{
//     protected:
//     string issueDate;
//     public:
//     void getdata(){
//         cout<<"enter issue date"<<endl;
//         cin>>issueDate;
//     }
// };

// class ReturnBook: public IssueBook{
//     protected:
//     string returnDate;
//     public:
//     void getReturnDate(){
//         cout<<"enter return date"<<endl;
//         cin>>returnDate;
//     }
//     void displayReturnDetails(){
//         cout<<"book name: "<<bookName<<endl;
//         cout<<"issue date: "<<issueDate<<endl;
//         cout<<"return date: "<<returnDate<<endl;
//     }
// };

// int main(){
//     ReturnBook rb;
//     rb.getBookName();
//     rb.getdata();
//     rb.getReturnDate();
//     rb.displayReturnDetails();
//     return 0;
// }

// hybrid inheritance

class Student{
    protected:
    char name[30];
    int rollNo;
    public:
    void getdata(){
        cout<<"enter student name: ";
        cin>>name;
        cout<<"enter roll number: ";
        cin>>rollNo;
    }
};

class CA: public Student{
    protected:
    int marks[3];
    public:
    void getmarks(){
        cout<<"enter marks: ";
        for(int i=0; i<3; i++){
            cin>>marks[i];
        }
    }

    void calculateresult(){
        int totalMarks = marks[0] + marks[1] + marks[2];
        double percentage = (totalMarks / 300.0) * 100;
        cout<<"total marks: "<<totalMarks<<endl;
        cout<<"percentage: "<<percentage<<"%"<<endl;
    }
};

class Sports{
    protected:
    int score;
    public:
    void getscore(){
        cout<<"enter sports score: ";
        cin>>score;
    }
};

class Result: public CA, public Sports{
    public:
    void claculateFinalResult(){
        int totalMarks = marks[0] + marks[1] + marks[2]+score;
        double percentage = (totalMarks / 400.0) * 100;
        cout<<"total marks: "<<totalMarks<<endl;
        cout<<"percentage: "<<percentage<<"%"<<endl;
        cout<<"sports score: "<<score<<endl;
    }
};

int main(){
    Result r;
    r.getdata();
    r.getmarks();
    r.getscore();
    r.claculateFinalResult();
    return 0;
}

