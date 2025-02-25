#include "../../include/services/UserService.h"

UserService::UserService(std::shared_ptr<UserRepository> repo)
        : userRepository(std::move(repo)) {}

void UserService::createUser(int id, const std::string& firstName,const std::string& lastName) {
    auto user = std::make_shared<User>(id, firstName, lastName);
    userRepository->add(user);
}

void UserService::deleteUser(int id) {
    auto user = userRepository->findById(id);
    if (user) {
        userRepository->remove(user);
    }
}

std::shared_ptr<User> UserService::getUserById(int id) const {
    return userRepository->findById(id);
}

std::vector<std::shared_ptr<User>> UserService::getAllUsers() const {
    return userRepository->getAll();
}