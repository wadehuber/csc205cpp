#ifndef TEAM_H
#define TEAM_H

// Java: "public interface Team<T> extends Iterable<T>".
// A generic (templated) interface -> a class template of pure virtual
// functions. (Java's "extends Iterable<T>" means it can be used in a
// for-each loop; in C++ the concrete class would add begin()/end().)
template <typename T>
class Team {
public:
    virtual ~Team() = default;

    virtual void addMember(T item) = 0;
    virtual bool isTeamEmpty() = 0;
    virtual int memberCount() = 0;
};

#endif
