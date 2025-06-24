#include "user.h"
User::User(const std::string& username, const std::string& password) : username(username), password(password) {}
std::string User::getUsername() const {
    return username;
}
bool User::checkPassword(const std::string& input) const {
    return input == password;
}
