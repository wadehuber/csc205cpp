#ifndef TEAM_H
#define TEAM_H

// Java: "interface Team<T> extends Iterable<T>".
//
// A generic (templated) interface -- see Bag.h for notes on what
// "template <typename T>" and the pure virtual functions ("= 0") mean.
template <typename T>
class Team {
public:
    virtual ~Team() = default;

    virtual void addMember(T item) = 0;
    virtual bool isTeamEmpty() = 0;
    virtual int memberCount() = 0;
};

#endif
