#include "../../include/services/BookService.h"
#include <algorithm>

void BookService::createBook(int id, const std::string &title, const std::string &description, int authorId) {
    if (title.empty()) {
        throw std::invalid_argument("Title cannot be empty");
    }
    if (authorId <= 0) {
        throw std::invalid_argument("Invalid author ID");
    }
    if (bookExists(id)) {
        throw std::runtime_error("Book with this ID already exists");
    }

    auto book = BookBuilder()
            .setId(id)
            .setTitle(title)
            .setDescription(description)
            .setAuthorId(authorId)
            .build();
    create(book);
}

void BookService::updateBook(int id, const std::string &title, const std::string &description) {
    if (title.empty()) {
        throw std::invalid_argument("Title cannot be empty");
    }

    update(id, [&](std::shared_ptr<Book> book) {
        book->setTitle(title);
        book->setDescription(description);
    });
}

bool BookService::bookExists(int id) const {
    return repository->findById(id) != nullptr;
}

std::vector<std::shared_ptr<Book>> BookService::findByTitle(const std::string &title) const {
    std::vector<std::shared_ptr<Book>> result;
    auto allBooks = getAll();

    std::copy_if(allBooks.begin(), allBooks.end(), std::back_inserter(result),
                 [&title](const std::shared_ptr<Book> &book) {
                     return book->getTitle().find(title) != std::string::npos;
                 });

    return result;
}

std::vector<std::shared_ptr<Book>> BookService::findByAuthor(int authorId) const {
    std::vector<std::shared_ptr<Book>> result;
    auto allBooks = getAll();

    std::copy_if(allBooks.begin(), allBooks.end(), std::back_inserter(result),
                 [authorId](const std::shared_ptr<Book> &book) {
                     return book->getAuthorId() == authorId;
                 });

    return result;
}

size_t BookService::countBooks() const {
    return getAll().size();
}

size_t BookService::countBooksByAuthor(int authorId) const {
    return findByAuthor(authorId).size();
}