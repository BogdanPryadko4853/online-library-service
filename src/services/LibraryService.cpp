#include "../../include/services/LibraryService.h"


void LibraryService::createLibrary(int id, const std::string &name, const std::string &description,
                                   const std::string &address) {
    auto library = LibraryBuilder()
            .setId(1)
            .setName("Central Library")
            .setDescription("The main library of the city.")
            .setAddress("123 Main St.")
            .build();
    create(library);
}

void LibraryService::updateLibrary(int id, const std::string &name, const std::string &description,
                                   const std::string &address) {
    update(id, [&](std::shared_ptr<Library> library) {
        library->setName(name);
        library->setDescription(description);
        library->setAddress(address);
    });
}

