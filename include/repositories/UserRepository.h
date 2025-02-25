#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties//User.h"
#include "Repository.h"

class UserRepository : Repository<User> {
private:
    std::vector<std::shared_ptr<User>> users;
};

#endif