#include<iostream>
using namespace std;

class BankException{
    public:
    int amount=0;
    int withdrawl;

    void deposit(int a){
        amount+=a;
    }

    void checkBalance(){
        cout<<"current balance is: "<<amount<<endl;
    }
    void withdraw(int w){
        if(w>amount){
            throw "withdrawl amount is greater than balance";
        }
        else if(w<0){
            throw "withdrawl amount cannot be negative";
        }
        else{
            amount-=w;
            cout<<"withdrawl successful. current balance is: "<<amount<<endl;
        }
    }

};
int main(){
    BankException b;
    printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
    int choice;
    do{
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            int dep;
            cout<<"enter the amount to deposit:";
            cin>>dep;
            b.deposit(dep);
            break;
            case 2:
            int w;
            cout<<"enter the amount to withdraw:";
            cin>>w;
            try{
                b.withdraw(w);
            }catch(const char *err){
                cerr<<"error:"<<err<<endl;
            }
            break;
            case 3:
            b.checkBalance();
            break;
            case 4:
            cout<<"exiting..."<<endl;
            break;
            default:
            cout<<"invalid choice, please try again."<<endl;
        }
    }while(choice!=4);
    return 0;
}