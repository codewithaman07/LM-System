#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
#include "member.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;

    Book* findBookById(int bookId);
    Member* findMemberById(int memberId);

public:
    Library();

    void addBook(const Book &book);
    void removeBook(int bookId);
    void displayBooks() const;

    void addMember(const Member &member);
    void removeMember(int memberId);
    void displayMembers() const;

    void borrowBook(int bookId, int memberId);
    void returnBook(int bookId, int memberId);
};

#endif 
