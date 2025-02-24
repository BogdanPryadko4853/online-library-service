#ifndef LIBRARYSERVICE_H
#define LIBRARYSERVICE_H

#include <memory>
#include <vector>
#include "../repositories/LibraryRepository.h"
#include "../enteties/Library.h"

class LibraryService {
private:
    std::shared_ptr<LibraryRepository> libraryRepository;

public:
    explicit LibraryService(const std::shared_ptr<LibraryRepository>& repo);
    void createLibrary(int id, const std::string& name, const std::string& description, const std::string& address);
    std::shared_ptr<Library> getLibraryById(int id) const;
    std::vector<std::shared_ptr<Library>> getAllLibraries() const;
    void updateLibrary(int id, const std::string& name, const std::string& description, const std::string& address);
    void deleteLibrary(int id);
};

#endif