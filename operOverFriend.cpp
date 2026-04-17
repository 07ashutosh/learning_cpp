#include<iostream>
using namespace std;

class complex{
    int x,y;
    public:
    complex(int r=0, int i=0){
        x = r;
        y = i;
    }

    void display(){
        cout << x << " + " << y << "i" << endl;
    }

    friend complex operator+(complex &obj1, complex &obj2);
};

complex operator+(complex &obj1, complex &obj2){
    complex temp;
    temp.x = obj1.x + obj2.x;
    temp.y = obj1.y + obj2.y;
    return temp;
}

int main(){
    complex c1(2, 3);
    complex c2(4, 5);
    complex c3 = c1 + c2;
    c3.display();
    return 0;
}