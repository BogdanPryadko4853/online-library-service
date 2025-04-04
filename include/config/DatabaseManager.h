#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <sqlite3.h>
#include <memory>
#include <string>
#include <vector>

class DatabaseManager {
public:

    ~DatabaseManager();

    static DatabaseManager& getInstance();

    bool execute(const std::string& sql);
    bool executeWithParams(const std::string& sql, const std::vector<std::string>& params);
    std::vector<std::vector<std::string>> query(const std::string& sql);

    // Удаляем копирование и присваивание
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

private:
    DatabaseManager();

    sqlite3* db;
    static std::unique_ptr<DatabaseManager> instance;
};

#endif