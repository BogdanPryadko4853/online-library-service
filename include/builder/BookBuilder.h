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
    BookBuilder &setId(int id);

    BookBuilder &setTitle(const std::string &title);

    BookBuilder &setDescription(const std::string &description);

    BookBuilder &setAuthorId(int authorId);

    std::shared_ptr<Book> build();
};

#endif