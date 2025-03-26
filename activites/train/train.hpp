#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include "traincar.hpp"

class Train {
private:
    TrainCar<std::string>* front;
    TrainCar<std::string>* caboose;
    int size;

public:
    Train() {
        front = new TrainCar<std::string>("Engine", true);
        caboose = front;
        size = 1;
        addCar("Caboose");
    }

    ~Train() {
        TrainCar<std::string>* current = front;
        while (current != nullptr) {
            TrainCar<std::string>* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    void addCar(const std::string& name) {
        TrainCar<std::string>* newCar = new TrainCar<std::string>(name);
        TrainCar<std::string>* current = front;

        while (current->getNext() != nullptr && current->getNext()->getPayload() != "Caboose") {
            current = current->getNext();
        }

        newCar->setNext(current->getNext());
        current->setNext(newCar);
        size++;
    }

    int length() const {
        return size;
    }

    std::string toString() const {
        std::string result = "_____<";
        TrainCar<std::string>* current = front;
        while (current != nullptr) {
            result += " | " + current->toString();
            current = current->getNext();
        }
        result += " |+______";
        return result;
    }
};

#endif
