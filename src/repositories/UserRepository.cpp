#include "../../include/repositories/UserRepository.h"

std::shared_ptr<UserRepository> UserRepository::instance = nullptr;

std::shared_ptr<User> UserRepository::findById(int id) const {
   auto user =  Repository::findById(id);
    notifyObservers(&"Getting user with id - "[id]);
    return user;
}

std::vector<std::shared_ptr<User>> UserRepository::getAll() const {
    auto users = Repository::getAll();
    notifyObservers("Getting all users");
    return users;
}


