#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "Service.h"
#include "../repositories/UserRepository.h"
#include "../enteties/User.h"
#include "../builder/UserBuilder.h"
#include <string>
#include <vector>
#include <memory>

class UserService : public Service<User, UserRepository> {
public:
    explicit UserService(const std::shared_ptr<UserRepository> &repo);

    void createUser(int id, const std::string &firstName, const std::string &lastName);

    void updateUser(int id, const std::string &firstName, const std::string &lastName);

    [[nodiscard]] std::vector<std::shared_ptr<User>> findByName(const std::string &name) const;

    [[nodiscard]] size_t countUsers() const;

    [[nodiscard]] bool userExists(int id) const;

};

#endif