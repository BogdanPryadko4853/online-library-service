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
    explicit LibraryService(const std::shared_ptr<LibraryRepository> &repo)
            : Service(repo) {}

    void createLibrary(int id, const std::string &name,
                       const std::string &description, const std::string &address);

    void updateLibrary(int id, const std::string &name,
                       const std::string &description, const std::string &address);


    [[nodiscard]] std::vector<std::shared_ptr<Library>> findByName(const std::string &name) const;

    [[nodiscard]] std::vector<std::shared_ptr<Library>> findByAddress(const std::string &address) const;

    [[nodiscard]] size_t countLibraries() const;

    [[nodiscard]] size_t countBooksInLibrary(int libraryId) const;

    [[nodiscard]] bool libraryExists(int id) const;
};

#endif