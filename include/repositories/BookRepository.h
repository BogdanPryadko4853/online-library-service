#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include "../enteties/Book.h"
#include "Repository.h"
#include "../observer/Observable.h"
#include <vector>
#include <memory>

class BookRepository : public Repository<Book>, public Observable {
private:
    BookRepository() = default;

    BookRepository(const BookRepository &) = delete;

    BookRepository &operator=(const BookRepository &) = delete;

    static std::shared_ptr<BookRepository> instance;

public:
    static std::shared_ptr<BookRepository> getInstance();

    void add(const std::shared_ptr<Book> &book) override;

    void remove(const std::shared_ptr<Book> &book) override;

    std::shared_ptr<Book> findById(int id) const override;

    std::vector<std::shared_ptr<Book>> getAll() const override;

    std::vector<std::shared_ptr<Book>> findByTitle(const std::string &title) const;

    std::vector<std::shared_ptr<Book>> findByAuthor(int authorId) const;

    std::vector<std::shared_ptr<Book>> findByLibrary(int libraryId) const;

    size_t countBooks() const;

    size_t countBooksByAuthor(int authorId) const;

    size_t countBooksInLibrary(int libraryId) const;

    bool exists(int id) const;

    bool titleExists(const std::string &title) const;

};

#endif