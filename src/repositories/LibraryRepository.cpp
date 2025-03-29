#include "../../include/repositories/LibraryRepository.h"
#include <algorithm>

std::shared_ptr<LibraryRepository> LibraryRepository::instance = nullptr;

std::shared_ptr<LibraryRepository> LibraryRepository::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<LibraryRepository>(new LibraryRepository());
    }
    return instance;
}

void LibraryRepository::add(const std::shared_ptr<Library> &library) {
    if (!library) {
        throw std::invalid_argument("Cannot add null library");
    }
    if (exists(library->getId())) {
        throw std::runtime_error("Library with this ID already exists");
    }
    if (nameExists(library->getName())) {
        throw std::runtime_error("Library with this name already exists");
    }

    Repository<Library>::add(library);
    notifyObservers("Added library: ID=" + std::to_string(library->getId()) +
                    ", Name=" + library->getName());
}

void LibraryRepository::remove(const std::shared_ptr<Library> &library) {
    if (!library || !exists(library->getId())) {
        throw std::runtime_error("Library not found");
    }

    Repository<Library>::remove(library);
    notifyObservers("Removed library: ID=" + std::to_string(library->getId()));
}

std::shared_ptr<Library> LibraryRepository::findById(int id) const {
    auto library = Repository<Library>::findById(id);
    notifyObservers("Found library with id " + std::to_string(id));
    return library;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::getAll() const {
    auto libraries = Repository<Library>::getAll();
    notifyObservers("Retrieved all libraries (count: " + std::to_string(libraries.size()) + ")");
    return libraries;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::findByName(const std::string &name) const {
    std::vector<std::shared_ptr<Library>> result;
    auto all = getAll();

    std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                 [&name](const auto &library) {
                     return library->getName().find(name) != std::string::npos;
                 });

    notifyObservers("Search by name: '" + name + "' found " + std::to_string(result.size()) + " libraries");
    return result;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::findByAddress(const std::string &address) const {
    std::vector<std::shared_ptr<Library>> result;
    auto all = getAll();

    std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                 [&address](const auto &library) {
                     return library->getAddress().find(address) != std::string::npos;
                 });

    notifyObservers("Search by address: '" + address + "' found " + std::to_string(result.size()) + " libraries");
    return result;
}


bool LibraryRepository::exists(int id) const {
    return findById(id) != nullptr;
}

bool LibraryRepository::nameExists(const std::string &name) const {
    auto all = getAll();
    return std::any_of(all.begin(), all.end(),
                       [&name](const auto &library) {
                           return library->getName() == name;
                       });
}
