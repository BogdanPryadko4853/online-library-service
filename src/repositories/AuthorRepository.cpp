#include "../../include/repositories/AuthorRepository.h"

void AuthorRepository::addAuthor(const std::shared_ptr<Author>& author) {
    authors.push_back(author);
}

void AuthorRepository::removeAuthor(const std::shared_ptr<Author>& author) {
    authors.erase(
            std::remove_if(
                    authors.begin(),
                    authors.end(),
                    [&author](const std::shared_ptr<Author>& a) {
                        return a->getId() == author->getId();
                    }
            ),
            authors.end()
    );
}

std::shared_ptr<Author> AuthorRepository::findAuthorById(int id) const {
    for (const auto& author : authors) {
        if (author->getId() == id) {
            return author;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Author>> AuthorRepository::getAllAuthors() const {
    return authors;
}