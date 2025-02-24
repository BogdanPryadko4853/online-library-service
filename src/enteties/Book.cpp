#include <algorithm>
#include "../../include/enteties/Library.h"
#include "../../include/enteties/Book.h"

Book::Book(int id, const std::string &title, const std::string &description, int authorId)
        : id(id), title(title), description(description), authorId(authorId) {}

int Book::getId() const { return id; }

std::string Book::getTitle() const { return title; }

std::string Book::getDescription() const { return description; }

int Book::getAuthorId() const { return authorId; }

const std::vector<std::shared_ptr<Library>> &Book::getLibraries() const { return libraries; }

void Book::setTitle(const std::string &title) { this->title = title; }

void Book::setDescription(const std::string &description) { this->description = description; }

void Book::addLibrary(const std::shared_ptr<Library> &library) {
    libraries.push_back(library);
}

void Book::removeLibrary(const std::shared_ptr<Library> &library) {
    libraries.erase(
            std::remove_if(
                    libraries.begin(),
                    libraries.end(),
                    [&library](const std::shared_ptr<Library>& lib) {
                        return lib == library;
                    }
            ),
            libraries.end()
    );
}
