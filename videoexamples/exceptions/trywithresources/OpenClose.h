#ifndef OPENCLOSE_H
#define OPENCLOSE_H

#include <string>

// A resource that prints when it opens and when it closes.
// In Java this was "class OpenClose implements AutoCloseable" with a
// close() method, used in a try-with-resources statement.
//
// C++ has no try-with-resources and no AutoCloseable. Instead C++ uses RAII
// ("Resource Acquisition Is Initialization"): the work that Java did in
// close() goes in the DESTRUCTOR ~OpenClose(). The destructor runs
// automatically when the object goes out of scope (at the end of its
// enclosing { } block), so there is no try-with-resources needed.
//
// We also keep an explicit close() method so the example can stay 1-1 with
// the Java that called oc1.close() by hand -- but the idiomatic C++ way is
// just to let the destructor handle it via scoping.
class OpenClose {
private:
    std::string label;
    bool closed = false;   // guard so close() isn't done twice

public:
    explicit OpenClose(const std::string& l);
    ~OpenClose();

    void close();
};

#endif
