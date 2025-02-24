#ifndef AUTHORCONTROLLER_H
#define AUTHORCONTROLLER_H

#include <crow.h>
#include <memory>
#include "../services/AuthorService.h"

class AuthorController {
private:
    std::shared_ptr<AuthorService> authorService;

public:
    explicit AuthorController(const std::shared_ptr<AuthorService>& service);
    void setupRoutes(crow::SimpleApp& app);
};

#endif