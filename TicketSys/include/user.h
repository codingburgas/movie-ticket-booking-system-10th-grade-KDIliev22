#ifndef USER_H
#define USER_H
#include <string>
class User {
private:
    std::string username;
    std::string password;
public:
    User(const std::string& username, const std::string& password);
    std::string getUsername() const;
    bool checkPassword(const std::string& input) const;
};
#endif
