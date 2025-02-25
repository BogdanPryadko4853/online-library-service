#include "../../include/services/LibraryService.h"

LibraryService::LibraryService(const std::shared_ptr<LibraryRepository>& repo)
        : libraryRepository(repo) {}

void LibraryService::createLibrary(int id, const std::string& name, const std::string& description, const std::string& address) {
    auto library = std::make_shared<Library>(id, name, description, address);
    libraryRepository->add(library);
}

std::shared_ptr<Library> LibraryService::getLibraryById(int id) const {
    return libraryRepository->findById(id);
}

std::vector<std::shared_ptr<Library>> LibraryService::getAllLibraries() const {
    return libraryRepository->getAll();
}

void LibraryService::updateLibrary(int id, const std::string& name, const std::string& description, const std::string& address) {
    auto library = libraryRepository->findById(id);
    if (library) {
        library->setName(name);
        library->setDescription(description);
        library->setAddress(address);
    }
}

void LibraryService::deleteLibrary(int id) {
    auto library = libraryRepository->findById(id);
    if (library) {
        libraryRepository->remove(library);
    }
}