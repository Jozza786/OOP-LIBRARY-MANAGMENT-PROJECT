#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  CLASS: Book
//  File : Book.h  (Header File - contains class declaration)
//
//  OOP Concepts: Encapsulation, Constructors, Access Modifiers
// ============================================================

class Book {
private:
    int    bookID;
    string title;
    string author;
    string genre;
    bool   isIssued;

public:
    // Constructors
    Book();
    Book(int id, string t, string a, string g);

    // Accessor (Getter) functions
    int    getBookID();
    string getTitle();
    string getAuthor();
    string getGenre();
    bool   getIssued();

    // Mutator (Setter) functions
    void setIssued(bool status);

    // Display
    void displayBook();

    // Friend function declaration
    friend void printBookSummary(Book b);
};

// Friend function prototype
void printBookSummary(Book b);

#endif
