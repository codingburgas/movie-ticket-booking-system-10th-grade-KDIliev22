#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "cinema.h"
#include <vector>

class DataStorage {
public:
    static void saveMovies(Movie* movieHead);
    static Movie* loadMovies();
    static void saveHalls(Hall* hallHead);
    static Hall* loadHalls();
    static void saveShows(Hall* hallHead);
    static void loadShows(Hall* hallHead, Movie* movieHead);
};

#endif