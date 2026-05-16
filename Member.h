#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <fstream>


class Member : public Person {   // <-- INHERITANCE
private:
    int issuedBookID;   // -1 means no book currently issued
    int totalBorrowed;  // counts how many books borrowed overall

public:
    // Default Constructor — calls Person() constructor
    Member() : Person(), issuedBookID(-1), totalBorrowed(0) {}

    // Parameterized Constructor — calls Person(i, n, c) constructor
    Member(int id, string name, string contact)
        : Person(id, name, contact), issuedBookID(-1), totalBorrowed(0) {}

    // ---- Getters ----
    int getIssuedBookID()  const { return issuedBookID;  }
    int getTotalBorrowed() const { return totalBorrowed; }

    // ---- Setters ----
    void setIssuedBookID(int id) { issuedBookID = id; }
    void incrementBorrowed()     { totalBorrowed++;   }
    void decrementBorrowed()     { if (totalBorrowed > 0) totalBorrowed--; }

    // ---- Override Pure Virtual (Polymorphism) ----
    // Same function name as Librarian::display() but different output
    void display() const override {
        cout << "  Member ID     : " << getID()      << endl;
        cout << "  Name          : " << getName()    << endl;
        cout << "  Contact       : " << getContact() << endl;
        cout << "  Issued Book   : ";
        if (issuedBookID == -1) cout << "None" << endl;
        else                    cout << "Book ID " << issuedBookID << endl;
        cout << "  Total Borrowed: " << totalBorrowed << " book(s)" << endl;
        cout << "  ------------------------------------------------" << endl;
    }

    // ---- FILE HANDLING: Save member to file ----
    void saveToFile(ofstream &fout) const {
        fout << getID()      << "\n"
             << getName()    << "\n"
             << getContact() << "\n"
             << issuedBookID << "\n"
             << totalBorrowed << "\n";
    }

    // ---- FILE HANDLING: Load member from file ----
    void loadFromFile(ifstream &fin) {
        int    id, bID, tb;
        string name, contact;
        fin >> id >> bID >> tb;
        fin.ignore();
        getline(fin, name);
        getline(fin, contact);
        *this = Member(id, name, contact);
        issuedBookID  = bID;
        totalBorrowed = tb;
    }
};

#endif
