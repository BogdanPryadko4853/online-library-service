#ifndef USERBUILDER_H
#define USERBUILDER_H

#include "../enteties/User.h"

class UserBuilder {
private:
    int id;
    std::string firstName;
    std::string lastName;

public:
    UserBuilder& setId(int id) {
        this->id = id;
        return *this;
    }

    UserBuilder& setFirstName(const std::string& firstName) {
        this->firstName = firstName;
        return *this;
    }

    UserBuilder& setLastName(const std::string& lastName) {
        this->lastName = lastName;
        return *this;
    }

    std::shared_ptr<User> build() {
        return std::make_shared<User>(id, firstName, lastName);
    }
};

#endif