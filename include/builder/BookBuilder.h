#ifndef BOOKBUILDER_H
#define BOOKBUILDER_H

#include "../enteties/Book.h"

class BookBuilder {
private:
    int id;
    std::string title;
    std::string description;
    int authorId;

public:
    BookBuilder& setId(int id) {
        this->id = id;
        return *this;
    }

    BookBuilder& setTitle(const std::string& title) {
        this->title = title;
        return *this;
    }

    BookBuilder& setDescription(const std::string& description) {
        this->description = description;
        return *this;
    }

    BookBuilder& setAuthorId(int authorId) {
        this->authorId = authorId;
        return *this;
    }

    std::shared_ptr<Book> build() {
        return std::make_shared<Book>(id, title, description, authorId);
    }
};

#endif