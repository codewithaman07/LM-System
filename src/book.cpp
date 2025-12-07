#include <iostream>
#include "book.h"
using namespace std;

Book::Book(int id, const string &title, const string &author)
    : id(id), title(title), author(author), isAvailable(true) {}

int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setAvailability(bool status) {
    isAvailable = status;
}

void Book::displayBook() const {
    cout << "ID: " << id << '\n';
    cout << "Title: " << title << '\n';
    cout << "Author: " << author << '\n';
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << '\n';
}
