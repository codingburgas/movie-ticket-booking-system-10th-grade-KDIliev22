#include "booking.h"

Booking::Booking(const std::string& customerName, const Show& show, const Seat& seat) : customerName(customerName), show(show), seat(seat) {}
std::string Booking::getCustomerName() const {
    return customerName;
}
Show Booking::getShow() const {
    return show;
}
Seat Booking::getSeat() const {
    return seat;
}
void Booking::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    file << customerName << "," << show.getMovieTitle() << "," << seat.getNumber() << "\n";
    file.close();
}

