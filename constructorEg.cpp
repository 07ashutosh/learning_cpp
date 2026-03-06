#include <iostream>
using namespace std;
/*
Promble statement: library book system
 desgin a class book for a library system
 . data members: bookid,title,author,price.
 . create a default constructor that initializes:
    bookid=0
    title="not avaiblable"
    author="unknown"
    price=0.0
  . display the default book detail when an object is created without passing arguments.
 */
// class Book{
//     private:
//         int bookId;
//         string title;
//         string author;
//         double price;

//     public:
//         // Default constructor
//         Book(){
//             bookId = 0;
//             title = "not available";
//             author = "unknown";
//             price = 0.0;
//             cout << "Default constructor called." << endl;
//             cout << "Book ID: " << bookId << endl;
//             cout << "Title: " << title << endl;
//             cout << "Author: " << author << endl;
//             cout << "Price: $" << price << endl;
//         }

//         // perameterized constructor
//         Book(int id, string t, string a, double p){
//             bookId = id;
//             title = t;
//             author = a;
//             price = p;
//             cout << "Parameterized constructor called." << endl;
//             cout << "Book ID: " << bookId << endl;
//             cout << "Title: " << title << endl;
//             cout << "Author: " << author << endl;
//             cout << "Price: $" << price << endl;
//         }

// };
// int main(){
//     // Creating an object of Book class using default constructor
//     Book myBook;
//     Book anotherBook(123, "harry potter", "j.k rowling", 799);
//     return 0;
// }

class MovieTicket
{
private:
    string movieName;
    string seatType;
    int price;

public:
    // default constructor
    MovieTicket()
    {
        movieName = "not selected";
        seatType = "not selected";
        price = 0;
        cout << "default constructor called" << endl;
        cout << "movie name: " << movieName << endl;
        cout << "seat type: " << seatType << endl;
        cout << "price: " << price << endl;
    }

    // tax calculation
    int clac_tax(int p){
        int tot;
        int tax;
        price = p;

        if (p > 0 && p <= 100)
        {
            tax = (p * 5) / 100;
            tot = p + tax;
        }
        else if (p >= 100 && p < 200)
        {
            tax = (p * 10) / 100;
            tot = p + tax;
        }
        else
        {
            tax = (p * 15) / 100;
            tot = p + tax;
        }
        return tot;
    }
    // parameterized constructor
    void bookTicket(string m, string s, int p)
    {
        movieName = m;
        seatType = s;
        price = clac_tax(p);
        cout << "Ticke book succesfully !!" << endl;
        cout << "movie name: " << movieName << endl;
        cout << "seat type: " << seatType << endl;
        cout << "price: " << price << endl;
    }
};

int main()
{
    // MovieTicket mybook;
    MovieTicket myTicket;
    myTicket.bookTicket("shatak","premium",150);
    return 0;
}