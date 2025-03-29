#include "../../include/services/BookService.h"

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