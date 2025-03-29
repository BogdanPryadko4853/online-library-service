#include "../../include/services/LibraryService.h"
#include <algorithm>
#include <stdexcept>

void LibraryService::createLibrary(int id, const std::string &name,
                                   const std::string &description, const std::string &address) {
    if (name.empty()) {
        throw std::invalid_argument("Library name cannot be empty");
    }
    if (address.empty()) {
        throw std::invalid_argument("Address cannot be empty");
    }
    if (libraryExists(id)) {
        throw std::runtime_error("Library with this ID already exists");
    }

    auto library = LibraryBuilder()
            .setId(id)
            .setName(name)
            .setDescription(description)
            .setAddress(address)
            .build();
    create(library);
}

void LibraryService::updateLibrary(int id, const std::string &name,
                                   const std::string &description, const std::string &address) {
    if (name.empty()) {
        throw std::invalid_argument("Library name cannot be empty");
    }
    if (address.empty()) {
        throw std::invalid_argument("Address cannot be empty");
    }

    update(id, [&](std::shared_ptr<Library> library) {
        library->setName(name);
        library->setDescription(description);
        library->setAddress(address);
    });
}

std::vector<std::shared_ptr<Library>> LibraryService::findByName(const std::string &name) const {
    std::vector<std::shared_ptr<Library>> result;
    auto allLibraries = getAll();

    std::copy_if(allLibraries.begin(), allLibraries.end(), std::back_inserter(result),
                 [&name](const std::shared_ptr<Library> &lib) {
                     return lib->getName().find(name) != std::string::npos;
                 });

    return result;
}

std::vector<std::shared_ptr<Library>> LibraryService::findByAddress(const std::string &address) const {
    std::vector<std::shared_ptr<Library>> result;
    auto allLibraries = getAll();

    std::copy_if(allLibraries.begin(), allLibraries.end(), std::back_inserter(result),
                 [&address](const std::shared_ptr<Library> &lib) {
                     return lib->getAddress().find(address) != std::string::npos;
                 });

    return result;
}

size_t LibraryService::countLibraries() const {
    return getAll().size();
}

size_t LibraryService::countBooksInLibrary(int libraryId) const {
    auto library = repository->findById(libraryId);
    return library ? library->getBooks().size() : 0;
}

bool LibraryService::libraryExists(int id) const {
    return repository->findById(id) != nullptr;
}