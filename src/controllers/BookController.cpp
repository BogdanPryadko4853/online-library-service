#include "../../include/controllers/BookController.h"

BookController::BookController(const std::shared_ptr<BookService>& service)
        : bookService(service) {}

void BookController::setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/books")([this]() {
        auto books = bookService->getAll();
        crow::json::wvalue result;
        for (size_t i = 0; i < books.size(); ++i) {
            result[i]["id"] = books[i]->getId();
            result[i]["title"] = books[i]->getTitle();
            result[i]["description"] = books[i]->getDescription();
            result[i]["authorId"] = books[i]->getAuthorId();
        }
        return result;
    });

    CROW_ROUTE(app, "/books/<int>")([this](int id) {
        auto book = bookService->getById(id);
        if (book) {
            crow::json::wvalue result;
            result["id"] = book->getId();
            result["title"] = book->getTitle();
            result["description"] = book->getDescription();
            result["authorId"] = book->getAuthorId();
            return crow::response{result.dump()}; // Возвращаем crow::response с JSON
        } else {
            return crow::response(404, "Book not found");
        }
    });

    CROW_ROUTE(app, "/books").methods("POST"_method)([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        int id = body["id"].i();
        std::string title = body["title"].s();
        std::string description = body["description"].s();
        int authorId = body["authorId"].i();
        bookService->createBook(id, title, description, authorId);
        return crow::response(201, "Book created");
    });
}