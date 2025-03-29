#ifndef USERBUILDER_H
#define USERBUILDER_H

#include "../enteties/User.h"

class UserBuilder {
private:
    int id;
    std::string firstName;
    std::string lastName;

public:
    UserBuilder &setId(int id);

    UserBuilder &setFirstName(const std::string &firstName);

    UserBuilder &setLastName(const std::string &lastName);

    std::shared_ptr<User> build();
};

#endif