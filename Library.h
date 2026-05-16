#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include <fstream>


class Library {
private:
    Book     books[100];
    Member   members[100];
    Librarian admin;          // Single librarian/admin object
    int      bookCount;
    int      memberCount;

    static int totalIssued;   // Static member — shared across all objects

    // ---- Helper: find book index by ID ----
    int findBook(int id) const {
        for (int i = 0; i < bookCount; i++)
            if (books[i].getBookID() == id) return i;
        return -1;
    }

    // ---- Helper: find member index by ID ----
    int findMember(int id) const {
        for (int i = 0; i < memberCount; i++)
            if (members[i].getID() == id) return i;
        return -1;
    }

public:
    // Constructor — sets up admin and loads saved data from files
    Library() : bookCount(0), memberCount(0) {
        admin = Librarian(1, "Admin Librarian", "0300-0000000", "LIB-001", "admin123");
        loadBooks();
        loadMembers();
    }

    // ---- Static Function ----
    static int getTotalIssued() { return totalIssued; }

    // ---- Check admin password ----
    bool adminLogin(const string &pass) const {
        return admin.checkPassword(pass);
    }

    // ============================================================
    //  FILE HANDLING — BOOKS
    // ============================================================

    // Save all books to books.txt
    void saveBooks() const {
        ofstream fout("books.txt");   // open file for writing
        if (!fout) {
            cout << "\n  [!] Error: Could not open books.txt for saving.\n";
            return;
        }
        fout << bookCount << "\n";    // first line = number of books
        for (int i = 0; i < bookCount; i++)
            books[i].saveToFile(fout);
        fout.close();
    }

    // Load all books from books.txt
    void loadBooks() {
        ifstream fin("books.txt");    // open file for reading
        if (!fin) return;             // file doesn't exist yet — that's ok

        fin >> bookCount;
        fin.ignore();
        for (int i = 0; i < bookCount; i++)
            books[i].loadFromFile(fin);
        fin.close();

        // Re-count total issued from loaded data
        totalIssued = 0;
        for (int i = 0; i < bookCount; i++)
            if (books[i].getIsIssued()) totalIssued++;
    }

    // ============================================================
    //  FILE HANDLING — MEMBERS
    // ============================================================

    // Save all members to members.txt
    void saveMembers() const {
        ofstream fout("members.txt");
        if (!fout) {
            cout << "\n  [!] Error: Could not open members.txt for saving.\n";
            return;
        }
        fout << memberCount << "\n";
        for (int i = 0; i < memberCount; i++)
            members[i].saveToFile(fout);
        fout.close();
    }

    // Load all members from members.txt
    void loadMembers() {
        ifstream fin("members.txt");
        if (!fin) return;

        fin >> memberCount;
        fin.ignore();
        for (int i = 0; i < memberCount; i++)
            members[i].loadFromFile(fin);
        fin.close();
    }

    // ============================================================
    //  BOOK OPERATIONS
    // ============================================================

    void addBook(int id, string title, string author, string genre) {
        if (findBook(id) != -1) { cout << "\n  [!] Book ID " << id << " already exists!\n"; return; }
        if (bookCount >= 100)   { cout << "\n  [!] Library is full.\n"; return; }
        books[bookCount++] = Book(id, title, author, genre);
        saveBooks();   // save after every change
        cout << "\n  [+] Book added and saved successfully!\n";
    }

    void deleteBook(int id) {
        int idx = findBook(id);
        if (idx == -1)                   { cout << "\n  [!] Book not found.\n"; return; }
        if (books[idx].getIsIssued())    { cout << "\n  [!] Cannot delete — book is currently issued.\n"; return; }
        for (int i = idx; i < bookCount - 1; i++) books[i] = books[i + 1];
        bookCount--;
        saveBooks();
        cout << "\n  [+] Book deleted and saved successfully!\n";
    }

    void displayAllBooks() const {
        if (bookCount == 0) { cout << "\n  No books in library yet.\n"; return; }
        cout << "\n  ================================================" << endl;
        cout << "             ALL BOOKS IN LIBRARY"                   << endl;
        cout << "  ================================================" << endl;
        for (int i = 0; i < bookCount; i++) books[i].display();
    }

    void searchBookByID(int id) const {
        int idx = findBook(id);
        if (idx == -1) { cout << "\n  [!] No book found with ID " << id << ".\n"; return; }
        cout << "\n  [Found]\n";
        books[idx].display();
    }

    void searchBookByTitle(string keyword) const {
        bool found = false;
        cout << "\n  Results for \"" << keyword << "\" :\n";
        cout << "  ------------------------------------------------" << endl;
        for (int i = 0; i < bookCount; i++) {
            string t = books[i].getTitle(), tl = "", kl = "";
            for (char c : t)       tl += tolower(c);
            for (char c : keyword) kl += tolower(c);
            if (tl.find(kl) != string::npos) { books[i].display(); found = true; }
        }
        if (!found) cout << "  No books matched.\n";
    }

    void quickBookList() const {
        cout << "\n  Quick List:\n";
        cout << "  ------------------------------------------------" << endl;
        for (int i = 0; i < bookCount; i++) printBookSummary(books[i]);
    }

    // ============================================================
    //  MEMBER OPERATIONS
    // ============================================================

    void addMember(int id, string name, string contact) {
        if (findMember(id) != -1) { cout << "\n  [!] Member ID already exists!\n"; return; }
        if (memberCount >= 100)   { cout << "\n  [!] Member limit reached.\n"; return; }
        members[memberCount++] = Member(id, name, contact);
        saveMembers();
        cout << "\n  [+] Member registered and saved successfully!\n";
    }

    void displayAllMembers() const {
        if (memberCount == 0) { cout << "\n  No members registered yet.\n"; return; }
        cout << "\n  ================================================" << endl;
        cout << "            ALL REGISTERED MEMBERS"                   << endl;
        cout << "  ================================================" << endl;
        for (int i = 0; i < memberCount; i++) members[i].display();
    }

    void searchMemberByID(int id) const {
        int idx = findMember(id);
        if (idx == -1) { cout << "\n  [!] Member not found.\n"; return; }
        cout << "\n  [Found]\n";
        members[idx].display();
    }

    // ============================================================
    //  ISSUE & RETURN
    // ============================================================

    void issueBook(int memberID, int bookID) {
        int mIdx = findMember(memberID);
        int bIdx = findBook(bookID);
        if (mIdx == -1) { cout << "\n  [!] Member not found.\n";  return; }
        if (bIdx == -1) { cout << "\n  [!] Book not found.\n";    return; }
        if (members[mIdx].getIssuedBookID() != -1) {
            cout << "\n  [!] Member already has a book issued. Return it first.\n"; return;
        }
        if (books[bIdx].getIsIssued()) {
            cout << "\n  [!] Book is already issued to another member.\n"; return;
        }
        books[bIdx].setIssued(true, memberID);
        members[mIdx].setIssuedBookID(bookID);
        members[mIdx].incrementBorrowed();
        totalIssued++;
        saveBooks();
        saveMembers();
        cout << "\n  [+] \"" << books[bIdx].getTitle()
             << "\" issued to " << members[mIdx].getName() << " successfully!\n";
    }

    void returnBook(int memberID) {
        int mIdx = findMember(memberID);
        if (mIdx == -1) { cout << "\n  [!] Member not found.\n"; return; }
        int bID  = members[mIdx].getIssuedBookID();
        if (bID == -1)  { cout << "\n  [!] This member has no book to return.\n"; return; }
        int bIdx = findBook(bID);
        books[bIdx].setIssued(false, -1);
        members[mIdx].setIssuedBookID(-1);
        members[mIdx].decrementBorrowed();
        totalIssued--;
        saveBooks();
        saveMembers();
        cout << "\n  [+] Book returned by " << members[mIdx].getName() << " successfully!\n";
    }

    // ============================================================
    //  STATISTICS
    // ============================================================

    void showStats() const {
        cout << "\n  ===== Library Statistics =====" << endl;
        cout << "  Total Books     : " << bookCount           << endl;
        cout << "  Total Members   : " << memberCount         << endl;
        cout << "  Books Issued    : " << getTotalIssued()    << endl;
        cout << "  Books Available : " << bookCount - getTotalIssued() << endl;
        cout << "  ================================" << endl;
    }

    // ============================================================
    //  POLYMORPHISM DEMO
    //  Person* base pointer calling display() on both
    //  Librarian and Member — same function, different behavior
    // ============================================================

    void showAllPersonsInfo() const {
        cout << "\n  ================================================" << endl;
        cout << "      ALL PERSONS INFO  [Polymorphism Demo]"         << endl;
        cout << "  ================================================" << endl;

        // Person pointer pointing to Librarian
        cout << "\n  [ LIBRARIAN ]\n";
        const Person* p = &admin;
        p->display();   // calls Librarian::display()

        // Same Person pointer, now pointing to each Member
        for (int i = 0; i < memberCount; i++) {
            cout << "\n  [ MEMBER ]\n";
            p = &members[i];
            p->display();   // calls Member::display()
        }
    }
};

// Static member definition (must be outside class)
int Library::totalIssued = 0;

#endif
