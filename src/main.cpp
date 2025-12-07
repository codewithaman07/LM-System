#include <iostream>
#include <limits>
#include "library.h"
#include "book.h"
#include "member.h"

using namespace std;

void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add Book\n";
    cout << "2. Add Member\n";
    cout << "3. Display All Books\n";
    cout << "4. Display All Members\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (choice == 1) {
            int id;
            string title, author;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            Book newBook(id, title, author);
            library.addBook(newBook);

        } 
        else if (choice == 2) {
            int memberId;
            string name;

            cout << "Enter Member ID: ";
            cin >> memberId;
            cin.ignore();

            cout << "Enter Member Name: ";
            getline(cin, name);

            Member newMember(memberId, name);
            library.addMember(newMember);

        } 
        else if (choice == 3) {
            library.displayBooks();

        } 
        else if (choice == 4) {
            library.displayMembers();

        } 
        else if (choice == 5) {
            int bookId, memberId;
            cout << "Enter Book ID to borrow: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            library.borrowBook(bookId, memberId);

        } 
        else if (choice == 6) {
            int bookId, memberId;
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            library.returnBook(bookId, memberId);

        } 
        else if (choice == 7) {
            cout << "\nExiting system... Goodbye! 👋\n";
            break;

        } 
        else cout << "Invalid option! Try again.\n";
        
    }

    return 0;
}
