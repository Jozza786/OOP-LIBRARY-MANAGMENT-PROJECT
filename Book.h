#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Book {
private:
    int    bookID;
    string title;
    string author;
    string genre;
    bool   isIssued;
    int    issuedToID;   // stores member ID who borrowed this book

public:
    // Default Constructor
    Book() : bookID(0), title(""), author(""), genre(""), isIssued(false), issuedToID(-1) {}

    // Parameterized Constructor
    Book(int id, string t, string a, string g)
        : bookID(id), title(t), author(a), genre(g), isIssued(false), issuedToID(-1) {}

    // ---- Getters ----
    int    getBookID()     const { return bookID;     }
    string getTitle()      const { return title;      }
    string getAuthor()     const { return author;     }
    string getGenre()      const { return genre;      }
    bool   getIsIssued()   const { return isIssued;   }
    int    getIssuedToID() const { return issuedToID; }

    // ---- Setters ----
    void setIssued(bool status, int memberID) {
        isIssued   = status;
        issuedToID = memberID;
    }

    // ---- Display Book Info ----
    void display() const {
        cout << "  Book ID   : " << bookID  << endl;
        cout << "  Title     : " << title   << endl;
        cout << "  Author    : " << author  << endl;
        cout << "  Genre     : " << genre   << endl;
        cout << "  Status    : ";
        if (isIssued) cout << "Issued (Member ID: " << issuedToID << ")" << endl;
        else          cout << "Available" << endl;
        cout << "  ------------------------------------------------" << endl;
    }

    // ---- FILE HANDLING: Save one book to file ----
    // Uses ofstream (output file stream) to write data
    void saveToFile(ofstream &fout) const {
        fout << bookID    << "\n"
             << title     << "\n"
             << author    << "\n"
             << genre     << "\n"
             << isIssued  << "\n"
             << issuedToID << "\n";
    }

    // ---- FILE HANDLING: Load one book from file ----
    // Uses ifstream (input file stream) to read data
    void loadFromFile(ifstream &fin) {
        fin >> bookID >> isIssued >> issuedToID;
        fin.ignore();
        getline(fin, title);
        getline(fin, author);
        getline(fin, genre);
    }

    // Friend Function Declaration
    friend void printBookSummary(const Book &b);
};

// Friend Function — can access private members of Book directly
void printBookSummary(const Book &b) {
    cout << "  [" << b.bookID << "] " << b.title
         << "  |  " << b.author
         << "  |  " << (b.isIssued ? "Issued" : "Available") << endl;
}

#endif
