#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string title;
    std::string genre;

public:
    Movie();
    Movie(const std::string& title, const std::string& genre);
    std::string getTitle() const;
    std::string getGenre() const;
};

#endif
