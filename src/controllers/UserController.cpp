#include "../../include/controllers/UserController.h"

UserController::UserController(const std::shared_ptr<UserService>& service)
        : userService(service) {}

void UserController::setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/users")([this]() {
        auto users = userService->getAllUsers();
        crow::json::wvalue result;
        for (size_t i = 0; i < users.size(); ++i) {
            result[i]["id"] = users[i]->getId();
            result[i]["firstName"] = users[i]->getFirstName();
            result[i]["lastName"] = users[i]->getLastName();
        }
        return result;
    });

    CROW_ROUTE(app, "/users/<int>")([this](int id) {
        auto user = userService->getUserById(id);
        if (user) {
            crow::json::wvalue result;
            result["id"] = user->getId();
            result["firstName"] = user->getFirstName();
            result["lastName"] = user->getLastName();
            return crow::response{result.dump()};
        } else {
            return crow::response(404, "User not found");
        }
    });

    CROW_ROUTE(app, "/users").methods("POST"_method)([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        int id = body["id"].i();
        std::string firstName = body["firstName"].s();
        std::string lastName = body["lastName"].s();
        userService->createUser(id, firstName, lastName);
        return crow::response(201, "User created");
    });

    CROW_ROUTE(app, "/users/<int>").methods("DELETE"_method)([this](int id) {
        userService->deleteUser(id);
        return crow::response(200, "User deleted");
    });
}