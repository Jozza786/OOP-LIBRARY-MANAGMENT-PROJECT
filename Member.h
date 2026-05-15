#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  CLASS: Member
//  File : Member.h  (Header File)
//
//  OOP Concepts: Encapsulation, Constructors, Access Modifiers
// ============================================================

class Member {
private:
    int    memberID;
    string name;
    int    issuedBookID;   // -1 means no book issued

public:
    // Constructors
    Member();
    Member(int id, string n);

    // Accessors
    int    getMemberID();
    string getName();
    int    getIssuedBookID();

    // Mutators
    void setIssuedBookID(int id);

    // Display
    void displayMember();
};

#endif
