#include "../../include/repositories/LoanRepository.h"
#include "../../include/config/DatabaseManager.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <string>

std::shared_ptr<LoanRepository> LoanRepository::instance = nullptr;

std::string timePointToString(const std::chrono::system_clock::time_point &tp) {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::chrono::system_clock::time_point stringToTimePoint(const std::string &str) {
    std::tm tm = {};
    int year, month, day, hour, minute, second;

    if (sscanf(str.c_str(), "%d-%d-%d %d:%d:%d",
               &year, &month, &day, &hour, &minute, &second) != 6) {
        throw std::runtime_error("Failed to parse date string: " + str);
    }

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_isdst = -1;

    std::time_t time = std::mktime(&tm);
    if (time == -1) {
        throw std::runtime_error("Failed to convert tm to time_t");
    }

    return std::chrono::system_clock::from_time_t(time);
}

std::shared_ptr<Loan> LoanRepository::findById(int id) const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT l.id, l.book_id, l.user_id, l.loan_date, l.return_date, "
            "b.title, b.description, b.author_id, "
            "u.first_name, u.last_name "
            "FROM loans l "
            "JOIN books b ON l.book_id = b.id "
            "JOIN users u ON l.user_id = u.id "
            "WHERE l.id = " + std::to_string(id)
    );

    if (result.empty()) {
        return nullptr;
    }

    auto row = result[0];
    auto book = std::make_shared<Book>(
            std::stoi(row[1]),
            row[5],
            row[6],
            std::stoi(row[7])
    );

    auto user = std::make_shared<User>(
            std::stoi(row[2]),
            row[8],
            row[9]
    );

    auto loan = std::make_shared<Loan>(
            std::stoi(row[0]),
            book,
            user,
            stringToTimePoint(row[3]),
            row[4].empty() ? std::chrono::system_clock::time_point() : stringToTimePoint(row[4])
    );

    notifyObservers("Getting loan with id - " + std::to_string(id));
    return loan;
}

std::vector<std::shared_ptr<Loan>> LoanRepository::getAll() const {
    auto &db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT l.id, l.book_id, l.user_id, l.loan_date, l.return_date, "
            "b.title, b.description, b.author_id, "
            "u.first_name, u.last_name "
            "FROM loans l "
            "JOIN books b ON l.book_id = b.id "
            "JOIN users u ON l.user_id = u.id"
    );

    std::vector<std::shared_ptr<Loan>> loans;
    for (const auto &row: result) {
        auto book = std::make_shared<Book>(
                std::stoi(row[1]), row[5], row[6], std::stoi(row[7])
        );

        auto user = std::make_shared<User>(
                std::stoi(row[2]), row[8], row[9]
        );

        loans.push_back(std::make_shared<Loan>(
                std::stoi(row[0]),  // id
                book,
                user,
                stringToTimePoint(row[3]),  // loan_date
                row[4].empty() ? std::chrono::system_clock::time_point() : stringToTimePoint(row[4]) // return_date
        ));
    }

    notifyObservers("Getting all loans");
    return loans;
}


void LoanRepository::add(const std::shared_ptr<Loan>& loan) {
    auto& db = DatabaseManager::getInstance();

    std::string loanDateStr = timePointToString(loan->getLoanDate());
    std::string returnDateStr = loan->getReturnDate() == std::chrono::system_clock::time_point()
                                ? "NULL"
                                : "'" + timePointToString(loan->getReturnDate()) + "'";

    db.execute(
            "INSERT INTO loans (id, book_id, user_id, loan_date, return_date) VALUES (" +
            std::to_string(loan->getId()) + ", " +
            std::to_string(loan->getBook()->getId()) + ", " +
            std::to_string(loan->getUser()->getId()) + ", '" +
            loanDateStr + "', " +
            returnDateStr + ")"
    );

    notifyObservers("Added new loan with id - " + std::to_string(loan->getId()));
}
