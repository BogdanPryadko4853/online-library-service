#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <crow.h>
#include <memory>
#include "../services/UserService.h"

class UserController {
private:
    std::shared_ptr<UserService> userService;

public:
    explicit UserController(const std::shared_ptr<UserService>& service);
    void setupRoutes(crow::SimpleApp& app);
};

#endif