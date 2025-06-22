#include <iostream>
#include "cinema.h"
#include "movie.h"

int main() {
    Cinema c("Cinema City", "Burgas");
    std::cout << "Cinema: " << c.getName() << ", City: " << c.getCity() << "\n";
    Movie m("Back to the Future", "Science Fiction");
    std::cout << "Movie: " << m.getTitle() << ", Genre: " << m.getGenre() << "\n";
    return 0;
}

