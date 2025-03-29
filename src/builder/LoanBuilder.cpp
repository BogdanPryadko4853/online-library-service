

#include "../../include/builder/LoanBuilder.h"


LoanBuilder &LoanBuilder::setId(int id) {
    this->id = id;
    return *this;
}

LoanBuilder &LoanBuilder::setBook(const std::shared_ptr<Book> &book) {
    this->book = book;
    return *this;
}

LoanBuilder &LoanBuilder::setUser(const std::shared_ptr<User> &user) {
    this->user = user;
    return *this;
}

LoanBuilder &LoanBuilder::setLoanDate(const std::chrono::system_clock::time_point &loanDate) {
    this->loanDate = loanDate;
    return *this;
}

LoanBuilder &LoanBuilder::setReturnDate(const std::chrono::system_clock::time_point &returnDate) {
    this->returnDate = returnDate;
    return *this;
}

std::shared_ptr<Loan> LoanBuilder::build() {
    return std::make_shared<Loan>(id, book, user, loanDate, returnDate);
}
