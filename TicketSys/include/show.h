#ifndef SHOW_H
#define SHOW_H

#include <string>

class Show {
private:
    std::string movieTitle;
    std::string time;

public:
    Show();
    Show(const std::string& movieTitle, const std::string& time);
    std::string getMovieTitle() const;
    std::string getTime() const;
};

#endif
