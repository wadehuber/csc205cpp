#ifndef TRAINCAR_H
#define TRAINCAR_H

#include <string>
#include <sstream>

//  @author Wade Huber
//
//  Adapted from LinearNode by Lewis, DePasquale, and Chase
//
//  Represents a train car.
//
//  This is a generic (templated) class, so it lives entirely in the header.
template <typename T>
class TrainCar {
private:
    /** reference to the next car in the train */
    TrainCar<T>* next;

    /** payload stored in this car (used for name if no payload) */
    T payload;

    /** indicates if the car is an engine or not */
    bool engine;

public:
    /** Creates a train car. */
    TrainCar() {
        next = nullptr;
        payload = T();      // Java used null; C++ uses a default-constructed value
        engine = false;
    }

    /** Creates a train car storing the specified payload. */
    TrainCar(T pay) {
        this->next = nullptr;
        this->payload = pay;
        this->engine = false;
    }

    /** Creates a train car storing the specified payload. */
    TrainCar(T pay, bool engine) {
        this->next = nullptr;
        this->payload = pay;
        this->engine = engine;
    }

    /** Returns the car that follows this one. */
    TrainCar<T>* getNext() {
        return next;
    }

    /** Sets the car that follows this one. */
    void setNext(TrainCar<T>* car) {
        next = car;
    }

    /** Returns the payload stored in this car. */
    T getPayload() {
        return payload;
    }

    /** Sets the payload stored in this car. */
    void setPayload(T pay) {
        payload = pay;
    }

    bool isEngine() {
        return engine;
    }

    std::string toString() const {
        std::string engStr = "";
        if (engine) {
            engStr = "#";
        }
        // ostringstream lets us join the payload (any type T) into a string.
        std::ostringstream out;
        out << "[" << engStr << payload << engStr << "]";
        return out.str();
    }
};

#endif
