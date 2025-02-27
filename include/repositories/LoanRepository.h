#ifndef LOANREPOSITORY_H
#define LOANREPOSITORY_H

#include "../enteties/Loan.h"
#include "Repository.h"
#include "../observer/Observable.h"

class LoanRepository : public Repository<Loan>,public Observable {
private:
    LoanRepository() = default;

    LoanRepository(const LoanRepository &) = delete;

    LoanRepository &operator=(const LoanRepository &) = delete;

    static std::shared_ptr<LoanRepository> instance;

public:
    static std::shared_ptr<LoanRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<LoanRepository>(new LoanRepository());
        }
        return instance;
    }

    std::shared_ptr<Loan> findById(int id) const override;

    std::vector<std::shared_ptr<Loan>> getAll() const override;
};

#endif