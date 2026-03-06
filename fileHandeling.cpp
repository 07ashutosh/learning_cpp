#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fout;
    ifstream fin;
    
    char ch;
    int vovals = 0;

    fout.open("xyz.txt");
    if(!fout){
        cout<<"error in file opening"<<endl;
        return 0;
    }
    
    cout<<"enter characters (press '.' to stop):";

    cin>>ch;
    while(ch != '.'){
        fout<<ch;
        cin>>ch;
    }

    fout.close();

    // reading from the file 

    fin.open("xyz.txt");
    if(!fin){
        cout<<"error in file opening"<<endl;
        return 0;
    }

    while(fin.get(ch)){
        if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||
            ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U'){
                vovals++;  
            }
    }
    fin.close();
    cout<<"number of vowels: "<<vovals<<endl;
}