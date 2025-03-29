#include "../../include/services/LoanSerivce.h"
#include <algorithm>
#include <stdexcept>

LoanService::LoanService(const std::shared_ptr<LoanRepository> &repo)
        : Service(repo) {}

void LoanService::createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                             const std::chrono::system_clock::time_point &loanDate,
                             const std::chrono::system_clock::time_point &returnDate) {
    if (!book) {
        throw std::invalid_argument("Book cannot be null");
    }
    if (!user) {
        throw std::invalid_argument("User cannot be null");
    }
    if (returnDate <= loanDate) {
        throw std::invalid_argument("Return date must be after loan date");
    }
    if (!isBookAvailable(book->getId())) {
        throw std::runtime_error("Book is not available for loan");
    }
    if (!canUserBorrow(user->getId())) {
        throw std::runtime_error("User has reached the maximum number of loans");
    }

    auto loan = LoanBuilder()
            .setId(id)
            .setBook(book)
            .setUser(user)
            .setLoanDate(loanDate)
            .setReturnDate(returnDate)
            .build();
    create(loan);
}

void LoanService::returnLoan(int loanId) {
    auto loan = repository->findById(loanId);
    if (!loan) {
        throw std::runtime_error("Loan not found");
    }

    loan->setReturnDate(std::chrono::system_clock::now());
}

void LoanService::renewLoan(int loanId) {
    auto loan = repository->findById(loanId);
    if (!loan) {
        throw std::runtime_error("Loan not found");
    }
    if (isLoanOverdue(loanId)) {
        throw std::runtime_error("Cannot renew overdue loan");
    }

    auto newReturnDate = loan->getReturnDate() + std::chrono::hours(24 * LOAN_DURATION_DAYS);
    loan->setReturnDate(newReturnDate);
}

bool LoanService::isBookAvailable(int bookId) const {
    auto loans = repository->getAll();
    return std::none_of(loans.begin(), loans.end(),
                        [bookId](const std::shared_ptr<Loan> &loan) {
                            return loan->getBook()->getId() == bookId &&
                                   loan->getReturnDate() > std::chrono::system_clock::now();
                        });
}

bool LoanService::canUserBorrow(int userId) const {
    return countUserLoans(userId) < MAX_LOANS_PER_USER;
}

bool LoanService::isLoanOverdue(int loanId) const {
    auto loan = repository->findById(loanId);
    return loan && loan->getReturnDate() < std::chrono::system_clock::now();
}

std::vector<std::shared_ptr<Loan>> LoanService::getActiveLoans() const {
    auto loans = repository->getAll();
    loans.erase(std::remove_if(loans.begin(), loans.end(),
                               [](const std::shared_ptr<Loan> &loan) {
                                   return loan->getReturnDate() <= std::chrono::system_clock::now();
                               }), loans.end());
    return loans;
}

std::vector<std::shared_ptr<Loan>> LoanService::getUserLoans(int userId) const {
    auto loans = repository->getAll();
    loans.erase(std::remove_if(loans.begin(), loans.end(),
                               [userId](const std::shared_ptr<Loan> &loan) {
                                   return loan->getUser()->getId() != userId;
                               }), loans.end());
    return loans;
}

std::vector<std::shared_ptr<Loan>> LoanService::getOverdueLoans() const {
    auto loans = repository->getAll();
    loans.erase(std::remove_if(loans.begin(), loans.end(),
                               [](const std::shared_ptr<Loan> &loan) {
                                   return loan->getReturnDate() >= std::chrono::system_clock::now();
                               }), loans.end());
    return loans;
}

size_t LoanService::countActiveLoans() const {
    return getActiveLoans().size();
}

size_t LoanService::countUserLoans(int userId) const {
    return getUserLoans(userId).size();
}

size_t LoanService::countOverdueLoans() const {
    return getOverdueLoans().size();
}