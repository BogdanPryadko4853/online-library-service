#include "../../include/repositories/AuthorRepository.h"
#include <algorithm>

std::shared_ptr<AuthorRepository> AuthorRepository::instance = nullptr;

std::shared_ptr<AuthorRepository> AuthorRepository::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<AuthorRepository>(new AuthorRepository());
    }
    return instance;
}

void AuthorRepository::add(const std::shared_ptr<Author> &author) {
    if (!author) {
        throw std::invalid_argument("Cannot add null author");
    }
    if (exists(author->getId())) {
        throw std::runtime_error("Author with this ID already exists");
    }
    if (nameExists(author->getFirstName(), author->getLastName())) {
        throw std::runtime_error("Author with this name already exists");
    }

    Repository<Author>::add(author);
    notifyObservers("Added author: ID=" + std::to_string(author->getId()) +
                    ", Name=" + author->getFirstName() + " " + author->getLastName());
}

void AuthorRepository::remove(const std::shared_ptr<Author> &author) {
    if (!author || !exists(author->getId())) {
        throw std::runtime_error("Author not found");
    }

    Repository<Author>::remove(author);
    notifyObservers("Removed author: ID=" + std::to_string(author->getId()));
}

std::shared_ptr<Author> AuthorRepository::findById(int id) const {
    auto all = getAll();
    auto it = std::find_if(all.begin(), all.end(),
                           [id](const auto &author) { return author->getId() == id; });
    return it != all.end() ? *it : nullptr;
}

std::vector<std::shared_ptr<Author>> AuthorRepository::findByName(const std::string &name) const {
    std::vector<std::shared_ptr<Author>> result;
    auto all = getAll();

    std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                 [&name](const auto &author) {
                     return author->getFirstName().find(name) != std::string::npos ||
                            author->getLastName().find(name) != std::string::npos;
                 });

    return result;
}

bool AuthorRepository::exists(int id) const {
    return findById(id) != nullptr;
}

bool AuthorRepository::nameExists(const std::string &firstName, const std::string &lastName) const {
    auto all = getAll();
    return std::any_of(all.begin(), all.end(),
                       [&](const auto &author) {
                           return author->getFirstName() == firstName &&
                                  author->getLastName() == lastName;
                       });
}
