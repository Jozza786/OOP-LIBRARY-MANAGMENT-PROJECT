#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"



class Librarian : public Person {   // <-- INHERITANCE
private:
    string employeeCode;
    string password;       // admin login password

public:
    // Default Constructor
    Librarian() : Person(), employeeCode(""), password("") {}

    // Parameterized Constructor
    Librarian(int id, string name, string contact, string code, string pass)
        : Person(id, name, contact), employeeCode(code), password(pass) {}

    // ---- Getters ----
    string getEmployeeCode() const { return employeeCode; }

    // ---- Check password ----
    bool checkPassword(const string &pass) const {
        return password == pass;
    }

    // ---- Override Pure Virtual (Polymorphism) ----
    // Same function name as Member::display() but different behavior
    void display() const override {
        cout << "  Librarian ID   : " << getID()          << endl;
        cout << "  Name           : " << getName()        << endl;
        cout << "  Contact        : " << getContact()     << endl;
        cout << "  Employee Code  : " << employeeCode     << endl;
        cout << "  ------------------------------------------------" << endl;
    }
};

#endif
