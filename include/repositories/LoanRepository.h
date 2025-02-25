#ifndef LOANREPOSITORY_H
#define LOANREPOSITORY_H

#include <vector>
#include <memory>
#include "../enteties//Loan.h"
#include "Repository.h"

class LoanRepository : public  Repository<Loan> {
private:
    std::vector<std::shared_ptr<Loan>> loans;
public:
    using Repository<Loan>::add;
    using Repository<Loan>::remove;
    using Repository<Loan>::findById;
    using Repository<Loan>::getAll;
};

#endif