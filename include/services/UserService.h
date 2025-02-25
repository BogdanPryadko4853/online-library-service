#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "Service.h"
#include "../repositories/UserRepository.h"
#include "../enteties/User.h"

class UserService : public Service<User, UserRepository> {
public:
    explicit UserService(const std::shared_ptr<UserRepository>& repo)
            : Service(repo) {}

    void createUser(int id, const std::string& firstName, const std::string& lastName) {
        auto user = std::make_shared<User>(id, firstName, lastName);
        create(user);
    }
};

#endif