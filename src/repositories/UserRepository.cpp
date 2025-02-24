#include "../../include/repositories/UserRepository.h"

void UserRepository::addUser(const std::shared_ptr<User>& user) {
    users.push_back(user);
}

void UserRepository::removeUser(const std::shared_ptr<User>& user) {
    users.erase(
            std::remove_if(
                    users.begin(),
                    users.end(),
                    [&user](const std::shared_ptr<User>& u) {
                        return u->getId() == user->getId();
                    }
            ),
            users.end()
    );
}

std::shared_ptr<User> UserRepository::findUserById(int id) const {
    for (const auto& user : users) {
        if (user->getId() == id) {
            return user;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<User>> UserRepository::getAllUsers() const {
    return users;
}