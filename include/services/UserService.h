#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <memory>
#include "../repositories/UserRepository.h"

class UserService {
private:
    std::shared_ptr<UserRepository> userRepository;

public:
    explicit UserService(std::shared_ptr<UserRepository> repo);
    void createUser(int id, const std::string& firstName,const std::string& lastName);
    void deleteUser(int id);
    std::shared_ptr<User> getUserById(int id) const;
    std::vector<std::shared_ptr<User>> getAllUsers() const;
};

#endif