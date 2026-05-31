#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H

#include <vector>
#include <string>
#include <sstream>     // std::ostringstream, used to build the toString() text
#include "EasyCollection.h"

// A generic collection that can hide "secret" items.
//
// NOTE: template classes are written entirely in the header file -- there
// is no MyCollection.cpp. (C++ needs to see the whole template to build it
// for a specific type like MyCollection<int>.)
template <typename T>
class MyCollection : public EasyCollection<T> {
private:
    // A small helper that remembers an item and whether it is secret.
    // (Java used a private inner class called CollectionItem.)
    struct CollectionItem {
        T item;
        bool secret;
    };

    std::vector<CollectionItem> items;

public:
    // Java's add(): the item is NOT secret.
    void add(T thing) override {
        items.push_back(CollectionItem{thing, false});
    }

    // A secret item: it is stored, but hidden from toString() and the loops.
    void addSecret(T thing) {
        items.push_back(CollectionItem{thing, true});
    }

    int size() const {
        return (int) items.size();
    }

    // Remove the first item equal to 'thing'.
    void remove(T thing) override {
        for (std::size_t i = 0; i < items.size(); i++) {
            if (items[i].item == thing) {
                items.erase(items.begin() + i);
                return;
            }
        }
    }

    // Java's toString(): list only the non-secret items.
    std::string toString() const {
        std::ostringstream out;
        for (std::size_t i = 0; i < items.size(); i++) {
            if (!items[i].secret) {
                out << items[i].item << " ";
            }
        }
        return out.str();
    }

    // -----------------------------------------------------------------
    // Style 1: a Java-style iterator with hasNext()/next().
    // Used like:  while (it.hasNext()) { ... it.next() ... }
    // -----------------------------------------------------------------
    class Iterator {
    private:
        std::vector<T> elements;   // a copy of just the non-secret items
    public:
        Iterator(const std::vector<CollectionItem>& items) {
            for (std::size_t i = 0; i < items.size(); i++) {
                if (!items[i].secret) {
                    elements.push_back(items[i].item);
                }
            }
        }
        bool hasNext() const {
            return elements.size() > 0;
        }
        T next() {
            T ret = elements.front();      // first remaining element
            elements.erase(elements.begin());
            return ret;
        }
    };

    // Like Java's iterator() method.
    Iterator iterator() const {
        return Iterator(items);
    }

    // -----------------------------------------------------------------
    // Style 2: support for C++'s range-based for loop:
    //     for (int x : values) { ... }
    // This requires begin() and end(). The iterator below walks the
    // items but skips the secret ones, so the loop only sees real items.
    // (operator++, operator*, operator!= are what the for loop calls
    // behind the scenes.)
    // -----------------------------------------------------------------
    class RangeIterator {
    private:
        const std::vector<CollectionItem>* items;
        std::size_t pos;

        void skipSecret() {
            while (pos < items->size() && (*items)[pos].secret) {
                pos++;
            }
        }
    public:
        RangeIterator(const std::vector<CollectionItem>* items, std::size_t pos)
            : items(items), pos(pos) {
            skipSecret();
        }
        bool operator!=(const RangeIterator& other) const {
            return pos != other.pos;
        }
        const T& operator*() const {
            return (*items)[pos].item;
        }
        RangeIterator& operator++() {
            pos++;
            skipSecret();
            return *this;
        }
    };

    RangeIterator begin() const {
        return RangeIterator(&items, 0);
    }
    RangeIterator end() const {
        return RangeIterator(&items, items.size());
    }
};

#endif
