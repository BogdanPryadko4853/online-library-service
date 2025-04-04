#include "../../include/config/DatabaseManager.h"
#include <stdexcept>

std::unique_ptr<DatabaseManager> DatabaseManager::instance;

DatabaseManager::DatabaseManager() {
    if (sqlite3_open("library.db", &db) != SQLITE_OK) {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    execute(
            "CREATE TABLE IF NOT EXISTS books ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "title TEXT NOT NULL, "
            "description TEXT, "
            "author_id INTEGER NOT NULL, "
            "FOREIGN KEY(author_id) REFERENCES authors(id), "
            "UNIQUE(title)"
            ");"
    );

    execute(
            "CREATE TABLE IF NOT EXISTS libraries ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "description TEXT, "
            "address TEXT NOT NULL, "
            "UNIQUE(name)"
            ");"
    );

    execute(
            "CREATE TABLE IF NOT EXISTS library_books ("
            "library_id INTEGER NOT NULL, "
            "book_id INTEGER NOT NULL, "
            "PRIMARY KEY (library_id, book_id), "
            "FOREIGN KEY(library_id) REFERENCES libraries(id) ON DELETE CASCADE, "
            "FOREIGN KEY(book_id) REFERENCES books(id) ON DELETE CASCADE"
            ");"
    );

    execute(
            "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "first_name TEXT NOT NULL, "
            "last_name TEXT NOT NULL, "
            "password TEXT NOT NULL"
            ");"
    );

    execute(
            "CREATE TABLE IF NOT EXISTS loans ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "book_id INTEGER NOT NULL, "
            "user_id INTEGER NOT NULL, "
            "loan_date TEXT NOT NULL, "
            "return_date TEXT, "
            "FOREIGN KEY(book_id) REFERENCES books(id), "
            "FOREIGN KEY(user_id) REFERENCES users(id)"
            ");"
    );
}

DatabaseManager::~DatabaseManager() {
    if (db) {
        sqlite3_close(db);
    }
}

DatabaseManager& DatabaseManager::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<DatabaseManager>(new DatabaseManager());
    }
    return *instance;
}

bool DatabaseManager::execute(const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool DatabaseManager::executeWithParams(const std::string& sql, const std::vector<std::string>& params) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    for (int i = 0; i < params.size(); ++i) {
        sqlite3_bind_text(stmt, i+1, params[i].c_str(), -1, SQLITE_TRANSIENT);
    }

    bool result = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return result;
}

std::vector<std::vector<std::string>> DatabaseManager::query(const std::string& sql) {
    std::vector<std::vector<std::string>> result;
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return result;
    }

    int cols = sqlite3_column_count(stmt);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < cols; ++i) {
            row.push_back(
                    reinterpret_cast<const char*>(sqlite3_column_text(stmt, i))
            );
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    return result;
}