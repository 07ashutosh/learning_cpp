#include <iostream>
using namespace std;

class Distance{
    int Km,m;
    public:
    Distance(int k=0, int m1=0){
        Km = k;
        m = m1;
    }
    Distance operator+(Distance d){
        Distance temp;
        temp.Km = Km + d.Km;
        temp.m = m + d.m;
        if(temp.m >= 1000){
            temp.Km += temp.m / 1000;
            temp.m = temp.m % 1000;
        }
        return temp;
    }
    void display(){
        cout << Km << " Km " << m << " m" << endl;
    }

};

int main(){
    Distance d1(2, 500);
    Distance d2(3, 750);
    Distance d3 = d1 + d2;
    d3.display();
    return 0;
}
