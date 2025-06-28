#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;

    Movie* next;

    Movie(std::string t, std::string l, std::string g, std::string r) : title(t), language(l), genre(g), releaseDate(r), next(nullptr) {}
};

#endif //MOVIE_H
