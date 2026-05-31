#ifndef BASE_H
#define BASE_H

class Base {
protected:
    int a;

public:
    Base(int a);

    // 'virtual' so a subclass can override it (print() is overridden below).
    virtual ~Base() = default;

    virtual void change(int x);
    virtual void print();
};

#endif
