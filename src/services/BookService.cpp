#include "../../include/services/BookService.h"

BookService::BookService(const std::shared_ptr<BookRepository>& repo)
        : bookRepository(repo) {}

void BookService::createBook(int id, const std::string& title, const std::string& description, int authorId) {
    auto book = std::make_shared<Book>(id, title, description, authorId);
    bookRepository->addBook(book);
}

std::shared_ptr<Book> BookService::getBookById(int id) const {
    return bookRepository->findBookById(id);
}

std::vector<std::shared_ptr<Book>> BookService::getAllBooks() const {
    return bookRepository->getAllBooks();
}

void BookService::updateBook(int id, const std::string& title, const std::string& description) {
    auto book = bookRepository->findBookById(id);
    if (book) {
        book->setTitle(title);
        book->setDescription(description);
    }
}

void BookService::deleteBook(int id) {
    auto book = bookRepository->findBookById(id);
    if (book) {
        bookRepository->removeBook(book);
    }
}