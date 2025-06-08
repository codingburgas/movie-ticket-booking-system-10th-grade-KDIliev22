#include "Database.h"
#include <iostream>

    // Will have to implement sqlite management functions for creating or selecting user databases. Kill me.

Database::Database() { 
    sqlite3_open("db/tickets.db", &db);
}
Database::~Database() {
    sqlite3_close(db);
}
Database& Database::instance() {
    static Database inst;
    return inst;
}

bool Database::execute(const std::string& sql) {
    char* err = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &err) != SQLITE_OK) {
        sqlite3_free(err);
        return false;
    }
    return true;
}

bool Database::query(const std::string& sql, int (*callback)(void*, int, char**, char**), void* data) {
    char* err = nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, data, &err) != SQLITE_OK) {
        sqlite3_free(err);
        return false;
    }
    return true;
}