#include "../../include/services/UserService.h"
#include <algorithm>
#include <stdexcept>

UserService::UserService(const std::shared_ptr<UserRepository> &repo)
        : Service(repo) {}

void UserService::createUser(int id, const std::string &firstName, const std::string &lastName) {
    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name cannot be empty");
    }
    if (userExists(id)) {
        throw std::runtime_error("User with this ID already exists");
    }

    auto user = UserBuilder()
            .setId(id)
            .setFirstName(firstName)
            .setLastName(lastName)
            .build();
    create(user);
}

void UserService::updateUser(int id, const std::string &firstName, const std::string &lastName) {
    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name cannot be empty");
    }

    update(id, [&](std::shared_ptr<User> user) {
        user->setFirstName(firstName);
        user->setLastName(lastName);
    });
}

std::vector<std::shared_ptr<User>> UserService::findByName(const std::string &name) const {
    std::vector<std::shared_ptr<User>> result;
    auto allUsers = getAll();

    std::copy_if(allUsers.begin(), allUsers.end(), std::back_inserter(result),
                 [&name](const std::shared_ptr<User> &user) {
                     return user->getFirstName().find(name) != std::string::npos ||
                            user->getLastName().find(name) != std::string::npos;
                 });

    return result;
}

size_t UserService::countUsers() const {
    return getAll().size();
}

bool UserService::userExists(int id) const {
    return repository->findById(id) != nullptr;
}
