#include "../../include/enteties/Author.h"

Author::Author(int id, const std::string& firstName, const std::string& lastName, const std::string& bio)
        : id(id), firstName(firstName), lastName(lastName), bio(bio) {}

int Author::getId() const {
    return id;
}

std::string Author::getFirstName() const {
    return firstName;
}

std::string Author::getLastName() const {
    return lastName;
}

std::string Author::getBio() const {
    return bio;
}

void Author::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Author::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Author::setBio(const std::string& bio) {
    this->bio = bio;
}