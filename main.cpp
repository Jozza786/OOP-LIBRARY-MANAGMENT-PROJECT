#include <iostream>
#include <string>
#include "Library.h"
using namespace std;


// ---- Display Admin Menu ----
void showAdminMenu() {
    cout << "\n  ================================================" << endl;
    cout << "        ADMIN MENU  |  Library Management"           << endl;
    cout << "  ================================================" << endl;
    cout << "  --- BOOKS ---"                                     << endl;
    cout << "  1.  Add Book"                                      << endl;
    cout << "  2.  Delete Book"                                   << endl;
    cout << "  3.  Display All Books"                             << endl;
    cout << "  4.  Search Book by ID"                             << endl;
    cout << "  5.  Search Book by Title"                          << endl;
    cout << "  6.  Quick Book List"                               << endl;
    cout << "  --- MEMBERS ---"                                   << endl;
    cout << "  7.  Add Member"                                    << endl;
    cout << "  8.  Display All Members"                           << endl;
    cout << "  9.  Search Member by ID"                           << endl;
    cout << "  --- ISSUE / RETURN ---"                            << endl;
    cout << "  10. Issue Book to Member"                          << endl;
    cout << "  11. Return Book from Member"                       << endl;
    cout << "  --- OTHER ---"                                     << endl;
    cout << "  12. Library Statistics"                            << endl;
    cout << "  13. Show All Persons  "         << endl;
    cout << "  0.  Logout"                                        << endl;
    cout << "  ------------------------------------------------" << endl;
    cout << "  Enter choice: ";
}

// ---- Display Student Menu ----
void showStudentMenu() {
    cout << "\n  ================================================" << endl;
    cout << "      STUDENT MENU  |  Library Management"           << endl;
    cout << "  ================================================" << endl;
    cout << "  1. Display All Books"                              << endl;
    cout << "  2. Search Book by ID"                              << endl;
    cout << "  3. Search Book by Title"                           << endl;
    cout << "  4. Library Statistics"                             << endl;
    cout << "  0. Logout"                                         << endl;
    cout << "  ------------------------------------------------" << endl;
    cout << "  Enter choice: ";
}

// ---- Admin Operations ----
void runAdminMenu(Library &lib) {
    int choice;
    do {
        showAdminMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int id; string title, author, genre;
            cout << "\n  Enter Book ID  : "; cin >> id; cin.ignore();
            cout << "  Enter Title    : "; getline(cin, title);
            cout << "  Enter Author   : "; getline(cin, author);
            cout << "  Enter Genre    : "; getline(cin, genre);
            lib.addBook(id, title, author, genre);
        }
        else if (choice == 2) {
            int id;
            cout << "\n  Enter Book ID to delete: "; cin >> id;
            lib.deleteBook(id);
        }
        else if (choice == 3) lib.displayAllBooks();
        else if (choice == 4) {
            int id;
            cout << "\n  Enter Book ID: "; cin >> id;
            lib.searchBookByID(id);
        }
        else if (choice == 5) {
            string kw;
            cout << "\n  Enter title keyword: "; getline(cin, kw);
            lib.searchBookByTitle(kw);
        }
        else if (choice == 6) lib.quickBookList();
        else if (choice == 7) {
            int id; string name, contact;
            cout << "\n  Enter Member ID  : "; cin >> id; cin.ignore();
            cout << "  Enter Name       : "; getline(cin, name);
            cout << "  Enter Contact    : "; getline(cin, contact);
            lib.addMember(id, name, contact);
        }
        else if (choice == 8) lib.displayAllMembers();
        else if (choice == 9) {
            int id;
            cout << "\n  Enter Member ID: "; cin >> id;
            lib.searchMemberByID(id);
        }
        else if (choice == 10) {
            int mID, bID;
            cout << "\n  Enter Member ID : "; cin >> mID;
            cout << "  Enter Book ID   : "; cin >> bID;
            lib.issueBook(mID, bID);
        }
        else if (choice == 11) {
            int mID;
            cout << "\n  Enter Member ID : "; cin >> mID;
            lib.returnBook(mID);
        }
        else if (choice == 12) lib.showStats();
        else if (choice == 13) lib.showAllPersonsInfo();
        else if (choice != 0)  cout << "\n  [!] Invalid choice. Try again.\n";

    } while (choice != 0);
}

// ---- Student Operations ----
void runStudentMenu(Library &lib) {
    int choice;
    do {
        showStudentMenu();
        cin >> choice;
        cin.ignore();

        if      (choice == 1) lib.displayAllBooks();
        else if (choice == 2) {
            int id;
            cout << "\n  Enter Book ID: "; cin >> id;
            lib.searchBookByID(id);
        }
        else if (choice == 3) {
            string kw;
            cout << "\n  Enter title keyword: "; getline(cin, kw);
            lib.searchBookByTitle(kw);
        }
        else if (choice == 4) lib.showStats();
        else if (choice != 0) cout << "\n  [!] Invalid choice. Try again.\n";

    } while (choice != 0);
}

int main() {
    Library lib;   // Object of Library — loads saved data automatically

    cout << "\n  ================================================" << endl;
    cout << "       LIBRARY MANAGEMENT SYSTEM"                    << endl;
    cout << "       Data is saved automatically to files"         << endl;
    cout << "  ================================================" << endl;

    int loginChoice;
    cout << "\n  1. Login as Admin (Librarian)"    << endl;
    cout << "  2. Login as Student (View Only)"   << endl;
    cout << "  Enter choice: ";
    cin >> loginChoice;
    cin.ignore();

    if (loginChoice == 1) {
        string pass;
        cout << "  Enter Admin Password: ";
        getline(cin, pass);

        if (lib.adminLogin(pass)) {
            cout << "\n  [+] Welcome, Admin! Data loaded from files.\n";
            runAdminMenu(lib);
        } else {
            cout << "\n  [!] Wrong password! Logging in as Student.\n";
            runStudentMenu(lib);
        }
    } else {
        cout << "\n  [+] Logged in as Student.\n";
        runStudentMenu(lib);
    }

    cout << "\n  Thank you for using the Library System. Goodbye!\n\n";
    return 0;
}
