#ifndef ARRAYLISTTEAM_H
#define ARRAYLISTTEAM_H

#include <string>
#include "Team.h"

// Starter code: a stub implementation of the Team interface for you to
// complete. The method bodies are placeholders (just like the Java
// version's "TODO Auto-generated method stub").
//
// This is a generic (templated) class, so it lives entirely in the header.
template <typename T>
class ArrayListTeam : public Team<T> {
public:
    ArrayListTeam() {
    }

    std::string toString() const {
        return "";
    }

    void addMember(T item) override {
        // TODO: implement
        (void) item;   // (silences the "unused parameter" warning for now)
    }

    bool isTeamEmpty() override {
        // TODO: implement
        return false;
    }

    int memberCount() override {
        // TODO: implement
        return 0;
    }
};

#endif
