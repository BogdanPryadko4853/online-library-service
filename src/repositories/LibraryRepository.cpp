#include "../../include/repositories/LibraryRepository.h"

std::shared_ptr<LibraryRepository> LibraryRepository::instance = nullptr;


std::shared_ptr<Library> LibraryRepository::findById(int id) const {
    auto library = Repository<Library>::findById(id);
    notifyObservers(&"Founded library with id - "[id]);
    return library;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::getAll() const {
    auto libraries = Repository::getAll();
    notifyObservers("Getting all libraries");
    return libraries;
}


