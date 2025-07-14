#ifndef LIBRARY_H
#define LIBRARY_H
#include<bits/stdc++.h>
#include "book.h"
#include "member.h"
using namespace std;

class Library{
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(Book& book);
    void removeBook(int bookId);
    void displayBooks();
    void addMember(Member& member);
    void removeMember(int memberId);
    void displayMembers();
    void borrowBook(int bookId, int memberId);
    void returnBook(int bookId, int memberId);
    vector<Book> getAvailableBooks();

};

#endif