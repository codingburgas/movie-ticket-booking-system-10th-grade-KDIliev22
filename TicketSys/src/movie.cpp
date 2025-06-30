#include "movie.h"

Movie::Movie(std::string t, std::string l, std::string g, std::string r) : title(t), language(l), genre(g), releaseDate(r), next(nullptr) {}