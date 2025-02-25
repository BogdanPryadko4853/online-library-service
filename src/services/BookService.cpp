#include "../../include/services/BookService.h"

BookService::BookService(const std::shared_ptr<BookRepository>& repo)
        : bookRepository(repo) {}

void BookService::createBook(int id, const std::string& title, const std::string& description, int authorId) {
    auto book = std::make_shared<Book>(id, title, description, authorId);
    bookRepository->add(book);
}

std::shared_ptr<Book> BookService::getBookById(int id) const {
    return bookRepository->findById(id);
}

std::vector<std::shared_ptr<Book>> BookService::getAllBooks() const {
    return bookRepository->getAll();
}

void BookService::updateBook(int id, const std::string& title, const std::string& description) {
    auto book = bookRepository->findById(id);
    if (book) {
        book->setTitle(title);
        book->setDescription(description);
    }
}

void BookService::deleteBook(int id) {
    auto book = bookRepository->findById(id);
    if (book) {
        bookRepository->remove(book);
    }
}