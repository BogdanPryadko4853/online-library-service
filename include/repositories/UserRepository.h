#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "../enteties/User.h"
#include "Repository.h"
#include "../observer/Observable.h"

class UserRepository : public Repository<User>, public Observable {
private:
    UserRepository() = default;

    UserRepository(const UserRepository &) = delete;

    UserRepository &operator=(const UserRepository &) = delete;

    static std::shared_ptr<UserRepository> instance;

public:
    static std::shared_ptr<UserRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<UserRepository>(new UserRepository());
        }
        return instance;
    }

    std::shared_ptr<User> findById(int id) const override;

    std::vector<std::shared_ptr<User>> getAll() const override;
};

#endif