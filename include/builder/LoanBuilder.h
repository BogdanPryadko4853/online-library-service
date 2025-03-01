#ifndef LOANBUILDER_H
#define LOANBUILDER_H

#include "../enteties/Loan.h"

class LoanBuilder {
private:
    int id;
    std::shared_ptr<Book> book;
    std::shared_ptr<User> user;
    std::chrono::system_clock::time_point loanDate;
    std::chrono::system_clock::time_point returnDate;

public:
    LoanBuilder& setId(int id) {
        this->id = id;
        return *this;
    }

    LoanBuilder& setBook(const std::shared_ptr<Book>& book) {
        this->book = book;
        return *this;
    }

    LoanBuilder& setUser(const std::shared_ptr<User>& user) {
        this->user = user;
        return *this;
    }

    LoanBuilder& setLoanDate(const std::chrono::system_clock::time_point& loanDate) {
        this->loanDate = loanDate;
        return *this;
    }

    LoanBuilder& setReturnDate(const std::chrono::system_clock::time_point& returnDate) {
        this->returnDate = returnDate;
        return *this;
    }

    std::shared_ptr<Loan> build() {
        return std::make_shared<Loan>(id, book, user, loanDate, returnDate);
    }
};

#endif