#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "movie.h"

class Show {
public:
    std::string time;
    Movie* movie;
    Show* next;
    Show(std::string t, Movie* m) : time(t), movie(m), next(nullptr) {}
};

#endif //SHOW_H
