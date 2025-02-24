#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties//User.h"

class UserRepository {
private:
    std::vector<std::shared_ptr<User>> users;

public:
    void addUser(const std::shared_ptr<User>& user);
    void removeUser(const std::shared_ptr<User>& user);
    std::shared_ptr<User> findUserById(int id) const;
    std::vector<std::shared_ptr<User>> getAllUsers() const;
};

#endif