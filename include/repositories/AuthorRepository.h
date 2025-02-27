#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "../enteties/Author.h"
#include "Repository.h"

class AuthorRepository : public Repository<Author> {
private:
    AuthorRepository() = default;

    AuthorRepository(const AuthorRepository &) = delete;

    AuthorRepository &operator=(const AuthorRepository &) = delete;

    static std::shared_ptr<AuthorRepository> instance;

public:
    static std::shared_ptr<AuthorRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<AuthorRepository>(new AuthorRepository());
        }
        return instance;
    }
};

#endif