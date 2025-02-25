#include "../../include/services/LoanSerivce.h"

LoanService::LoanService(std::shared_ptr<LoanRepository> repo)
        : loanRepository(std::move(repo)) {}

void LoanService::createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                             const std::chrono::system_clock::time_point& loanDate,
                             const std::chrono::system_clock::time_point& returnDate) {
    auto loan = std::make_shared<Loan>(id, book, user, loanDate, returnDate);
    loanRepository->add(loan);
}

void LoanService::deleteLoan(int id) {
    auto loan = loanRepository->findById(id);
    if (loan) {
        loanRepository->remove(loan);
    }
}

std::shared_ptr<Loan> LoanService::getLoanById(int id) const {
    return loanRepository->findById(id);
}

std::vector<std::shared_ptr<Loan>> LoanService::getAllLoans() const {
    return loanRepository->getAll();
}