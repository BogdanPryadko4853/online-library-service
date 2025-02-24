#include <crow.h>
#include "include/controllers/AuthController.h"
#include "include/controllers/BookController.h"
#include "include/repositories/AuthorRepository.h"
#include "include/repositories/BookRepository.h"
#include "include/services/AuthorService.h"
#include "include/services/BookService.h"

int main() {
    auto authorRepo = std::make_shared<AuthorRepository>();
    auto bookRepo = std::make_shared<BookRepository>();

    auto authorService = std::make_shared<AuthorService>(authorRepo);
    auto bookService = std::make_shared<BookService>(bookRepo);

    AuthorController authorController(authorService);
    BookController bookController(bookService);

    crow::SimpleApp app;

    authorController.setupRoutes(app);
    bookController.setupRoutes(app);

    app.port(8080).multithreaded().run();

    return 0;
}