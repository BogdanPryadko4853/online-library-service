#ifndef LIBRARYBUILDER_H
#define LIBRARYBUILDER_H

#include "../enteties/Library.h"

class LibraryBuilder {
private:
    int id;
    std::string name;
    std::string description;
    std::string address;

public:
    LibraryBuilder &setId(int id);

    LibraryBuilder &setName(const std::string &name);

    LibraryBuilder &setDescription(const std::string &description);

    LibraryBuilder &setAddress(const std::string &address);

    std::shared_ptr<Library> build();
};

#endif