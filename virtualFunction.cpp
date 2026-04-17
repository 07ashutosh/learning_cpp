#include <iostream>
using namespace std;

class Base {
    public:
    virtual void display(){
        cout<<"base class display is called"<<endl;
    }
};

class Derived : public Base {
    public:
    void display(){
        cout<<"derived class display is called"<<endl;
    }
};

int main(){
    Base b, *p;
    Derived d;
    p = &b;
    p->display();
    p = &d;
    p->display();
    return 0;
}