#include <iostream>
#include <algorithm>
#include "member.h"
using namespace std;
Member::Member(int memberId, const std::string &name)
    : memberId(memberId), name(name) {}

int Member::getMemberId() const {
    return memberId;
}

string Member::getName() const {
    return name;
}

void Member::setName(const std::string &newName) {
    name = newName;
}

void Member::displayMember() const {
    std::cout << "Member ID: " << memberId << '\n';
    std::cout << "Name: " << name << '\n';
}

bool Member::borrowBook(int bookId) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end()) {
        cout << "Book ID " << bookId << " already borrowed.\n";
        return false;
    }
    borrowedBooks.push_back(bookId);
    return true;
}

bool Member::returnBook(int bookId) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it == borrowedBooks.end()) {
        cout << "This book was not borrowed.\n";
        return false;
    }
    borrowedBooks.erase(it);
    return true;
}

void Member::displayBorrowedBooks() const {
    if (borrowedBooks.empty()) {
        cout << "Borrowed Books: None\n";
        return;
    }

    cout << "Borrowed Books: ";
    for (size_t i = 0; i < borrowedBooks.size(); ++i) {
        cout << borrowedBooks[i];
        if (i + 1 < borrowedBooks.size()) std::cout << ", ";
    }
    cout<<endl;
}

int Member::getBorrowedCount() const {
    return borrowedBooks.size();
}
