#ifndef TRAINCAR_H
#define TRAINCAR_H

#include <iostream>
#include <string>

template <typename T>
class TrainCar {
private:
    TrainCar<T>* next;
    T payload;
    bool engine;

public:
    TrainCar() : next(nullptr), payload(T()), engine(false) {}

    TrainCar(T pay) : next(nullptr), payload(pay), engine(false) {}

    TrainCar(T pay, bool isEngine) : next(nullptr), payload(pay), engine(isEngine) {}

    TrainCar<T>* getNext() const {
        return next;
    }

    void setNext(TrainCar<T>* car) {
        next = car;
    }

    T getPayload() const {
        return payload;
    }

    void setPayload(T pay) {
        payload = pay;
    }

    bool isEngine() const {
        return engine;
    }

    std::string toString() const {
        std::string engStr = engine ? "#" : "";
        return "[" + engStr + payload + engStr + "]";
    }
};

#endif
