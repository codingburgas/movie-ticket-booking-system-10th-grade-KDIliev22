#include <iostream>
#include "cinema.h"
#include "movie.h"
#include "show.h"
#include "seat.h"

int main() {
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

    return 0;
}

