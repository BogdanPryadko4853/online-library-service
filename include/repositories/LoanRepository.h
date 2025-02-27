#ifndef LOANREPOSITORY_H
#define LOANREPOSITORY_H

#include "../enteties/Loan.h"
#include "Repository.h"

class LoanRepository : public Repository<Loan> {
private:
    LoanRepository() = default;

    LoanRepository(const LoanRepository &) = delete;

    LoanRepository &operator=(const LoanRepository &) = delete;

    static std::shared_ptr<LoanRepository> instance;

public:
    // Метод для доступа к экземпляру
    static std::shared_ptr<LoanRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<LoanRepository>(new LoanRepository());
        }
        return instance;
    }
};

#endif