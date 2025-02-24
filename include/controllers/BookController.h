#ifndef BOOKCONTROLLER_H
#define BOOKCONTROLLER_H

#include <crow.h>
#include <memory>
#include "../services/BookService.h"

class BookController {
private:
    std::shared_ptr<BookService> bookService;

public:
    explicit BookController(const std::shared_ptr<BookService>& service);
    void setupRoutes(crow::SimpleApp& app);
};

#endif