#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include "../enteties/Book.h"
#include "Repository.h"

class BookRepository : public Repository<Book> {
private:
    BookRepository() = default;

    BookRepository(const BookRepository &) = delete;

    BookRepository &operator=(const BookRepository &) = delete;

    static std::shared_ptr<BookRepository> instance;

public:
    // Метод для доступа к экземпляру
    static std::shared_ptr<BookRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<BookRepository>(new BookRepository());
        }
        return instance;
    }
};

#endif