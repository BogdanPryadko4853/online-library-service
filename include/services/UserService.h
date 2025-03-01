#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <optional>
#include "Service.h"
#include "../repositories/UserRepository.h"
#include "../enteties/User.h"
#include "../builder/UserBuilder.h"

class UserService : public Service<User, UserRepository> {
public:
    explicit UserService(const std::shared_ptr<UserRepository>& repo)
            : Service(repo) {}

    void createUser(int id, const std::string& firstName, const std::string& lastName) {
        auto user = UserBuilder()
                .setId(1)
                .setFirstName("John")
                .setLastName("Doe")
                .build();
        create(user);
    }
};

#endif