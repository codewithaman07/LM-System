#include<bits/stdc++.h>
#include "member.h"
using namespace std;

Member::Member(int memberId, string name) {
    this->memberId = memberId;
    this->name = name;
}

void Member::displayMember(){
    cout<< "Member ID: " << memberId << endl;
    cout<< "Name: " << name << endl;
}
string Member::getName() {
    return name;
}
void Member::setName(string name) {
    this->name = name;
    cout << "Name updated to: " << name << endl;
}
int Member::getMemberId() {
    return memberId;
}
void Member::addBorrowedBook(int bookId) {
    borrowedBooks.push_back(bookId);
    cout << "Book ID " << bookId << " added to borrowed books." << endl;
}
void Member::removeBorrowedBook(int bookId) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        cout << "Book ID " << bookId << " removed from borrowed books." << endl;
    }
    else {
        cout << "Book ID " << bookId << " not found in borrowed books." << endl;
    }
}

void Member::getBorrowedBooks() {
    cout << "Borrowed Books: ";
    int n = borrowedBooks.size();
    for(int i = 0; i < n; i++) {
        cout << borrowedBooks[i] << (i < n - 1 ? ", " : "");
    }
    cout << endl;
}

bool Member::borrowBook(int bookId) {
    if (find(borrowedBooks.begin(), borrowedBooks.end(), bookId) == borrowedBooks.end()) {
        addBorrowedBook(bookId);
        return true;
    } else {
        cout << "Book ID " << bookId << " is already borrowed." << endl;
        return false;
    }
}

bool Member::returnBook(int bookId) {
    if (find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end()) {
        removeBorrowedBook(bookId);
        return true;
    } else {
        cout << "Book ID " << bookId << " was not borrowed." << endl;
        return false;
    }
}

int Member::getBorrowedCount() {
    return borrowedBooks.size();
}