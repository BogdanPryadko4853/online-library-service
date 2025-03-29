#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "../enteties/Author.h"
#include "Repository.h"
#include "../observer/Observable.h"
#include <vector>
#include <memory>

class AuthorRepository : public Repository<Author>, public Observable {
private:
    AuthorRepository() = default;

    AuthorRepository(const AuthorRepository &) = delete;

    AuthorRepository &operator=(const AuthorRepository &) = delete;

    static std::shared_ptr<AuthorRepository> instance;

public:
    static std::shared_ptr<AuthorRepository> getInstance();

    void add(const std::shared_ptr<Author> &author) override;

    void remove(const std::shared_ptr<Author> &author) override;

    [[nodiscard]] std::shared_ptr<Author> findById(int id) const;

    [[nodiscard]] std::vector<std::shared_ptr<Author>> findByName(const std::string &name) const;

    [[nodiscard]] bool exists(int id) const;

    [[nodiscard]] bool nameExists(const std::string &firstName, const std::string &lastName) const;

};

#endif