#  Library Management System
### Object-Oriented Programming Project — C++

 
##  About the Project

A console-based Library Management System built in C++ that demonstrates all six core OOP concepts. The system has two user roles — Admin (Librarian) and Student — each with their own menu and access level. Data is saved permanently using file handling so nothing is lost when the program closes.



##  OOP Concepts Demonstrated

| Concept | Where Used |
|--------|------------|
| **Classes & Objects** | Book, Person, Member, Librarian, Library |
| **Encapsulation** | Private data with public getters/setters in all classes |
| **Abstraction** | `Person` is abstract — has pure virtual `display()` |
| **Inheritance** | `Member` and `Librarian` both inherit from `Person` |
| **Polymorphism** | `Person*` pointer calls `display()` on Member & Librarian |
| **Composition** | `Library` contains arrays of `Book[]` and `Member[]` |
| **Static Member** | `totalIssued` — shared across all Library objects |
| **Friend Function** | `printBookSummary()` accesses private data of `Book` |
| **File Handling** | `books.txt` and `members.txt` save data permanently |




> **Admin Password:** `admin123`

## Uml 

<img width="317" height="321" alt="image" src="https://github.com/user-attachments/assets/0d5c7033-607e-47aa-a3e8-5dc461ad9912" />


##  Features

**Admin Menu**
- Add / Delete Books
- Display All Books
- Search Book by ID or Title
- Quick Book List
- Register Members
- Display / Search Members
- Issue Book to Member
- Return Book from Member
- Library Statistics
- Polymorphism Demo (Option 13)

**Student Menu**
- Display All Books
- Search Book by ID or Title
- Library Statistics

 
 ## File Handling

The system automatically saves all data to text files:

- `books.txt` — stores all book records
- `members.txt` — stores all member records

Data is saved every time you **add, delete, issue, or return** a book. When you run the program again, all previous data is loaded back automatically.




## Screenshots

**Login Screen**

<img width="372" height="200" alt="image" src="https://github.com/user-attachments/assets/3a6a8b21-570e-4f65-83b4-ffadc6494652" />


**Admin Menu**

<img width="359" height="267" alt="image" src="https://github.com/user-attachments/assets/8593fef1-ca21-42dd-bf5f-ca00f85a01ac" />


**Student Menu**

<img width="664" height="300" alt="image" src="https://github.com/user-attachments/assets/dd64dd0d-3b99-4c84-a69d-99fee9c6671c" />

