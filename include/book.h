#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id, const std::string &title, const std::string &author);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool getAvailability() const;
    void setAvailability(bool status);

    void displayBook() const;
};

#endif 
