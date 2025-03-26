#ifndef ARRAYLISTTEAM_H
#define ARRAYLISTTEAM_H

#include "team.hpp"
#include <vector>
#include <string>
#include <sstream>

template <typename T>
class ArrayListTeam : public Team<T> {
private:
    std::vector<T> members;

public:
    ArrayListTeam() = default;

    void addMember(T item) override {
        // Complete as part of activity
    }

    bool isTeamEmpty() const override {
        // Complete as part of activity
        return false;
    }

    int memberCount() const override {
        // Complete as part of activity
        return 0;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < members.size(); ++i) {
            oss << members[i];
            if (i < members.size() - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    // Iterator access
    typename std::vector<T>::iterator begin() { return members.begin(); }
    typename std::vector<T>::iterator end() { return members.end(); }

    typename std::vector<T>::const_iterator begin() const { return members.begin(); }
    typename std::vector<T>::const_iterator end() const { return members.end(); }
};

#endif
