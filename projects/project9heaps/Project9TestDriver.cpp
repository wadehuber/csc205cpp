// Project9TestDriver -- C++ conversion of Project9TestDriver.java
//
// Exercises HeapStack and HeapQueue (a stack/queue built on a heap) plus the
// Sorting.smallest_n helper. NOTE: in the starter code HeapStack, HeapQueue,
// and Sorting.smallest_n are STUDENT STUBS, so the program's interesting output
// is produced once students complete those methods. Until then the stack/queue
// report size 0 and a "null"-equivalent top/front, exactly as the Java starter.

#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include "jsjf/HeapStack.h"
#include "jsjf/HeapQueue.h"
#include "csc205/Sorting.h"

// Java printed Integer objects: a real value shows as the number, and the
// stubbed "return null" shows the literal text "null". Our HeapStack/HeapQueue
// stubs return T() (i.e. 0 for int). To mirror the Java starter's visible
// output, we print the stub's default-constructed value the same way Java
// printed null. Here we simply stream the int value (peek()/first() return 0).
//
// Java's Arrays.asList(...) and ArrayList.toString() render as "[a, b, c]".
// This helper reproduces that formatting for a container of values.
template <typename Container>
std::string toJavaListString(const Container& c) {
    std::ostringstream out;
    out << "[";
    bool first = true;
    for (const auto& e : c) {
        if (!first)
            out << ", ";
        out << e;
        first = false;
    }
    out << "]";
    return out.str();
}

int main() {
    HeapStack<int> hstack;            // Java: HeapStack<Integer>
    HeapQueue<int> hqueue;            // Java: HeapQueue<Integer>
    int numbers[10];                  // Java: Integer numbers[] = new Integer[10]

    // Java used java.util.Random with rand.nextInt(20)+1 (values 1..20).
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 20);

    std::cout << "Project 9 test driver" << std::endl;

    for (int ii = 0; ii < 10; ii++) {
        int nextNum = dist(gen);      // Java: rand.nextInt(20) + 1
        hstack.push(nextNum);
        hqueue.enqueue(nextNum);
        numbers[ii] = nextNum;
    }

    std::cout << "Test array: " << toJavaListString(numbers) << std::endl;
    std::cout << "    Top of HeapStack : " << hstack.peek() << std::endl;
    std::cout << "    Front of HeapQueue : " << hqueue.first() << std::endl;

    std::cout << "    HeapStack of " << hstack.size() << ": ";
    while (hstack.size() > 0) {
        std::cout << hstack.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "    HeapQueue of " << hqueue.size() << ": ";
    while (hqueue.size() > 0) {
        std::cout << hqueue.dequeue() << " ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "Smallest N of " << toJavaListString(numbers) << std::endl;
    std::cout << "    First 1: " << toJavaListString(Sorting::smallest_n(numbers, 1)) << std::endl;
    std::cout << "    First 4: " << toJavaListString(Sorting::smallest_n(numbers, 4)) << std::endl;
    std::cout << "    First 8: " << toJavaListString(Sorting::smallest_n(numbers, 8)) << std::endl;

    return 0;
}
