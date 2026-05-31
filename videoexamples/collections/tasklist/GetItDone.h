// GetItDone.h
// C++ version of GetItDone.java (header).
//
// GetItDone "implements" the ToDoList interface (inherits the abstract base
// class) and stores its Tasks in a std::vector (Java used an ArrayList).
//
// Because Java's ToDoList extended Iterable<Task>, GetItDone could be looped
// over. We follow the course convention and provide BOTH ways to iterate:
//   1. Java-style: iterator() returning an object with hasNext()/next()
//   2. C++-style:  begin()/end() so a range-based for loop works

#ifndef GETITDONE_H
#define GETITDONE_H

#include <vector>
#include <string>
#include <cstddef>
#include "ToDoList.h"
#include "Task.h"

class GetItDone : public ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(Task p) override;
    void printTasks() override;

    std::string toString() const;

    // ----- Style 1: Java-style iterator (hasNext()/next()) -----
    class Iterator {
    private:
        const std::vector<Task>* tasks;
        std::size_t pos;
    public:
        Iterator(const std::vector<Task>* tasks, std::size_t pos)
            : tasks(tasks), pos(pos) {}
        bool hasNext() const {
            return pos < tasks->size();
        }
        Task next() {
            return (*tasks)[pos++];
        }
    };

    Iterator iterator() const {
        return Iterator(&tasks, 0);
    }

    // ----- Style 2: C++ range-based for support -----
    std::vector<Task>::const_iterator begin() const {
        return tasks.begin();
    }
    std::vector<Task>::const_iterator end() const {
        return tasks.end();
    }
};

#endif
