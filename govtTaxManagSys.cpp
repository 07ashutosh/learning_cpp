/*
a government tax management system stores taxpayer detail such as ID,Name and Income using a class and array of objects.
the tax amount is calculated using a paramerized constructor and inline function,
while a frend function is used by the tax authority class to access private member income details. 
the program also uses pointer to object for processing multiple record and stores taxpayer information in a binary file 
using file handling for future reference.
*/ 
#include<iostream>
#include<fstream>

using namespace std;

class TaxPayer
{
    private:
        int ID;
        string Name;
        double Income;
        double TaxAmount;

    public:

        TaxPayer()
        {
            ID = 0;
            Name = "";
            Income = 0.0;
            TaxAmount = 0.0;
        }
        TaxPayer(int id, string name, double income)
        {
            ID = id;
            Name = name;
            Income = income;
            calculateTax();
        }

        inline void calculateTax()
        {
            if(Income <= 50000)
                TaxAmount = Income * 0.1;
            else if(Income <= 100000)
                TaxAmount = Income * 0.2;
            else
                TaxAmount = Income * 0.3;
        }

        friend class TaxAuth;

        void displayDetails()
        {
            cout << "ID: " << ID << endl;
            cout << "Name: " << Name << endl;
            cout << "Income: " << Income << endl;
            cout << "Tax Amount: " << TaxAmount << endl;
        }
};
class TaxAuth
{
    public:
        void displayTaxDetails(TaxPayer &tp)
        {
            cout << "Tax Details for " << tp.Name << ":" << endl;
            cout << "Income: " << tp.Income << endl;
            cout << "Tax Amount: " << tp.TaxAmount << endl;
        }
};

void saveToFile(TaxPayer *tp, int size)
{
    ofstream outFile("taxpayers.dat", ios::binary);
    if(!outFile){
        cout << "Error opening file!" << endl;
        return;
    }
    outFile.write((char*)tp, size * sizeof(TaxPayer));
    outFile.close();
}

void readFromFile()
{
    TaxPayer tp;
    ifstream inFile("taxpayers.dat", ios::binary);
    if(!inFile){
        cout << "Error opening file!" << endl;
        return;
    }
    
    while(inFile.read((char*)&tp, sizeof(TaxPayer))){
        tp.displayDetails();
    }
    inFile.close();
}

int main()
{
    int size = 3;
    TaxPayer *taxpayers = new TaxPayer[size]{
        TaxPayer(1, "ashu", 45000),
        TaxPayer(2, "babu", 75000),
        TaxPayer(3, "vinay", 120000)
    };

    saveToFile(taxpayers, size);
    cout << "Taxpayer details saved to file." << endl;

    cout << "Reading taxpayer details from file:" << endl;
    readFromFile();

    delete[] taxpayers;
    return 0;
}
