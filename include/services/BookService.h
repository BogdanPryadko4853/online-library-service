#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include "Service.h"
#include "../repositories/BookRepository.h"
#include "../enteties/Book.h"

class BookService : public Service<Book, BookRepository> {
public:
    explicit BookService(const std::shared_ptr<BookRepository>& repo)
            : Service(repo) {}

    void createBook(int id, const std::string& title, const std::string& description, int authorId) {
        auto book = std::make_shared<Book>(id, title, description, authorId);
        create(book);
    }

    void updateBook(int id, const std::string& title, const std::string& description) {
        update(id, [&](std::shared_ptr<Book> book) {
            book->setTitle(title);
            book->setDescription(description);
        });
    }
};

#endif