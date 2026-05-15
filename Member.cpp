
#include "Member.h"

// ============================================================
//  File: Member.cpp  (Source File)
// ============================================================

// ---- Default Constructor ----
Member::Member() {
    memberID     = 0;
    name         = "";
    issuedBookID = -1;
}

// ---- Parameterized Constructor ----
Member::Member(int id, string n) {
    memberID     = id;
    name         = n;
    issuedBookID = -1;
}

// ---- Accessors ----
int    Member::getMemberID()     { return memberID;     }
string Member::getName()         { return name;         }
int    Member::getIssuedBookID() { return issuedBookID; }

// ---- Mutator ----
void Member::setIssuedBookID(int id) {
    issuedBookID = id;
}

// ---- Display ----
void Member::displayMember() {
    cout << "  Member ID    : " << memberID << endl;
    cout << "  Name         : " << name     << endl;
    if (issuedBookID == -1)
        cout << "  Issued Book  : None" << endl;
    else
        cout << "  Issued Book  : Book ID " << issuedBookID << endl;
    cout << "  --------------------------------------------------" << endl;
}
