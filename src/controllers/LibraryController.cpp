#include "../../include/controllers/LibraryController.h"

LibraryController::LibraryController(const std::shared_ptr<LibraryService>& service)
        : libraryService(service) {}

void LibraryController::setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/libraries")([this]() {
        auto libraries = libraryService->getAll();
        crow::json::wvalue result;
        for (size_t i = 0; i < libraries.size(); ++i) {
            result[i]["id"] = libraries[i]->getId();
            result[i]["name"] = libraries[i]->getName();
            result[i]["description"] = libraries[i]->getDescription();
            result[i]["address"] = libraries[i]->getAddress();
        }
        return result;
    });

    CROW_ROUTE(app, "/libraries/<int>")([this](int id) {
        auto library = libraryService->getById(id);
        if (library) {
            crow::json::wvalue result;
            result["id"] = library->getId();
            result["name"] = library->getName();
            result["description"] = library->getDescription();
            result["address"] = library->getAddress();
            return crow::response{result.dump()};
        } else {
            return crow::response(404, "Library not found");
        }
    });

    CROW_ROUTE(app, "/libraries").methods("POST"_method)([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        int id = body["id"].i();
        std::string name = body["name"].s();
        std::string description = body["description"].s();
        std::string address = body["address"].s();
        libraryService->createLibrary(id, name, description, address);
        return crow::response(201, "Library created");
    });

    CROW_ROUTE(app, "/libraries/<int>").methods("PUT"_method)([this](const crow::request& req, int id) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        std::string name = body["name"].s();
        std::string description = body["description"].s();
        std::string address = body["address"].s();
        libraryService->updateLibrary(id, name, description, address);
        return crow::response(200, "Library updated");
    });

    CROW_ROUTE(app, "/libraries/<int>").methods("DELETE"_method)([this](int id) {
        libraryService->deleteById(id);
        return crow::response(200, "Library deleted");
    });
}