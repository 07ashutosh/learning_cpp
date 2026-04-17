/*
ddesign a c++ program using multilevel inheritance and file handeling to manage records in a library. create a base class person with attributes like name ad id .
Derived a class member from person ,and further derive class such as studentMember and facaltyMember from Member each having there on specific data(eg. ,course, department
number of book issued).the program should allow the user to:
issue and return book to member
update member details
save records to the file 
search records by ID
using ofstream ,ifstream
*/

#include<iostream>
#include <fstream>
#include<string>
using namespace std;

class Person{
    protected:
    string name;
    int id;
};
class Member: public Person{
    protected:
    int numBooksIssued;
};
class StudentMember: public Member{
    private:
    string course;
    public:
    void issueBook(){
        numBooksIssued++;
    }
    void returnBook(){
        if(numBooksIssued > 0){
            numBooksIssued--;
        }
    }
    void updateDetails(string nm, int newId, string ncourse){
        name = nm;
        id = newId;
        course = ncourse;
    }
    void saveRecord(){
        ofstream fout("stdRecords.txt", ios::app);
        if(fout.is_open()){
            fout << "Name: " << name << ", ID: " << id << ", Course: " << course << ", Books Issued: " << numBooksIssued << endl;
            fout.close();
        } else {
            cout << "Unable to open file";
        }
    }

    void searchRecord(int sid){
        ifstream fin("stdRecords.txt");
        string line;
        if(fin.is_open()){
            while(getline(fin, line)){
                if(line.find("ID: " + to_string(sid)) != string::npos){
                    cout << line << endl;
                }
            }
            fin.close();
        } else {
            cout << "Unable to open file";
        }
    }
    
};
class FacultyMember: public Member{
    private:
    string department;
    public:
    void issueBook(){
        numBooksIssued++;
    }
    void returnBook(){
        if(numBooksIssued > 0){
            numBooksIssued--;
        }
    }
    void updateDetails(string newnm, int newId, string newDpt){
        name = newnm;
        id = newId;
        department = newDpt;
    }
    void saveRecord(){
        ofstream fout("faculty_records.txt", ios::app);
        if(fout.is_open()){
            fout << "Name: " << name << ", ID: " << id << ", Department: " << department << ", Books Issued: " << numBooksIssued << endl;
            fout.close();
        } else {
            cout << "Unable to open file";
        }
    }
    
};
int main(){
    StudentMember s;
    s.updateDetails("ashu", 1, "cs");
    s.issueBook();
    s.saveRecord();
    s.searchRecord(1);
    FacultyMember f;
    f.updateDetails("abhi", 2, "maths");
    f.issueBook();
    f.saveRecord();
    
    return 0;
}
