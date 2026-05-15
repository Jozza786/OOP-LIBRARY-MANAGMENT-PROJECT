#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

// ============================================================
//  File: main.cpp
//  Contains: login system + menus + main function
// ============================================================

// ---- Login Function ----
string login() {
    string adminPassword = "admin123";
    int choice;

    cout << "  ==================================================" << endl;
    cout << "      LIBRARY MANAGEMENT SYSTEM - LOGIN"              << endl;
    cout << "  ==================================================" << endl;
    cout << "  1. Login as Admin (Librarian)" << endl;
    cout << "  2. Login as Student (View Only)" << endl;
    cout << "  Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string pass;
        cout << "  Enter Admin Password: ";
        getline(cin, pass);
        if (pass == adminPassword) {
            cout << "\n  [+] Admin login successful! Welcome.\n";
            return "admin";
        } else {
            cout << "\n  [!] Wrong password. Logging in as Student.\n";
            return "student";
        }
    }
    cout << "\n  [+] Logged in as Student.\n";
    return "student";
}

// ---- Admin Menu ----
void showAdminMenu() {
    cout << "\n  ==================================================" << endl;
    cout << "         ADMIN MENU - Library Management"              << endl;
    cout << "  ==================================================" << endl;
    cout << "  --- Book Operations ---"    << endl;
    cout << "  1.  Add Book"              << endl;
    cout << "  2.  Delete Book"           << endl;
    cout << "  3.  Display All Books"     << endl;
    cout << "  4.  Search Book by ID"     << endl;
    cout << "  5.  Search Book by Title"  << endl;
    cout << "  6.  Quick Book List"       << endl;
    cout << "  --- Member Operations ---" << endl;
    cout << "  7.  Register Member"       << endl;
    cout << "  8.  Display All Members"   << endl;
    cout << "  --- Issue / Return ---"    << endl;
    cout << "  9.  Issue Book"            << endl;
    cout << "  10. Return Book"           << endl;
    cout << "  --- Other ---"             << endl;
    cout << "  11. Library Statistics"    << endl;
    cout << "  0.  Exit"                  << endl;
    cout << "  --------------------------------------------------" << endl;
    cout << "  Enter choice: ";
}

// ---- Student Menu ----
void showStudentMenu() {
    cout << "\n  ==================================================" << endl;
    cout << "        STUDENT MENU - Library Management"             << endl;
    cout << "  ==================================================" << endl;
    cout << "  1. Display All Books"    << endl;
    cout << "  2. Search Book by ID"   << endl;
    cout << "  3. Search Book by Title"<< endl;
    cout << "  4. Library Statistics"  << endl;
    cout << "  0. Exit"                << endl;
    cout << "  --------------------------------------------------" << endl;
    cout << "  Enter choice: ";
}

// ============================================================
//  MAIN FUNCTION
// ============================================================
int main() {
    Library lib;

    // Pre-loaded sample data
    lib.addBook(101, "Introduction to C++",        "Bjarne Stroustrup",  "Programming");
    lib.addBook(102, "C++ How to Program",          "Deitel & Deitel",    "Programming");
    lib.addBook(103, "Object Oriented Programming", "Robert Lafore",      "Programming");
    lib.addBook(104, "The Great Gatsby",            "F. Scott Fitzgerald","Fiction");
    lib.addBook(105, "A Brief History of Time",     "Stephen Hawking",    "Science");
    lib.addMember(1, "Ahmad Ali");
    lib.addMember(2, "Sara Khan");
    lib.addMember(3, "Usman Tariq");

    cout << "\n";
    string role = login();
    int choice;

    // ---- ADMIN ----
    if (role == "admin") {
        do {
            showAdminMenu();
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                int id;
                string title, author, genre;
                cout << "\n  Enter Book ID   : "; cin >> id; cin.ignore();
                cout << "  Enter Title     : "; getline(cin, title);
                cout << "  Enter Author    : "; getline(cin, author);
                cout << "  Enter Genre     : "; getline(cin, genre);
                lib.addBook(id, title, author, genre);

            } else if (choice == 2) {
                int id;
                cout << "\n  Enter Book ID to delete: "; cin >> id;
                lib.deleteBook(id);

            } else if (choice == 3) {
                lib.displayAllBooks();

            } else if (choice == 4) {
                int id;
                cout << "\n  Enter Book ID: "; cin >> id;
                lib.searchByID(id);

            } else if (choice == 5) {
                string kw;
                cout << "\n  Enter title keyword: "; getline(cin, kw);
                lib.searchByTitle(kw);

            } else if (choice == 6) {
                lib.printQuickList();

            } else if (choice == 7) {
                int id; string name;
                cout << "\n  Enter Member ID : "; cin >> id; cin.ignore();
                cout << "  Enter Name      : "; getline(cin, name);
                lib.addMember(id, name);

            } else if (choice == 8) {
                lib.displayAllMembers();

            } else if (choice == 9) {
                int mID, bID;
                cout << "\n  Enter Member ID : "; cin >> mID;
                cout << "  Enter Book ID   : "; cin >> bID;
                lib.issueBook(mID, bID);

            } else if (choice == 10) {
                int mID;
                cout << "\n  Enter Member ID : "; cin >> mID;
                lib.returnBook(mID);

            } else if (choice == 11) {
                lib.showStats();

            } else if (choice != 0) {
                cout << "\n  [!] Invalid choice.\n";
            }

        } while (choice != 0);

    // ---- STUDENT ----
    } else {
        do {
            showStudentMenu();
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                lib.displayAllBooks();

            } else if (choice == 2) {
                int id;
                cout << "\n  Enter Book ID: "; cin >> id;
                lib.searchByID(id);

            } else if (choice == 3) {
                string kw;
                cout << "\n  Enter title keyword: "; getline(cin, kw);
                lib.searchByTitle(kw);

            } else if (choice == 4) {
                lib.showStats();

            } else if (choice != 0) {
                cout << "\n  [!] Invalid choice.\n";
            }

        } while (choice != 0);
    }

    cout << "\n  Thank you for using the Library System. Goodbye!\n\n";
    return 0;
}
