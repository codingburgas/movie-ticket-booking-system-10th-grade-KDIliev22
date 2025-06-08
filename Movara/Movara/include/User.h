#pragma once
#ifndef USER_H
#define USER_H
#include <string>
// Nadejdata umira posledna

class User {
public:
    static bool registerUser(const std::string& username, const std::string& password);
    static bool loginUser(const std::string& username, const std::string& password);
};

#endif // USER_H
