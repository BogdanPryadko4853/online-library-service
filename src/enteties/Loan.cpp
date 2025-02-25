#include "../../include/enteties/Loan.h"

Loan::Loan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
           const std::chrono::system_clock::time_point& loanDate,
           const std::chrono::system_clock::time_point& returnDate)
        : id(id), book(book), user(user), loanDate(loanDate), returnDate(returnDate) {}

int Loan::getId() const {
    return id;
}

std::shared_ptr<Book> Loan::getBook() const {
    return book;
}

std::shared_ptr<User> Loan::getUser() const {
    return user;
}

std::chrono::system_clock::time_point Loan::getLoanDate() const {
    return loanDate;
}

std::chrono::system_clock::time_point Loan::getReturnDate() const {
    return returnDate;
}

void Loan::setReturnDate(const std::chrono::system_clock::time_point& returnDate) {
    this->returnDate = returnDate;
}