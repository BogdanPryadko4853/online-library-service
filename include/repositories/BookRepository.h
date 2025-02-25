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
};

#endif