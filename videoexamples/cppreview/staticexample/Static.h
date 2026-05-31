// Static.h
// C++ version of Static.java (header).
//
// Java review topic: static vs non-static (instance) members.
//   - A STATIC member is shared by ALL objects of the class (one copy total).
//   - A NON-STATIC (instance) member: each object gets its own copy.
//
// KEY C++ DETAIL: a static data member is only DECLARED in the header. It must
// be DEFINED exactly once in the .cpp (e.g. int Static::counter = 0;), or the
// linker will complain. (Java initialized statics inline; C++ separates this.)

#ifndef STATIC_H
#define STATIC_H

#include <string>

class Static {
private:
    static int staticVariable;   // Static - shared by all objects
    int nonStaticVariable;       // Non-static - each object gets its own copy
    std::string name;
    static const int answer = 42;  // a const static int may be initialized inline

    int myNum;                   // Non-static - each object gets its own copy
    static int counter;          // Static - shared by all objects

public:
    Static(std::string name, int nonStaticVariable);

    // Static method - called as Static::staticMethod(x), no object needed.
    // Can only access static members.
    static void staticMethod(int x);

    // Non-static method - called on an object.
    void nonStaticMethod(int x);

    std::string toString() const;
};

#endif
