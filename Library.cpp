#include "Library.h"

// ============================================================
//  File: Library.cpp  (Source File)
// ============================================================

// Initialize static member OUTSIDE the class (required in C++)
int Library::totalIssued = 0;

// ---- Constructor ----
Library::Library() {
    bookCount   = 0;
    memberCount = 0;
}

// ============================================================
//  BOOK OPERATIONS
// ============================================================

void Library::addBook(int id, string title, string author, string genre) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "\n  [!] Book ID " << id << " already exists!\n";
            return;
        }
    }
    if (bookCount >= 100) {
        cout << "\n  [!] Library is full!\n";
        return;
    }
    books[bookCount] = Book(id, title, author, genre);
    bookCount++;
    cout << "\n  [+] Book added successfully!\n";
}

void Library::deleteBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getIssued()) {
                cout << "\n  [!] Cannot delete — book is currently issued.\n";
                return;
            }
            // Shift array left to fill the gap
            for (int j = i; j < bookCount - 1; j++)
                books[j] = books[j + 1];
            bookCount--;
            cout << "\n  [+] Book deleted successfully!\n";
            return;
        }
    }
    cout << "\n  [!] Book not found.\n";
}

void Library::displayAllBooks() {
    if (bookCount == 0) {
        cout << "\n  No books in the library yet.\n";
        return;
    }
    cout << "\n  ==================================================" << endl;
    cout << "               ALL BOOKS IN LIBRARY"                   << endl;
    cout << "  ==================================================" << endl;
    for (int i = 0; i < bookCount; i++)
        books[i].displayBook();
}

void Library::searchByID(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "\n  [Found]\n";
            books[i].displayBook();
            return;
        }
    }
    cout << "\n  [!] No book found with ID " << id << ".\n";
}

void Library::searchByTitle(string keyword) {
    bool found = false;
    cout << "\n  Results for \"" << keyword << "\" :\n";
    cout << "  --------------------------------------------------" << endl;
    for (int i = 0; i < bookCount; i++) {
        string t = books[i].getTitle();
        string tLow = "", kLow = "";
        for (int j = 0; j < (int)t.size(); j++)       tLow += tolower(t[j]);
        for (int j = 0; j < (int)keyword.size(); j++) kLow += tolower(keyword[j]);
        if (tLow.find(kLow) != string::npos) {
            books[i].displayBook();
            found = true;
        }
    }
    if (!found)
        cout << "  No books matched your search.\n";
}

void Library::printQuickList() {
    cout << "\n  Quick Book List:\n";
    cout << "  --------------------------------------------------" << endl;
    for (int i = 0; i < bookCount; i++)
        printBookSummary(books[i]);   // Friend function call
    cout << endl;
}

// ============================================================
//  MEMBER OPERATIONS
// ============================================================

void Library::addMember(int id, string name) {
    for (int i = 0; i < memberCount; i++) {
        if (members[i].getMemberID() == id) {
            cout << "\n  [!] Member ID already exists!\n";
            return;
        }
    }
    if (memberCount >= 100) {
        cout << "\n  [!] Member limit reached.\n";
        return;
    }
    members[memberCount] = Member(id, name);
    memberCount++;
    cout << "\n  [+] Member registered successfully!\n";
}

void Library::displayAllMembers() {
    if (memberCount == 0) {
        cout << "\n  No members registered yet.\n";
        return;
    }
    cout << "\n  ==================================================" << endl;
    cout << "             ALL REGISTERED MEMBERS"                   << endl;
    cout << "  ==================================================" << endl;
    for (int i = 0; i < memberCount; i++)
        members[i].displayMember();
}

// ============================================================
//  ISSUE & RETURN
// ============================================================

void Library::issueBook(int memberID, int bookID) {
    int mIdx = -1, bIdx = -1;

    for (int i = 0; i < memberCount; i++)
        if (members[i].getMemberID() == memberID) { mIdx = i; break; }

    for (int i = 0; i < bookCount; i++)
        if (books[i].getBookID() == bookID) { bIdx = i; break; }

    if (mIdx == -1) { cout << "\n  [!] Member not found.\n";  return; }
    if (bIdx == -1) { cout << "\n  [!] Book not found.\n";    return; }

    if (members[mIdx].getIssuedBookID() != -1) {
        cout << "\n  [!] Member already has a book. Return it first.\n";
        return;
    }
    if (books[bIdx].getIssued()) {
        cout << "\n  [!] Book is already issued to someone else.\n";
        return;
    }

    books[bIdx].setIssued(true);
    members[mIdx].setIssuedBookID(bookID);
    totalIssued++;

    cout << "\n  [+] \"" << books[bIdx].getTitle()
         << "\" issued to " << members[mIdx].getName() << " successfully!\n";
}

void Library::returnBook(int memberID) {
    int mIdx = -1, bIdx = -1;

    for (int i = 0; i < memberCount; i++)
        if (members[i].getMemberID() == memberID) { mIdx = i; break; }

    if (mIdx == -1) { cout << "\n  [!] Member not found.\n"; return; }

    int issuedID = members[mIdx].getIssuedBookID();
    if (issuedID == -1) {
        cout << "\n  [!] This member has no book to return.\n"; return;
    }

    for (int i = 0; i < bookCount; i++)
        if (books[i].getBookID() == issuedID) { bIdx = i; break; }

    books[bIdx].setIssued(false);
    members[mIdx].setIssuedBookID(-1);
    totalIssued--;

    cout << "\n  [+] Book returned by " << members[mIdx].getName() << " successfully!\n";
}

// ============================================================
//  STATS & STATIC FUNCTION
// ============================================================

void Library::showStats() {
    cout << "\n  ==== Library Statistics ====" << endl;
    cout << "  Total Books    : " << bookCount                       << endl;
    cout << "  Total Members  : " << memberCount                     << endl;
    cout << "  Books Issued   : " << Library::getTotalIssued()       << endl;
    cout << "  Books Available: " << bookCount - Library::getTotalIssued() << endl;
    cout << "  --------------------------------------------------"   << endl;
}

// Static Member Function
int Library::getTotalIssued() {
    return totalIssued;
}
