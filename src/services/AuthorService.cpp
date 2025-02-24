#include "../../include/services/AuthorService.h"

AuthorService::AuthorService(const std::shared_ptr<AuthorRepository>& repo)
        : authorRepository(repo) {}

void AuthorService::createAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
    auto author = std::make_shared<Author>(id, firstName, lastName, bio);
    authorRepository->addAuthor(author);
}

std::shared_ptr<Author> AuthorService::getAuthorById(int id) const {
    return authorRepository->findAuthorById(id);
}

std::vector<std::shared_ptr<Author>> AuthorService::getAllAuthors() const {
    return authorRepository->getAllAuthors();
}

void AuthorService::updateAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
    auto author = authorRepository->findAuthorById(id);
    if (author) {
        author->setFirstName(firstName);
        author->setLastName(lastName);
        author->setBio(bio);
    }
}

void AuthorService::deleteAuthor(int id) {
    auto author = authorRepository->findAuthorById(id);
    if (author) {
        authorRepository->removeAuthor(author);
    }
}