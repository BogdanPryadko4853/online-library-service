#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Author.h"
#include "Repository.h"

class AuthorRepository : public Repository<Author> {
private:
    std::vector<std::shared_ptr<Author>> authors;
public:
    using Repository<Author>::add;
    using Repository<Author>::remove;
    using Repository<Author>::findById;
    using Repository<Author>::getAll;
};

#endif