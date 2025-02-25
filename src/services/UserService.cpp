#include "../../include/services/UserService.h"

UserService::UserService(std::shared_ptr<UserRepository> repo)
        : userRepository(std::move(repo)) {}

void UserService::createUser(int id, const std::string& firstName,const std::string& lastName) {
    auto user = std::make_shared<User>(id, firstName, lastName);
    userRepository->addUser(user);
}

void UserService::deleteUser(int id) {
    auto user = userRepository->findUserById(id);
    if (user) {
        userRepository->removeUser(user);
    }
}

std::shared_ptr<User> UserService::getUserById(int id) const {
    return userRepository->findUserById(id);
}

std::vector<std::shared_ptr<User>> UserService::getAllUsers() const {
    return userRepository->getAllUsers();
}