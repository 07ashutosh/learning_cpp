#include <iostream>
using namespace std;

class Patient
{
public:
    int p_id;
    string name;
    int age;
    string disease;
    double bill_amt;

public:
    void disp_seniorCitizen()
    {
        if (age > 60)
            cout << "\nPatient is a Senior Citizen\n";

        cout << "Patient ID: " << p_id << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Patient Age: " << age << endl;
        cout << "Patient Disease: " << disease << endl;
        cout << "Patient Bill Amount: " << bill_amt << endl;
    }

    double discount(double amt)
    {
        double disc = 0;

        if(amt >= 1000 && amt <= 50000)
        {
            cout<<"You get 10% discount"<<endl;
            disc = amt * 0.10;
        }
        else if(amt > 50000 && amt <= 100000)
        {
            cout<<"You get 20% discount"<<endl;
            disc = amt * 0.20;
        }
        else
        {
            cout<<"You get 25% discount"<<endl;
            disc = amt * 0.25;
        }

        return disc;
    }

    void dispAfterDisp(int desc){
        cout << "patient id" << p_id;
            cout << "patient name" <<name;
            cout << "patient age" << age;
            cout << "patient disease" <<disease;
            cout << "patient bill amount" <<desc;
    }
};

void dispPatient(Patient p)
{
    cout << "Patient ID: " << p.p_id << endl;
    cout << "Patient Name: " << p.name << endl;
    cout << "Patient Age: " << p.age << endl;
    cout << "Patient Disease: " << p.disease << endl;
    cout << "Patient Bill Amount: " << p.bill_amt << endl;
}

int main(){
    int id;
    string nm;
    int ag;
    string d;
    double amt;
    Patient p[5];

    for(int i = 0; i < 5; i++)
    {
        cout<<"Patient ID: ";
        cin>>p[i].p_id;

        cout<<"Name: ";
        cin>>p[i].name;

        cout<<"Age: ";
        cin>>p[i].age;

        cout<<"Disease: ";
        cin>>p[i].disease;

        cout<<"Bill Amount: ";
        cin>>p[i].bill_amt;
    }
    for(int i = 0; i < 5; i++)
    {
        p[i].disp_seniorCitizen();
        int disc = p[i].discount(p[i].bill_amt);
        p[i].dispAfterDisp(disc);
        dispPatient(p[i]);
    }


}
