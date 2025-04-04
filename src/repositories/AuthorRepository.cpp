#include "../../include/repositories/AuthorRepository.h"
#include "../../include/config/DatabaseManager.h"
#include <algorithm>

std::shared_ptr<AuthorRepository> AuthorRepository::instance = nullptr;

std::shared_ptr<AuthorRepository> AuthorRepository::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<AuthorRepository>(new AuthorRepository());
    }
    return instance;
}

void AuthorRepository::add(const std::shared_ptr<Author> &author) {
    if (!author) {
        throw std::invalid_argument("Cannot add null author");
    }
    if (exists(author->getId())) {
        throw std::runtime_error("Author with this ID already exists");
    }
    if (nameExists(author->getFirstName(), author->getLastName())) {
        throw std::runtime_error("Author with this name already exists");
    }

    auto &db = DatabaseManager::getInstance();
    std::string sql = "INSERT INTO authors (first_name, last_name, biography) VALUES (?, ?, ?)";

    if (!db.executeWithParams(sql, {
            author->getFirstName(),
            author->getLastName(),
            author->getBio()
    })) {
        throw std::runtime_error("Failed to add author to database");
    }

    notifyObservers("Added author: " + author->getFirstName() + " " + author->getLastName());
}

void AuthorRepository::remove(const std::shared_ptr<Author> &author) {
    if (!author || !exists(author->getId())) {
        throw std::runtime_error("Author not found");
    }

    auto &db = DatabaseManager::getInstance();
    std::string sql = "DELETE FROM authors WHERE id = ?";

    if (!db.executeWithParams(sql, {std::to_string(author->getId())})) {
        throw std::runtime_error("Failed to remove author from database");
    }

    notifyObservers("Removed author: ID=" + std::to_string(author->getId()));
}

std::shared_ptr<Author> AuthorRepository::findById(int id) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query("SELECT * FROM authors WHERE id = " + std::to_string(id));

    if (result.empty()) {
        return nullptr;
    }

    auto row = result[0];
    return std::make_shared<Author>(
            std::stoi(row[0]),
            row[1],
            row[2],
            row[3]
    );
}

std::vector<std::shared_ptr<Author>> AuthorRepository::findByName(const std::string &name) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT * FROM authors WHERE first_name LIKE '%" + name + "%' OR last_name LIKE '%" + name + "%'"
    );

    std::vector<std::shared_ptr<Author>> authors;
    for (const auto &row: result) {
        authors.push_back(std::make_shared<Author>(
                std::stoi(row[0]),
                row[1],
                row[2],
                row[3]
        ));
    }

    return authors;
}

bool AuthorRepository::exists(int id) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query("SELECT 1 FROM authors WHERE id = " + std::to_string(id));
    return !result.empty();
}

bool AuthorRepository::nameExists(const std::string &firstName, const std::string &lastName) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT 1 FROM authors WHERE first_name = '" + firstName +
            "' AND last_name = '" + lastName + "'"
    );
    return !result.empty();
}