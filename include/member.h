#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
using namespace std;

class Member {
private:
    int memberId;
    string name;
    vector<int> borrowedBooks;

public:
    Member(int memberId, const string &name);

    int getMemberId() const;
    string getName() const;
    void setName(const string &newName);

    bool borrowBook(int bookId);
    bool returnBook(int bookId);

    void displayMember() const;
    void displayBorrowedBooks() const;

    int getBorrowedCount() const;
};

#endif 
