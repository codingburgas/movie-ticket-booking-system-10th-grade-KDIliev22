#include "movie.h"

Movie::Movie() : title(""), genre("") {}

Movie::Movie(const std::string& title, const std::string& genre) : title(title), genre(genre) {}
std::string Movie::getTitle() const {
    return title;
}
std::string Movie::getGenre() const {
    return genre;
}
