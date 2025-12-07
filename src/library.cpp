#include <iostream>
#include<numeric>
#include <algorithm>
#include "library.h"
using namespace std;

Library::Library() {
    books.emplace_back(1, "1984", "George Orwell");
    books.emplace_back(2, "The Alchemist", "Paulo Coelho");
    books.emplace_back(3, "Clean Code", "Robert C. Martin");

    members.emplace_back(101, "Aman");
    members.emplace_back(102, "Ravi");
}

Book* Library::findBookById(int bookId) {
    for (auto &b : books) {
        if (b.getId() == bookId) return &b;
    }
    return nullptr;
}

Member* Library::findMemberById(int memberId) {
    for (auto &m : members) {
        if (m.getMemberId() == memberId) return &m;
    }
    return nullptr;
}

void Library::addBook(const Book &book) {
    books.push_back(book);
    cout << "Book added successfully.\n";
}

void Library::removeBook(int bookId) {
    auto it = std::remove_if(books.begin(), books.end(),
                             [bookId](const Book &b){ return b.getId() == bookId; });
    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book removed.\n";
    } 
    else cout << "Book not found.\n";
    
}

void Library::displayBooks() const {
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }
    cout << "\n--- Books List ---\n";
    for (const auto &b : books) {
        b.displayBook();
        cout << "------------------\n";
    }
}

void Library::addMember(const Member &member) {
    members.push_back(member);
    cout << "Member added.\n";
}

void Library::removeMember(int memberId) {
    auto it = remove_if(members.begin(), members.end(),
                             [memberId](const Member &m){ return m.getMemberId() == memberId; });
    if (it != members.end()) {
        members.erase(it, members.end());
        cout << "Member removed.\n";
    } 
    else cout << "Member not found.\n";
    
}

void Library::displayMembers() const {
    if (members.empty()) {
        cout << "No members.\n";
        return;
    }
    cout << "\n--- Members List ---\n";
    for (const auto &m : members) {
        m.displayMember();
        m.displayBorrowedBooks();
        cout << "--------------------\n";
    }
}

void Library::borrowBook(int bookId, int memberId) {
    Book *book = findBookById(bookId);
    Member *member = findMemberById(memberId);

    if (!book) {
        cout << "Book not found.\n";
        return;
    }
    if (!member) {
        cout << "Member not found.\n";
        return;
    }

    if (!book->getAvailability()) {
        cout << "Book already borrowed.\n";
        return;
    }

    if (!member->borrowBook(bookId)) {
        cout << "Member cannot borrow.\n";
        return;
    }

    book->setAvailability(false);
    cout << "Borrow success.\n";
}

void Library::returnBook(int bookId, int memberId) {
    Book *book = findBookById(bookId);
    Member *member = findMemberById(memberId);

    if (!book || !member) {
        cout << "Book or member not found.\n";
        return;
    }

    if (!member->returnBook(bookId)) {
        cout << "Not borrowed by this member.\n";
        return;
    }

    book->setAvailability(true);
    cout << "Return success.\n";
}
