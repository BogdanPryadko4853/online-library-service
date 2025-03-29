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
    AuthorBuilder &setId(int id);

    AuthorBuilder &setFirstName(const std::string &firstName);

    AuthorBuilder &setLastName(const std::string &lastName);

    AuthorBuilder &setBio(const std::string &bio);

    std::shared_ptr<Author> build();
};

#endif