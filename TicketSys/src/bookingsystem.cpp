#include "bookingsystem.h"

void BookingSystem::bookSeats(Show* show, const std::string& customerName, const std::vector<std::string>& seatNumbers) {
    for (const auto& number : seatNumbers) {
        Seat* seat = show->findSeat(number);
        if (seat && !seat->isBooked) {
            seat->isBooked = true;
        }
    }
    NotificationSystem::addNotification("Booking made by " + customerName + " for " + show->movie->title + " at " + show->time);
}
void BookingSystem::cancelBooking(Show* show, const std::string& customerName, const std::vector<std::string>& seatNumbers) {
    for (const auto& number : seatNumbers) {
        Seat* seat = show->findSeat(number);
        if (seat && seat->isBooked) {
            seat->isBooked = false;
        }
    }
    NotificationSystem::addNotification("Booking canceled by " + customerName + " for " + show->movie->title + " at " + show->time);
}