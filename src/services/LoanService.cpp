#include "../../include/services/LoanSerivce.h"

LoanService::LoanService(std::shared_ptr<LoanRepository> repo)
        : loanRepository(std::move(repo)) {}

void LoanService::createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                             const std::chrono::system_clock::time_point& loanDate,
                             const std::chrono::system_clock::time_point& returnDate) {
    auto loan = std::make_shared<Loan>(id, book, user, loanDate, returnDate);
    loanRepository->addLoan(loan);
}

void LoanService::deleteLoan(int id) {
    auto loan = loanRepository->findLoanById(id);
    if (loan) {
        loanRepository->removeLoan(loan);
    }
}

std::shared_ptr<Loan> LoanService::getLoanById(int id) const {
    return loanRepository->findLoanById(id);
}

std::vector<std::shared_ptr<Loan>> LoanService::getAllLoans() const {
    return loanRepository->getAllLoans();
}