#include<iostream>
using namespace std;

double division(int a,int b){
    if(b==0){
        throw "division by zero is not allowed";
    }
    return (double)a/b;
}
int main(){
    int x,y;
    cout<<"enter two numbers:";
    cin>>x>>y;
    try{
        double res = division(x,y);
        cout<<"result of division is: "<<res<<endl;

    }
    catch(const char* err){
        cerr<<"Error:"<<err<<endl;
    }
}
