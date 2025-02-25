#include "../../include/services/AuthorService.h"

AuthorService::AuthorService(const std::shared_ptr<AuthorRepository>& repo)
        : authorRepository(repo) {}

void AuthorService::createAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
    auto author = std::make_shared<Author>(id, firstName, lastName, bio);
    authorRepository->add(author);
}

std::shared_ptr<Author> AuthorService::getAuthorById(int id) const {
    return authorRepository->findById(id);
}

std::vector<std::shared_ptr<Author>> AuthorService::getAllAuthors() const {
    return authorRepository->getAll();
}

void AuthorService::updateAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio) {
    auto author = authorRepository->findById(id);
    if (author) {
        author->setFirstName(firstName);
        author->setLastName(lastName);
        author->setBio(bio);
    }
}

void AuthorService::deleteAuthor(int id) {
    auto author = authorRepository->findById(id);
    if (author) {
        authorRepository->remove(author);
    }
}