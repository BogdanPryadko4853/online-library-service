#ifndef LIBRARYSERVICE_H
#define LIBRARYSERVICE_H

#include "Service.h"
#include "../repositories/LibraryRepository.h"
#include "../enteties/Library.h"
#include "../builder/LibraryBuilder.h"
#include <vector>
#include <memory>

class LibraryService : public Service<Library, LibraryRepository> {
public:
    explicit LibraryService(const std::shared_ptr<LibraryRepository>& repo)
            : Service(repo) {}

    void createLibrary(int id, const std::string& name,
                       const std::string& description, const std::string& address);
    void updateLibrary(int id, const std::string& name,
                       const std::string& description, const std::string& address);

    void addBookToLibrary(int libraryId, int bookId);
    void removeBookFromLibrary(int libraryId, int bookId);
    std::vector<std::shared_ptr<Book>> getLibraryBooks(int libraryId) const;

    std::vector<std::shared_ptr<Library>> findByName(const std::string& name) const;
    std::vector<std::shared_ptr<Library>> findByAddress(const std::string& address) const;

    size_t countLibraries() const;
    size_t countBooksInLibrary(int libraryId) const;

    bool libraryExists(int id) const;
};

#endif