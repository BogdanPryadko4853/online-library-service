#include "../../include/repositories/LoanRepository.h"

std::shared_ptr<LoanRepository> LoanRepository::instance = nullptr;

std::shared_ptr<Loan> LoanRepository::findById(int id) const {
    auto loan = Repository::findById(id);
    notifyObservers(&"Getting loan with id - "[id]);
    return loan;
}

std::vector<std::shared_ptr<Loan>> LoanRepository::getAll() const {
    auto loans = Repository::getAll();
    notifyObservers("Getting all loans");
    return loans;
}
