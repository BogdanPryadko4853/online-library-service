#include "../../include/repositories/LibraryRepository.h"

void LibraryRepository::addLibrary(const std::shared_ptr<Library>& library) {
    libraries.push_back(library);
}

void LibraryRepository::removeLibrary(const std::shared_ptr<Library>& library) {
    libraries.erase(
            std::remove_if(
                    libraries.begin(),
                    libraries.end(),
                    [&library](const std::shared_ptr<Library>& l) {
                        return l->getId() == library->getId();
                    }
            ),
            libraries.end()
    );
}

std::shared_ptr<Library> LibraryRepository::findLibraryById(int id) const {
    for (const auto& library : libraries) {
        if (library->getId() == id) {
            return library;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Library>> LibraryRepository::getAllLibraries() const {
    return libraries;
}