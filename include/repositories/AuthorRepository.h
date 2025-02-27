#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "../enteties/Author.h"
#include "Repository.h"
#include "../observer/Observable.h"

class AuthorRepository : public Repository<Author>, public Observable {
private:
    AuthorRepository() = default;
    AuthorRepository(const AuthorRepository&) = delete;
    AuthorRepository& operator=(const AuthorRepository&) = delete;

    static std::shared_ptr<AuthorRepository> instance;

public:
    static std::shared_ptr<AuthorRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<AuthorRepository>(new AuthorRepository());
        }
        return instance;
    }

    void add(const std::shared_ptr<Author>& author) override;
    void remove(const std::shared_ptr<Author>& author) override;
};

#endif