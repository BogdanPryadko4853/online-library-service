#ifndef LOANREPOSITORY_H
#define LOANREPOSITORY_H

#include <vector>
#include <memory>
#include "../enteties//Loan.h"

class LoanRepository {
private:
    std::vector<std::shared_ptr<Loan>> loans;

public:
    void addLoan(const std::shared_ptr<Loan>& loan);
    void removeLoan(const std::shared_ptr<Loan>& loan);
    std::shared_ptr<Loan> findLoanById(int id) const;
    std::vector<std::shared_ptr<Loan>> getAllLoans() const;
};

#endif