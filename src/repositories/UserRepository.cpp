#include "../../include/repositories/UserRepository.h"
#include "../../include/config/DatabaseManager.h"

std::shared_ptr<UserRepository> UserRepository::instance = nullptr;


std::shared_ptr<User> UserRepository::findById(int id) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT id, first_name, last_name, password FROM users WHERE id = " + std::to_string(id)
    );

    if (result.empty()) {
        return nullptr;
    }

    auto row = result[0];
    auto user = std::make_shared<User>(
            std::stoi(row[0]),  // id
            row[1],             // first_name
            row[2]              // last_name
    );

    user->setPassword(row[3]);
    auto loans = db.query(
            "SELECT id FROM loans WHERE user_id = " + std::to_string(id)
    );

    notifyObservers("Getting user with id - " + std::to_string(id));
    return user;
}

void UserRepository::add(const std::shared_ptr<User> &user) {
    auto &db = DatabaseManager::getInstance();
    db.execute(
            "INSERT INTO users (id, first_name, last_name, password) VALUES (" +
            std::to_string(user->getId()) + ", '" +
            user->getFirstName() + "', '" +
            user->getLastName() + "', '" +
            user->getPassword() + "')"
    );
    notifyObservers("Added new user with id - " + std::to_string(user->getId()));
}

std::vector<std::shared_ptr<User>> UserRepository::getAll() const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query("SELECT id, first_name, last_name FROM users");

    std::vector<std::shared_ptr<User>> users;
    for (const auto &row: result) {
        users.push_back(std::make_shared<User>(
                std::stoi(row[0]),
                row[1],
                row[2]
        ));
    }

    notifyObservers("Getting all users");
    return users;
}


