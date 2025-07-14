#include<bits/stdc++.h>
#include "library.h"
using namespace std;

void Library::addBook(Book& book) {
    books.push_back(book);
    cout << "Book added successfully.\n";
}

void Library::removeBook(int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == bookId) {
            books.erase(it);
            cout << "Book removed successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::displayBooks() {
    cout << "\n--- List of Books ---\n";
    for (Book& b : books) {
        b.displayBook();
        cout << "----------------------\n";
    }
}

void Library::addMember(Member& member) {
    members.push_back(member);
    cout << "Member added successfully.\n";
}

void Library::removeMember(int memberId) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getMemberId() == memberId) {
            members.erase(it);
            cout << "Member removed successfully.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

void Library::displayMembers() {
    cout << "\n--- List of Members ---\n";
    for (Member& m : members) {
        m.displayMember();
        cout << "------------------------\n";
    }
}

void Library::borrowBook(int bookId, int memberId) {
    Book* bookPtr = nullptr;
    Member* memberPtr = nullptr;

    for (Book& b : books) {
        if (b.getId() == bookId) {
            bookPtr = &b;
            break;
        }
    }

    for (Member& m : members) {
        if (m.getMemberId() == memberId) {
            memberPtr = &m;
            break;
        }
    }

    if (!bookPtr) {
        cout << "Book not found.\n";
        return;
    }
    if (!memberPtr) {
        cout << "Member not found.\n";
        return;
    }

    if (!bookPtr->getAvailability()) {
        cout << "Book is already borrowed.\n";
        return;
    }

    if (!memberPtr->borrowBook(bookId)) {
        cout << "Member cannot borrow more books.\n";
        return;
    }

    bookPtr->setAvailability(false);
    cout << "Book borrowed successfully.\n";
}

void Library::returnBook(int bookId, int memberId) {
    Book* bookPtr = nullptr;
    Member* memberPtr = nullptr;

    for (Book& b : books) {
        if (b.getId() == bookId) {
            bookPtr = &b;
            break;
        }
    }

    for (Member& m : members) {
        if (m.getMemberId() == memberId) {
            memberPtr = &m;
            break;
        }
    }

    if (!bookPtr || !memberPtr) {
        cout << "Book or Member not found.\n";
        return;
    }

    if (!memberPtr->returnBook(bookId)) {
        cout << "This member didn't borrow this book.\n";
        return;
    }

    bookPtr->setAvailability(true);
    cout << "Book returned successfully.\n";
}

vector<Book> Library::getAvailableBooks() {
    vector<Book> available;
    for (Book& b : books) {
        if (b.getAvailability()) {
            available.push_back(b);
        }
    }
    return available;
}

