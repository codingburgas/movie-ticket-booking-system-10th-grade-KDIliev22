#include "seat.h"

Seat::Seat() : number(0), type("Silver"), booked(false) {}

Seat::Seat(int number, const std::string& type) : number(number), type(type), booked(false) {}

int Seat::getNumber() const {
    return number;
}
std::string Seat::getType() const {
    return type;
}
bool Seat::isBooked() const {
    return booked;
}

void Seat::book() {
    booked = true;
}
