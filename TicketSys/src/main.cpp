#include <iostream>
#include "precompiler.h"
int main() {
    Show show("Back to the Future", "10:17 PM");
    show.generateSeats(12);
    bool running = true;
    while (running) {
        std::string customerName;
        int seatNumber;
        show.displaySeats();
        std::cout << "Enter your name: ";
        std::cin >> customerName;
        std::cout << "Choose seat number: ";
        std::cin >> seatNumber;
        if (!show.isSeatAvailable(seatNumber)) {
            std::cout << "Seat is already booked or invalid. Try again.\n";
            continue;
        }
        show.bookSeat(seatNumber);
        Seat selected = show.getSeat(seatNumber);
        Booking b(customerName, show, selected);
        b.saveToFile("bookings.txt");
        std::cout << "Booking confirmed for " << customerName << " - Seat #" << selected.getNumber() << " (" << selected.getType() << ")\n";
        std::cout << "Book another? (1 = Y / 0 = N): ";
        std::cin >> running;
    }
    return 0;
}
