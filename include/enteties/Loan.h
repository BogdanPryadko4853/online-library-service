#ifndef LOAN_H
#define LOAN_H

#include <memory>
#include <chrono>
#include "Book.h"
#include "User.h"

class Loan {
private:
    int id;
    std::shared_ptr<Book> book;
    std::shared_ptr<User> user;
    std::chrono::system_clock::time_point loanDate;
    std::chrono::system_clock::time_point returnDate;

public:
    Loan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
         const std::chrono::system_clock::time_point& loanDate,
         const std::chrono::system_clock::time_point& returnDate);

    int getId() const;
    std::shared_ptr<Book> getBook() const;
    std::shared_ptr<User> getUser() const;
    std::chrono::system_clock::time_point getLoanDate() const;
    std::chrono::system_clock::time_point getReturnDate() const;

    void setReturnDate(const std::chrono::system_clock::time_point& returnDate);
};

#endif