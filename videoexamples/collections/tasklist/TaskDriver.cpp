// TaskDriver.cpp
// C++ version of TaskDriver.java.
//
// Builds a GetItDone to-do list and prints its tasks.

#include "GetItDone.h"
#include "Task.h"

int main() {
    GetItDone myStuffToDo;

    myStuffToDo.addTask(Task(5, "Mow the lawn"));
    myStuffToDo.addTask(Task(1, "Do homework"));
    myStuffToDo.addTask(Task(3, "Wash the car"));

    myStuffToDo.printTasks();

    return 0;
}
