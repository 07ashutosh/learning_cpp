#include <iostream>
using namespace std;

class Account{
    private:
    string Name;
    int accountNumber;
    double balance;

    public:
    void setDetails(int accNum, string name, double bal){
        this->accountNumber = accNum;
        this->Name = name;
        this->balance = bal;
    }

    void deposit(double amount){
        this->balance += amount;
    }

    void displayAccountDetails(){
        cout<<"Account Holder Name: "<<Name<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

};

int main(){
   int n;

   cout<<"Enter number of accounts: ";
    cin>>n;
    Account acc[n];
    for(int i=0;i<n;i++){
        int accNum;
        string name;
        double bal;

        cout<<"Enter account number: ";
        cin>>accNum;
        cout<<"Enter account holder name: ";
        cin>>name;
        cout<<"Enter initial balance: ";
        cin>>bal;

        acc[i].setDetails(accNum, name, bal);
    }
    for(int i=0;i<n;i++){
        cout<<"Account "<<i+1<<" details:"<<endl;
        acc[i].displayAccountDetails();
        cout<<endl;
    }  

    return 0;
}
