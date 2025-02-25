#ifndef LOANREPOSITORY_H
#define LOANREPOSITORY_H

#include <vector>
#include <memory>
#include "../enteties//Loan.h"
#include "Repository.h"

class LoanRepository : Repository<Loan> {
private:
    std::vector<std::shared_ptr<Loan>> loans;
};

#endif