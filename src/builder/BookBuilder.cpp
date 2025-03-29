#include "../../include/builder/BookBuilder.h"


BookBuilder &BookBuilder::setId(int id) {
    this->id = id;
    return *this;
}

BookBuilder &BookBuilder::setTitle(const std::string &title) {
    this->title = title;
    return *this;
}

BookBuilder &BookBuilder::setDescription(const std::string &description) {
    this->description = description;
    return *this;
}

BookBuilder &BookBuilder::setAuthorId(int authorId) {
    this->authorId = authorId;
    return *this;
}

std::shared_ptr<Book> BookBuilder::build() {
    return std::make_shared<Book>(id, title, description, authorId);
}
