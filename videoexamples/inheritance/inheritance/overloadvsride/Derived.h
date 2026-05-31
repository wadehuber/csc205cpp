#ifndef DERIVED_H
#define DERIVED_H

#include <string>
#include "Base.h"

class Derived : public Base {
private:
    std::string s;

public:
    Derived(int a);
    Derived(int a, std::string s);

    // C++ NAME HIDING: as soon as Derived declares ANY method named
    // 'change', it hides ALL of Base's 'change' overloads. Without the line
    // below, "example.change(11)" would fail to compile because Base's
    // change(int) would be hidden. In Java the inherited change(int) stays
    // visible automatically; 'using Base::change;' restores that behavior so
    // overload resolution sees BOTH the inherited and the new overloads.
    using Base::change;

    // change(String) OVERLOADS change (same name, different parameters).
    void change(std::string y);

    // change(int, String) also OVERLOADS change.
    void change(int x, std::string y);

    // print() OVERRIDES Base::print() (same signature, virtual dispatch).
    void print() override;
};

#endif
