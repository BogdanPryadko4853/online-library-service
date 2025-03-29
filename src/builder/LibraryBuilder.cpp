#include "../../include/builder/LibraryBuilder.h"

LibraryBuilder &LibraryBuilder::setId(int id) {
    this->id = id;
    return *this;
}

LibraryBuilder &LibraryBuilder::setName(const std::string &name) {
    this->name = name;
    return *this;
}

LibraryBuilder &LibraryBuilder::setDescription(const std::string &description) {
    this->description = description;
    return *this;
}

LibraryBuilder &LibraryBuilder::setAddress(const std::string &address) {
    this->address = address;
    return *this;
}

std::shared_ptr<Library> LibraryBuilder::build() {
    return std::make_shared<Library>(id, name, description, address);
}
