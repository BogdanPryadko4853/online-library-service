#include <crow.h>
#include "include/controllers/AuthController.h"
#include "include/controllers/BookController.h"
#include "include/controllers/LibraryController.h"
#include "include/controllers/LoanController.h"
#include "include/controllers/UserController.h"
#include "include/repositories/AuthorRepository.h"
#include "include/repositories/BookRepository.h"
#include "include/repositories/LibraryRepository.h"
#include "include/repositories/LoanRepository.h"
#include "include/repositories/UserRepository.h"
#include "include/services/AuthorService.h"
#include "include/services/BookService.h"
#include "include/services/LibraryService.h"
#include "include/services/LoanSerivce.h"
#include "include/services/UserService.h"
#include "include/logger/Logger.h"

int main() {

    auto logger = std::make_shared<Logger>();
    auto authorRepo = AuthorRepository::getInstance();
    auto bookRepo = BookRepository::getInstance();
    auto libraryRepo = LibraryRepository::getInstance();
    auto loanRepo = LoanRepository::getInstance();
    auto userRepo = UserRepository::getInstance();

    bookRepo->addObserver(logger);
    authorRepo->addObserver(logger);
    libraryRepo->addObserver(logger);
    loanRepo->addObserver(logger);
    userRepo->addObserver(logger);


    auto authorService = std::make_shared<AuthorService>(authorRepo);
    auto bookService = std::make_shared<BookService>(bookRepo);
    auto libraryService = std::make_shared<LibraryService>(libraryRepo);
    auto loanService = std::make_shared<LoanService>(loanRepo);
    auto userService = std::make_shared<UserService>(userRepo);

    AuthorController authorController(authorService);
    BookController bookController(bookService);
    LibraryController libraryController(libraryService);
    LoanController loanController(loanService, bookService, userService);
    UserController userController(userService);

    crow::SimpleApp app;

    authorController.setupRoutes(app);
    bookController.setupRoutes(app);
    libraryController.setupRoutes(app);
    loanController.setupRoutes(app);
    userController.setupRoutes(app);

    app.port(8080).multithreaded().run();

    return 0;
}