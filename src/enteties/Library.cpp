#include <algorithm>
#include "../../include/enteties/Library.h"
#include "../../include/enteties/Book.h"

Library::Library(int id, const std::string& name, const std::string& description, const std::string& address)
        : id(id), name(name), description(description), address(address) {}

int Library::getId() const { return id; }
std::string Library::getName() const { return name; }
std::string Library::getDescription() const { return description; }
std::string Library::getAddress() const { return address; }
const std::vector<std::shared_ptr<Book>>& Library::getBooks() const { return books; }

void Library::setName(const std::string& name) { this->name = name; }
void Library::setDescription(const std::string& description) { this->description = description; }
void Library::setAddress(const std::string& address) { this->address = address; }

void Library::addBook(const std::shared_ptr<Book>& book) {
    books.push_back(book);
    book->addLibrary(shared_from_this());
}

