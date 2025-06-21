#include "cinema.h"

Cinema::Cinema() : name(""), city("") {}

Cinema::Cinema(const std::string& name, const std::string& city) : name(name), city(city) {}

std::string Cinema::getName() const {
       	return name;
}
std::string Cinema::getCity() const {
	return city;
}

