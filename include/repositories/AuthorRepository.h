#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Author.h"

class AuthorRepository {
private:
    std::vector<std::shared_ptr<Author>> authors;

public:
    void addAuthor(const std::shared_ptr<Author>& author);
    void removeAuthor(const std::shared_ptr<Author>& author);
    std::shared_ptr<Author> findAuthorById(int id) const;
    std::vector<std::shared_ptr<Author>> getAllAuthors() const;
};

#endif