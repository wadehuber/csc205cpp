#include "Train.h"

Train::Train() {
    front = new TrainCar<std::string>("Engine", true);
    caboose = front;
    size = 1;
    addCar("Caboose");
}

Train::~Train() {
    // Walk the chain of cars, deleting each one.
    TrainCar<std::string>* current = front;
    while (current != nullptr) {
        TrainCar<std::string>* nextCar = current->getNext();
        delete current;
        current = nextCar;
    }
}

void Train::addCar(std::string name) {
    TrainCar<std::string>* newCar = new TrainCar<std::string>(name);
    TrainCar<std::string>* current = front;

    while ((current->getNext() != nullptr) && (current->getNext()->getPayload() != "Caboose"))
        current = current->getNext();

    newCar->setNext(current->getNext());
    current->setNext(newCar);
    size++;
}

int Train::length() {
    return size;
}

std::string Train::toString() const {
    TrainCar<std::string>* current = front;
    std::string ret = "_____<";

    while (current != nullptr) {
        ret += " | " + current->toString();
        current = current->getNext();
    }
    ret += " |+______";

    return ret;
}
