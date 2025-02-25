#include "../../include/controllers/LoanController.h"

void LoanController::setupRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/loans")([this]() {
        auto loans = loanService->getAllLoans();
        crow::json::wvalue result;
        for (size_t i = 0; i < loans.size(); ++i) {
            result[i]["id"] = loans[i]->getId();
            result[i]["bookId"] = loans[i]->getBook()->getId();
            result[i]["userId"] = loans[i]->getUser()->getId();
            result[i]["loanDate"] = std::chrono::system_clock::to_time_t(loans[i]->getLoanDate());
            result[i]["returnDate"] = std::chrono::system_clock::to_time_t(loans[i]->getReturnDate());
        }
        return result;
    });

    CROW_ROUTE(app, "/loans/<int>")([this](int id) {
        auto loan = loanService->getLoanById(id);
        if (loan) {
            crow::json::wvalue result;
            result["id"] = loan->getId();
            result["bookId"] = loan->getBook()->getId();
            result["userId"] = loan->getUser()->getId();
            result["loanDate"] = std::chrono::system_clock::to_time_t(loan->getLoanDate());
            result["returnDate"] = std::chrono::system_clock::to_time_t(loan->getReturnDate());
            return crow::response{result.dump()};
        } else {
            return crow::response(404, "Loan not found");
        }
    });

    CROW_ROUTE(app, "/loans").methods("POST"_method)([this](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }

        int id = body["id"].i();
        int bookId = body["bookId"].i();
        int userId = body["userId"].i();
        auto loanDate = std::chrono::system_clock::from_time_t(body["loanDate"].i());
        auto returnDate = std::chrono::system_clock::from_time_t(body["returnDate"].i());

        auto book = bookService->getBookById(bookId);
        auto user = userService->getUserById(userId);

        if (!book) {
            return crow::response(404, "Book not found");
        }
        if (!user) {
            return crow::response(404, "User not found");
        }
        loanService->createLoan(id, book, user, loanDate, returnDate);
        return crow::response(201, "Loan created");
    });
    CROW_ROUTE(app, "/loans/<int>").methods("DELETE"_method)([this](int id) {
        loanService->deleteLoan(id);
        return crow::response(200, "Loan deleted");
    });
}