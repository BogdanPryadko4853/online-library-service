#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include "Service.h"
#include "../repositories/BookRepository.h"
#include "../enteties/Book.h"
#include "../builder/BookBuilder.h"
#include <stdexcept>

class BookService : public Service<Book, BookRepository> {
public:
    explicit BookService(const std::shared_ptr<BookRepository> &repo)
            : Service(repo) {}

    /**
     * Creates a new book with the given parameters
     * @throws std::invalid_argument if validation fails
     */
    void createBook(int id, const std::string &title, const std::string &description, int authorId);

    /**
     * Updates book information
     * @throws std::invalid_argument if validation fails
     */
    void updateBook(int id, const std::string &title, const std::string &description);

    /**
     * Checks if book exists
     */
    [[nodiscard]] bool bookExists(int id) const;


    [[nodiscard]] std::vector<std::shared_ptr<Book>> findByTitle(const std::string &title) const;

    [[nodiscard]] std::vector<std::shared_ptr<Book>> findByAuthor(int authorId) const;

    [[nodiscard]] size_t countBooks() const;

    [[nodiscard]] size_t countBooksByAuthor(int authorId) const;
};

#endif