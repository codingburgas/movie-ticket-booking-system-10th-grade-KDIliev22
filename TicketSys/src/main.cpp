#include <iostream>
#include "precompiler.h"
int main() {

    // Testing section, will be removed
    Cinema c("Cinema City", "Burgas");
    std::cout << "Cinema: " << c.getName() << ", City: " << c.getCity() << "\n";
    Movie m("Back to the Future", "Science Fiction");
    std::cout << "Movie: " << m.getTitle() << ", Genre: " << m.getGenre() << "\n";
    Show s(m.getTitle(), "10:17 PM");
    std::cout << "Show: " << s.getMovieTitle() << " at " << s.getTime() << "\n";
    Seat seat1(1, "Gold");
    std::cout << "Seat #" << seat1.getNumber() << ", Type: " << seat1.getType()
              << ", Booked: " << seat1.isBooked() << "\n";
    seat1.book();
    std::cout << "After booking: Booked: " << seat1.isBooked() << "\n";
    Booking booking("ASDF", s, seat1);
    std::cout << "Booking for: " << booking.getCustomerName() << ", Movie: " << booking.getShow().getMovieTitle() << ", Seat #: " << booking.getSeat().getNumber() << "\n";
    User u("Panyu", "Antonovski");
    std::cout << "User: " << u.getUsername() << "\n";
    std::cout << "Password check (Panyu): " << u.checkPassword("Antonovuski") << "\n";
    return 0;
}

