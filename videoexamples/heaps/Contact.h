#ifndef CONTACT_H
#define CONTACT_H

#include <string>

// Contact represents a phone contact.
//
// HEADER-ONLY: small demo data class.
//
// Java implemented Comparable<Contact> with compareTo(); C++ heaps/sorts use
// operator<. We define operator< (and operator== for completeness) so the
// generic structures can order Contacts exactly as Java's compareTo did:
// compare by last name, breaking ties by first name.
class Contact {
private:
    std::string firstName, lastName, phone;

public:
    // Sets up this contact with the specified information.
    Contact(const std::string& first, const std::string& last,
            const std::string& telephone)
        : firstName(first), lastName(last), phone(telephone) {}

    // Default constructor: needed because the generic ArrayList/heap store
    // values and occasionally default-construct a slot (Java used null).
    Contact() : firstName(""), lastName(""), phone("") {}

    // Returns a description of this contact as a string.
    std::string toString() const {
        return lastName + ", " + firstName + "\t" + phone;
    }

    // Java compareTo(): order by last name, then first name. Here we expose
    // the same logic through operator< as a private-style helper.
    int compareTo(const Contact& other) const {
        if (lastName == other.lastName)
            return firstName.compare(other.firstName);
        else
            return lastName.compare(other.lastName);
    }

    // operator< drives all the ordering in the generic heap/sort code.
    bool operator<(const Contact& other) const {
        return compareTo(other) < 0;
    }

    bool operator==(const Contact& other) const {
        return compareTo(other) == 0;
    }
};

#endif
