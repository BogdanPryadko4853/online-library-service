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
    LibraryBuilder& setId(int id) {
        this->id = id;
        return *this;
    }

    LibraryBuilder& setName(const std::string& name) {
        this->name = name;
        return *this;
    }

    LibraryBuilder& setDescription(const std::string& description) {
        this->description = description;
        return *this;
    }

    LibraryBuilder& setAddress(const std::string& address) {
        this->address = address;
        return *this;
    }

    std::shared_ptr<Library> build() {
        return std::make_shared<Library>(id, name, description, address);
    }
};

#endif