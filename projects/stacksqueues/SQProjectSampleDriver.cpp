#include <iostream>
#include <string>

#include "csc205/StackQueueUtil.h"
#include "jsjf/LinkedQueue.h"
#include "jsjf/LinkedStack.h"

/**
 * Sample driver for the stacks & queues project.
 *
 * 1-1 translation of SQProjectSampleDriver.java. Where Java printed an object
 * directly (e.g. "+ q"), Java implicitly called that object's toString(); in
 * C++ we call .toString() explicitly. Note that several queue/stack methods
 * are stubs in the starter code, so this driver's output reflects those stubs
 * (size 0, empty toString(), isEmpty() always true, etc.) rather than a fully
 * working data structure.
 */
int main() {
    LinkedQueue<std::string> q;
    LinkedStack<std::string> s;

    std::string testStrings1[] = {"a", "aa", "aba", "abca", "aabcbaa", "aabbccbbaa",
                                  "1!a8 (a a&21a.", "abcCBA",
                                  "A man, a plan, a canal: Panama.",
                                  "Are we not drawn onward, we few, drawn onward to new era?",
                                  "ab", "notapalindrome"};
    std::string testStrings2[] = {"To be or not to be, that is the question.",
                                  "The best way to predict the future is to invent it",
                                  "ThisSentenceHasNoSpaces",
                                  "You're gonna need a bigger boat",
                                  "Code never lies, comments sometimes do.",
                                  "Computer Science is no more about computers than astronomy is about telescopes - E. Dijkstra"};

    // Queue testing
    q.enqueue("FAIL");
    q.enqueue("FRONTTESTGOOD");
    q.enqueue("the");
    q.enqueue("LinkedQueue");
    q.dequeue();
    q.enqueue("works!");

    std::cout << "\n\n=============== QUEUE TESTING ===============" << std::endl;
    std::cout << "Queue toString():\n------------ \n" << q.toString() << "------------\n" << std::endl;
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue front: " << q.first() << std::endl;
    q.dequeue();
    std::cout << "Queue dequeue test: " << q.dequeue() << " ";
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }

    // Stack testing
    s.push("works");
    s.push("LinkedStack");
    s.push("FAIL");
    s.pop();
    s.push("The");
    s.push("Wrong");
    s.pop();

    std::cout << "\n\n=============== STACK TESTING ===============" << std::endl;
    std::cout << "Stack toString():\n------------ \n" << s.toString() << "\n------------\n" << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;
    s.push("PEEKTESTGOOD");
    std::cout << "Stack peek: " << s.peek() << std::endl;
    s.pop();
    std::cout << "LinkedStack pop test : " << s.pop() << " ";
    while (!s.isEmpty()) {
        std::cout << s.pop() << " ";
    }

    std::cout << "\n\n=============== FUNCTION TESTING ===============" << std::endl;
    std::cout << "----- isPalindrome() testing -----" << std::endl;
    for (const std::string& str : testStrings1) {
        if (StackQueueUtil::isPalindrome(str)) {
            std::cout << "  TRUE: " << str << " is a palindrome." << std::endl;
        }
        else {
            std::cout << "  FALSE: " << str << " is a NOT palindrome." << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "----- reverseWords() testing -----" << std::endl;
    for (const std::string& str : testStrings2) {
        std::cout << StackQueueUtil::reverseWords(str) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- checkArrays() testing -----" << std::endl;
    int test1a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int test1b[] = {4, 3, 2, 1, 5, 10, 9, 8, 6, 7};
    int test2a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int test2b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    if (StackQueueUtil::checkArrays(4, 6, test1a, test1b)) {
        std::cout << "Arrays test1a & test1b are valid" << std::endl;
    }
    else {
        std::cout << "Arrays test1a & test1b are NOT valid" << std::endl;
    }
    if (StackQueueUtil::checkArrays(4, 6, test2a, test2b)) {
        std::cout << "Arrays test2a & test2b are valid" << std::endl;
    }
    else {
        std::cout << "Arrays test2a & test2b are NOT valid" << std::endl;
    }

    return 0;
}
