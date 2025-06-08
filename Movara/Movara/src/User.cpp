#include "User.h"
#include "Database.h"
#include <sqlite3.h>
#include <string>
#include "Crypto_psk.h"
#include <iostream>
static int loginCallback(void* userData, int argc, char** argv, char**) {
    if (argc > 0 && argv[0]) {
        *static_cast<std::string*>(userData) = argv[0];
    }
    return 0;
}
bool User::loginUser(const std::string& username, const std::string& password)
{
    sqlite3* db = Database::instance().getDb();
    if (!db) {
        std::cerr << "Database not initialized!\n"; //keine Scheiße
        return false;
    }
    std::string sql =
        "SELECT password_hash FROM users WHERE username = '" + username + "';";

    std::string storedHash;
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), loginCallback, &storedHash, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQLite error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }
    std::string candidateHash = Crypto::hashSHA512(password);
    if (candidateHash == storedHash) {
        return true;
    }
    else {
        std::cerr << "Invalid credentials\n";
        return false;
    }
}
bool User::registerUser(const std::string& username, const std::string& password) {
    return true;
}
