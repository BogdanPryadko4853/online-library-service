#include "../../include/services/AuthorService.h"

void
AuthorService::createAuthor(int id, const std::string &firstName, const std::string &lastName, const std::string &bio) {
    if (repository->findById(id)) {
        throw std::runtime_error("Author with this ID already exists");
    }

    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name cannot be empty");
    }

    auto author = AuthorBuilder()
            .setId(id)  // Используем переданный ID
            .setFirstName(firstName)
            .setLastName(lastName)
            .setBio(bio)
            .build();

    create(author);
}

void
AuthorService::updateAuthor(int id, const std::string &firstName, const std::string &lastName, const std::string &bio) {
    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name cannot be empty");
    }

    update(id, [&](std::shared_ptr<Author> author) {
        author->setFirstName(firstName);
        author->setLastName(lastName);
        author->setBio(bio);
    });
}

std::vector<std::shared_ptr<Author>> AuthorService::findAuthorsByName(const std::string &name) const {
    std::vector<std::shared_ptr<Author>> result;
    auto allAuthors = getAll();

    std::copy_if(allAuthors.begin(), allAuthors.end(), std::back_inserter(result),
                 [&name](const std::shared_ptr<Author> &author) {
                     return author->getFirstName().find(name) != std::string::npos ||
                            author->getLastName().find(name) != std::string::npos;
                 });

    return result;
}

bool AuthorService::authorExists(int id) const {
    return repository->findById(id) != nullptr;
}