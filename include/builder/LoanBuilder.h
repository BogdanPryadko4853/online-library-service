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
    LoanBuilder &setId(int id);

    LoanBuilder &setBook(const std::shared_ptr<Book> &book);

    LoanBuilder &setUser(const std::shared_ptr<User> &user);

    LoanBuilder &setLoanDate(const std::chrono::system_clock::time_point &loanDate);

    LoanBuilder &setReturnDate(const std::chrono::system_clock::time_point &returnDate);
};

#endif