#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    int    id;
    string name;
    string contact;

public:
    // Default Constructor
    Person() : id(0), name(""), contact("") {}

    // Parameterized Constructor
    Person(int i, string n, string c) : id(i), name(n), contact(c) {}

    // Getters (Encapsulation)
    int    getID()      const { return id;      }
    string getName()    const { return name;    }
    string getContact() const { return contact; }

    // Setters
    void setName(string n)    { name    = n; }
    void setContact(string c) { contact = c; }

    // Pure Virtual Function -> makes Person ABSTRACT (Abstraction)
    // Every child class MUST override this
    virtual void display() const = 0;

    // Virtual Destructor (good practice with inheritance)
    virtual ~Person() {}
};

#endif
