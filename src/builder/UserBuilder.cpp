#include "../../include/builder/UserBuilder.h"

UserBuilder &UserBuilder::setId(int id) {
    this->id = id;
    return *this;
}

UserBuilder &UserBuilder::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
    return *this;
}

UserBuilder &UserBuilder::setLastName(const std::string &lastName) {
    this->lastName = lastName;
    return *this;
}

std::shared_ptr<User> UserBuilder::build() {
    return std::make_shared<User>(id, firstName, lastName);
}
