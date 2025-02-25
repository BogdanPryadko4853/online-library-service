#ifndef AUTHORSERVICE_H
#define AUTHORSERVICE_H

#include "Service.h"
#include "../repositories/AuthorRepository.h"
#include "../enteties/Author.h"

class AuthorService : public Service<Author, AuthorRepository> {
public:
    explicit AuthorService(const std::shared_ptr<AuthorRepository>& repo)
            : Service(repo) {}

    void createAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
        auto author = std::make_shared<Author>(id, firstName, lastName, bio);
        create(author);
    }

    void updateAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
        update(id, [&](std::shared_ptr<Author> author) {
            author->setFirstName(firstName);
            author->setLastName(lastName);
            author->setBio(bio);
        });
    }
};

#endif