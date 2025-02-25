#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Book.h"
#include "Repository.h"

class BookRepository: public Repository<Book> {
private:
    std::vector<std::shared_ptr<Book>> books;
public:
    using Repository<Book>::add;
    using Repository<Book>::remove;
    using Repository<Book>::findById;
    using Repository<Book>::getAll;
};

#endif