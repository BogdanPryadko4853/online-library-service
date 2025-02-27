#include "../../include/repositories/AuthorRepository.h"

std::shared_ptr<AuthorRepository> AuthorRepository::instance = nullptr;

void AuthorRepository::add(const std::shared_ptr<Author> &author) {
    Repository<Author>::add(author);
    notifyObservers("Author added: " + author->getFirstName() + " " + author->getLastName());
}

void AuthorRepository::remove(const std::shared_ptr<Author> &author) {
    Repository<Author>::remove(author);
    notifyObservers("Author removed: " + author->getFirstName() + " " + author->getLastName());
}