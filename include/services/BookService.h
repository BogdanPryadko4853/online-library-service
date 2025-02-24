#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include <memory>
#include <vector>
#include "../repositories/BookRepository.h"
#include "../enteties//Book.h"

class BookService {
private:
    std::shared_ptr<BookRepository> bookRepository;

public:
    explicit BookService(const std::shared_ptr<BookRepository>& repo);
    void createBook(int id, const std::string& title, const std::string& description, int authorId);
    std::shared_ptr<Book> getBookById(int id) const;
    std::vector<std::shared_ptr<Book>> getAllBooks() const;
    void updateBook(int id, const std::string& title, const std::string& description);
    void deleteBook(int id);
};

#endif