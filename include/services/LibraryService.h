#ifndef LIBRARYSERVICE_H
#define LIBRARYSERVICE_H

#include "Service.h"
#include "../repositories/LibraryRepository.h"
#include "../enteties/Library.h"

class LibraryService : public Service<Library, LibraryRepository> {
public:
    explicit LibraryService(const std::shared_ptr<LibraryRepository>& repo)
            : Service(repo) {}

    void createLibrary(int id, const std::string& name, const std::string& description, const std::string& address) {
        auto library = std::make_shared<Library>(id, name, description, address);
        create(library);
    }

    void updateLibrary(int id, const std::string& name, const std::string& description, const std::string& address) {
        update(id, [&](std::shared_ptr<Library> library) {
            library->setName(name);
            library->setDescription(description);
            library->setAddress(address);
        });
    }
};

#endif