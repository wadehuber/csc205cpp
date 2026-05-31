// Priority.h
// C++ version of Priority.java.
//
// Java's  interface Priority  becomes a C++ abstract base class: a class with
// pure virtual methods ( = 0 ) and a virtual destructor. Any class that
// "implements" Priority inherits from it and overrides these methods.

#ifndef PRIORITY_H
#define PRIORITY_H

class Priority {
public:
    virtual ~Priority() {}              // virtual destructor for a base class
    virtual void setPriority(int p) = 0;
    virtual int getPriority() = 0;
};

#endif
