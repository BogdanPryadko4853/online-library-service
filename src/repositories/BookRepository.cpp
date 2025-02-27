#include "../../include/repositories/BookRepository.h"

std::shared_ptr<BookRepository> BookRepository::instance = nullptr;

void BookRepository::add(const std::shared_ptr<Book>& book) {
    Repository<Book>::add(book);
    notifyObservers("Book added: " + book->getTitle());
}