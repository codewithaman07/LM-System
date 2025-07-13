#include<bits/stdc++.h>
#include "book.h"
#include "member.h"
using namespace std;

int main(){
    Book book1(1, "1984", "George Orwell");
    Member member1(01, "Aman");
    book1.displayBook();
    book1.setAvailability(false);
    cout << "After borrowing:" << endl;
    book1.displayBook();
    cout << "ID: " << book1.getId() << endl;
    cout << "Title: " << book1.getTitle() << endl;
    cout << "Availability: " << (book1.getAvailability() ? "Available" : "Not Available") << endl;
    member1.displayMember();
    member1.addBorrowedBook(book1.getId());
    member1.getBorrowedBooks();
    member1.returnBook(book1.getId());
    return 0;
}