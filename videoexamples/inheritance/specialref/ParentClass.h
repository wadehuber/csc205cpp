#ifndef PARENTCLASS_H
#define PARENTCLASS_H

#include <string>

class ParentClass {
protected:
    std::string myName;
    int num;

public:
    ParentClass(int num);

    // 'virtual' so the child's version is used through a base reference,
    // matching Java's @Override. A polymorphic base also needs a virtual
    // destructor.
    virtual ~ParentClass() = default;

    virtual std::string toString() const;
};

#endif
