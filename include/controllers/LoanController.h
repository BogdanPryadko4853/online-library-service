#ifndef LOANCONTROLLER_H
#define LOANCONTROLLER_H

#include <crow.h>
#include <memory>
#include "../services/LoanSerivce.h"
#include "../services/UserService.h"
#include "../services/BookService.h"

class LoanController {
private:
    std::shared_ptr<LoanService> loanService;
    std::shared_ptr<BookService> bookService;
    std::shared_ptr<UserService> userService;

public:
    explicit LoanController(
            const std::shared_ptr<LoanService>& loanService,
            const std::shared_ptr<BookService>& bookService,
            const std::shared_ptr<UserService>& userService
    )
            : loanService(loanService), bookService(bookService), userService(userService) {}

    void setupRoutes(crow::SimpleApp& app);
};

#endif