#include <iostream>
#include "cinema.h"
#include "movie.h"
#include "show.h"

int main() {
    Cinema c("Cinema City", "Burgas");
    std::cout << "Cinema: " << c.getName() << ", City: " << c.getCity() << "\n";
    Movie m("Back to the Future", "Science Fiction");
    std::cout << "Movie: " << m.getTitle() << ", Genre: " << m.getGenre() << "\n";
    Show s(m.getTitle(), "10:17 PM");
    std::cout << "Show: " << s.getMovieTitle() << " at " << s.getTime() << "\n";
    return 0;
}

