#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Book.h"

class BookRepository {
private:
    std::vector<std::shared_ptr<Book>> books;

public:
    void addBook(const std::shared_ptr<Book>& book);
    void removeBook(const std::shared_ptr<Book>& book);
    std::shared_ptr<Book> findBookById(int id) const;
    std::vector<std::shared_ptr<Book>> getAllBooks() const;
};

#endif