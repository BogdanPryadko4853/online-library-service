#ifndef LIBRARYREPOSITORY_H
#define LIBRARYREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Library.h"

class LibraryRepository {
private:
    std::vector<std::shared_ptr<Library>> libraries;

public:
    void addLibrary(const std::shared_ptr<Library>& library);
    void removeLibrary(const std::shared_ptr<Library>& library);
    std::shared_ptr<Library> findLibraryById(int id) const;
    std::vector<std::shared_ptr<Library>> getAllLibraries() const;
};

#endif