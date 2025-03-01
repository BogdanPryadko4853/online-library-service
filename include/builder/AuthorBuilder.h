#ifndef AUTHORBUILDER_H
#define AUTHORBUILDER_H

#include <memory>
#include "../enteties/Author.h"

class AuthorBuilder {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string bio;

public:
    AuthorBuilder& setId(int id) {
        this->id = id;
        return *this;
    }

    AuthorBuilder& setFirstName(const std::string& firstName) {
        this->firstName = firstName;
        return *this;
    }

    AuthorBuilder& setLastName(const std::string& lastName) {
        this->lastName = lastName;
        return *this;
    }

    AuthorBuilder& setBio(const std::string& bio) {
        this->bio = bio;
        return *this;
    }

    std::shared_ptr<Author> build() {
        return std::make_shared<Author>(id, firstName, lastName, bio);
    }
};

#endif