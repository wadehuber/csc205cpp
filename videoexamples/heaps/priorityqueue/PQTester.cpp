// PQTester - priority queue test driver class.
//
// Translated from PQTester.java. Adds string elements with various priorities,
// then drains the queue, which prints them in priority order (ties broken by
// arrival order).

#include <iostream>
#include <string>
#include "PriorityQueue.h"

int main() {
    PriorityQueue<std::string> pq;

    pq.addElement("first", 1);
    pq.addElement("bbb", 200);
    pq.addElement("third", 50);
    pq.addElement("fifth", 92);
    pq.addElement("second", 10);
    pq.addElement("fourth", 55);
    pq.addElement("aaa", 200);
    pq.addElement("this one should be first", 0);

    while (!pq.isEmpty()) {
        std::cout << pq.removeNext() << std::endl;
    }

    return 0;
}
