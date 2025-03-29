#include "../../include/builder/AuthorBuilder.h"

AuthorBuilder &AuthorBuilder::setId(int id) {
    this->id = id;
    return *this;
}

AuthorBuilder &AuthorBuilder::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
    return *this;
}

AuthorBuilder &AuthorBuilder::setLastName(const std::string &lastName) {
    this->lastName = lastName;
    return *this;
}

AuthorBuilder &AuthorBuilder::setBio(const std::string &bio) {
    this->bio = bio;
    return *this;
}

std::shared_ptr<Author> AuthorBuilder::build() {
    return std::make_shared<Author>(id, firstName, lastName, bio);
}
