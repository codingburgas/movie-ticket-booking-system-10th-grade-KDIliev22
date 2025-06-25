#include "show.h"
#include <iostream>

Show::Show() : movieTitle(""), time("") {}
Show::Show(const std::string& movieTitle, const std::string& time) : movieTitle(movieTitle), time(time) {}
std::string Show::getMovieTitle() const {
    return movieTitle;
}
std::string Show::getTime() const {
    return time;
}
void Show::generateSeats(int count) {
    seats.clear();
    for (int i = 1; i <= count; ++i) {
        std::string type = "Silver";
        if (i > count * 2 / 3) type = "Gold";
        if (i > count * 5 / 6) type = "Platinum";
        seats.emplace_back(i, type);
    }
}
void Show::displaySeats() const {
    std::cout << "Available seats for " << movieTitle << " at " << time << ":\n";
    for (const auto& seat : seats) {
        std::cout << "[#" << seat.getNumber() << " - " << seat.getType() << " - " << (seat.isBooked() ? "Booked" : "Available") << "] ";
    }
    std::cout << "\n";
}
bool Show::bookSeat(int seatNumber) {
    for (auto& seat : seats) {
        if (seat.getNumber() == seatNumber && !seat.isBooked()) {
            seat.book();
            return true;
        }
    }
    return false;
}

bool Show::isSeatAvailable(int seatNumber) const {
    for (const auto& seat : seats) {
        if (seat.getNumber() == seatNumber && !seat.isBooked()) {
            return true;
        }
    }
    return false;
}
Seat Show::getSeat(int seatNumber) const {
    for (const auto& seat : seats) {
        if (seat.getNumber() == seatNumber) {
            return seat;
        }
    }
    return Seat();
}