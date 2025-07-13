#ifndef MEMEBER_H
#define MEMEBER_H
#include <bits/stdc++.h>
using namespace std;
class Member{
private:
    int memberId;
    string name;
    vector<int>borrowedBooks; 

public:
    Member(int memberId, string name);
    void displayMember();
    string getName();
    void setName(string name);
    void addBorrowedBook(int bookId);
    void removeBorrowedBook(int bookId);
    void getBorrowedBooks();
    int getMemberId();
    bool borrowBook(int bookId);
    bool returnBook(int bookId);
    int getBorrowedCount();
};

#endif