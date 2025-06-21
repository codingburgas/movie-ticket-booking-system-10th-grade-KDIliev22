#ifndef CINEMA_H
#define CINEMA_H

#include <string>

class Cinema {
private:
    std::string name;
    std::string city;

public:
    Cinema();
    Cinema(const std::string& name, const std::string& city);
    std::string getName() const;
    std::string getCity() const;
};

#endif

