#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include "TrainCar.h"

//  @author Wade Huber
//
//  Represents a train.
class Train {
private:
    TrainCar<std::string>* front;
    TrainCar<std::string>* caboose;

    int size;

public:
    Train();

    // C++ needs a destructor to free the cars we created with "new"
    // (Java's garbage collector did this automatically).
    ~Train();

    void addCar(std::string name);
    int length();
    std::string toString() const;
};

#endif
