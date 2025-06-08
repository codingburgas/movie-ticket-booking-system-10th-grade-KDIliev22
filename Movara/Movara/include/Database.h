#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    sqlite3* getDb() const { return db; }
    static Database& instance();
    bool execute(const std::string& sql);
    bool query(const std::string& sql, int (*callback)(void*, int, char**, char**), void* data);
private:
    sqlite3* db;
    Database();
    ~Database();
};

#endif // DATABASE_H
