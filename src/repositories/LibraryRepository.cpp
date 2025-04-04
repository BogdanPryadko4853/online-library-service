#include "../../include/repositories/LibraryRepository.h"
#include "../../include/config/DatabaseManager.h"
#include <algorithm>

std::shared_ptr<LibraryRepository> LibraryRepository::instance = nullptr;

std::shared_ptr<LibraryRepository> LibraryRepository::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<LibraryRepository>(new LibraryRepository());
    }
    return instance;
}

void LibraryRepository::add(const std::shared_ptr<Library> &library) {
    if (!library) {
        throw std::invalid_argument("Cannot add null library");
    }
    if (exists(library->getId())) {
        throw std::runtime_error("Library with this ID already exists");
    }
    if (nameExists(library->getName())) {
        throw std::runtime_error("Library with this name already exists");
    }

    auto& db = DatabaseManager::getInstance();
    std::string sql = "INSERT INTO libraries (name, description, address) VALUES (?, ?, ?)";

    if (!db.executeWithParams(sql, {
            library->getName(),
            library->getDescription(),
            library->getAddress()
    })) {
        throw std::runtime_error("Failed to add library to database");
    }

    notifyObservers("Added library: ID=" + std::to_string(library->getId()) +
                    ", Name=" + library->getName());
}

void LibraryRepository::remove(const std::shared_ptr<Library> &library) {
    if (!library || !exists(library->getId())) {
        throw std::runtime_error("Library not found");
    }

    auto& db = DatabaseManager::getInstance();
    std::string sql = "DELETE FROM libraries WHERE id = ?";

    if (!db.executeWithParams(sql, {std::to_string(library->getId())})) {
        throw std::runtime_error("Failed to remove library from database");
    }

    notifyObservers("Removed library: ID=" + std::to_string(library->getId()));
}

std::shared_ptr<Library> LibraryRepository::findById(int id) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT * FROM libraries WHERE id = " + std::to_string(id));

    if (result.empty()) {
        return nullptr;
    }

    auto row = result[0];
    auto library = std::make_shared<Library>(
            std::stoi(row[0]),  // id
            row[1],             // name
            row[2],             // description
            row[3]              // address
    );

    notifyObservers("Found library with id " + std::to_string(id));
    return library;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::getAll() const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT * FROM libraries");

    std::vector<std::shared_ptr<Library>> libraries;
    for (const auto& row : result) {
        libraries.push_back(std::make_shared<Library>(
                std::stoi(row[0]), row[1], row[2], row[3]
        ));
    }

    notifyObservers("Retrieved all libraries (count: " + std::to_string(libraries.size()) + ")");
    return libraries;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::findByName(const std::string &name) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT * FROM libraries WHERE name LIKE '%" + name + "%'"
    );

    std::vector<std::shared_ptr<Library>> libraries;
    for (const auto& row : result) {
        libraries.push_back(std::make_shared<Library>(
                std::stoi(row[0]), row[1], row[2], row[3]
        ));
    }

    notifyObservers("Search by name: '" + name + "' found " + std::to_string(libraries.size()) + " libraries");
    return libraries;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::findByAddress(const std::string &address) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT * FROM libraries WHERE address LIKE '%" + address + "%'"
    );

    std::vector<std::shared_ptr<Library>> libraries;
    for (const auto& row : result) {
        libraries.push_back(std::make_shared<Library>(
                std::stoi(row[0]), row[1], row[2], row[3]
        ));
    }

    notifyObservers("Search by address: '" + address + "' found " + std::to_string(libraries.size()) + " libraries");
    return libraries;
}

bool LibraryRepository::exists(int id) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT 1 FROM libraries WHERE id = " + std::to_string(id));
    return !result.empty();
}

bool LibraryRepository::nameExists(const std::string &name) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT 1 FROM libraries WHERE name = '" + name + "'"
    );
    return !result.empty();
}
