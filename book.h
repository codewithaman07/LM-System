#ifndef BOOK_H
#define BOOK_H

#include <bits/stdc++.h>
using namespace std;
class Book{
private:
    int id;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id, string title, string author);
    int getId();
    bool getAvailability();
    void setAvailability(bool status);
    string getTitle();
    void displayBook();
};

#endif