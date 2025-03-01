#ifndef LIBRARYSERVICE_H
#define LIBRARYSERVICE_H

#include "Service.h"
#include "../repositories/LibraryRepository.h"
#include "../enteties/Library.h"
#include "../builder/LibraryBuilder.h"

class LibraryService : public Service<Library, LibraryRepository> {
public:
    explicit LibraryService(const std::shared_ptr<LibraryRepository>& repo)
            : Service(repo) {}

    void createLibrary(int id, const std::string& name, const std::string& description, const std::string& address) {
        auto library = LibraryBuilder()
                .setId(1)
                .setName("Central Library")
                .setDescription("The main library of the city.")
                .setAddress("123 Main St.")
                .build();
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