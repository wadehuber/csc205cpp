#ifndef TEAM_H
#define TEAM_H

template <typename T>
class Team {
public:
    virtual void addMember(T item) = 0;
    virtual bool isTeamEmpty() const = 0;
    virtual int memberCount() const = 0;
    virtual ~Team() = default;
};

#endif
