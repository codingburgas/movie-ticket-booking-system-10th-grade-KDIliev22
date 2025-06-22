#include "show.h"

Show::Show() : movieTitle(""), time("") {}
Show::Show(const std::string& movieTitle, const std::string& time) : movieTitle(movieTitle), time(time) {}

std::string Show::getMovieTitle() const {
    return movieTitle;
}
std::string Show::getTime() const {
    return time;
}
