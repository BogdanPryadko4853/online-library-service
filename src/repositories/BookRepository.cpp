#include "../../include/repositories/BookRepository.h"

std::shared_ptr<BookRepository> BookRepository::instance = nullptr;

void BookRepository::add(const std::shared_ptr<Book> &book) {
    Repository<Book>::add(book);
    notifyObservers("Book added: " + book->getTitle());
}

void BookRepository::remove(const std::shared_ptr<Book> &book) {
    Repository<Book>::remove(book);
    notifyObservers("Book removed: " + book->getTitle());
}

std::shared_ptr<Book> BookRepository::findById(int id) const {
    auto book = Repository<Book>::findById(id);
    notifyObservers(&"Founded book with id "[id]);
    return book;
}

std::vector<std::shared_ptr<Book>> BookRepository::getAll() const {
    auto books = Repository<Book>::getAll();
    notifyObservers("Was gotten all books");
    return books;
}