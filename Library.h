#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"

// ============================================================
//  CLASS: Library
//  File : Library.h  (Header File)
//
//  OOP Concepts:
//    - Composition  (Library HAS Book[] and Member[] objects)
//    - Arrays of Objects
//    - Static Data Member & Static Member Function
// ============================================================

class Library {
private:
    Book   books[100];     // Array of Book objects   --> Composition
    Member members[100];   // Array of Member objects --> Composition
    int    bookCount;
    int    memberCount;

    static int totalIssued;  // Static Data Member

public:
    // Constructor
    Library();

    // Book operations
    void addBook(int id, string title, string author, string genre);
    void deleteBook(int id);
    void displayAllBooks();
    void searchByID(int id);
    void searchByTitle(string keyword);
    void printQuickList();

    // Member operations
    void addMember(int id, string name);
    void displayAllMembers();

    // Issue / Return
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID);

    // Stats
    void showStats();

    // Static Member Function
    static int getTotalIssued();
};

#endif
