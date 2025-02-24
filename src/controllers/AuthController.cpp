#include "../../include/controllers/AuthController.h"

AuthorController::AuthorController(const std::shared_ptr<AuthorService>& service)
        : authorService(service) {}

void AuthorController::setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/authors")([this]() {
        auto authors = authorService->getAllAuthors();
        crow::json::wvalue result;
        for (size_t i = 0; i < authors.size(); ++i) {
            result[i]["id"] = authors[i]->getId();
            result[i]["firstName"] = authors[i]->getFirstName();
            result[i]["lastName"] = authors[i]->getLastName();
            result[i]["bio"] = authors[i]->getBio();
        }
        return result;
    });

    CROW_ROUTE(app, "/authors/<int>")([this](int id) {
        auto author = authorService->getAuthorById(id);
        if (author) {
            crow::json::wvalue result;
            result["id"] = author->getId();
            result["firstName"] = author->getFirstName();
            result["lastName"] = author->getLastName();
            result["bio"] = author->getBio();
            return crow::response{result.dump()};
        } else {
            return crow::response(404, "Author not found");
        }
    });

    CROW_ROUTE(app, "/authors").methods("POST"_method)([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        int id = body["id"].i();
        std::string firstName = body["firstName"].s();
        std::string lastName = body["lastName"].s();
        std::string bio = body["bio"].s();
        authorService->createAuthor(id, firstName, lastName, bio);
        return crow::response(201, "Author created");
    });
}