#include "Book.h"

// ============================================================
//  File: Book.cpp  (Source File - contains function definitions)
// ============================================================

// ---- Default Constructor ----
Book::Book() {
    bookID   = 0;
    title    = "";
    author   = "";
    genre    = "";
    isIssued = false;
}

// ---- Parameterized Constructor ----
Book::Book(int id, string t, string a, string g) {
    bookID   = id;
    title    = t;
    author   = a;
    genre    = g;
    isIssued = false;
}

// ---- Accessors ----
int    Book::getBookID()  { return bookID;   }
string Book::getTitle()   { return title;    }
string Book::getAuthor()  { return author;   }
string Book::getGenre()   { return genre;    }
bool   Book::getIssued()  { return isIssued; }

// ---- Mutator ----
void Book::setIssued(bool status) {
    isIssued = status;
}

// ---- Display ----
void Book::displayBook() {
    cout << "  Book ID  : " << bookID << endl;
    cout << "  Title    : " << title  << endl;
    cout << "  Author   : " << author << endl;
    cout << "  Genre    : " << genre  << endl;
    cout << "  Status   : " << (isIssued ? "*** Issued ***" : "Available") << endl;
    cout << "  --------------------------------------------------" << endl;
}

// ---- Friend Function Definition ----
// Can access private members directly because it is a friend
void printBookSummary(Book b) {
    cout << "  [" << b.bookID << "] " << b.title
         << "  by " << b.author
         << "  (" << (b.isIssued ? "Issued" : "Available") << ")" << endl;
}
