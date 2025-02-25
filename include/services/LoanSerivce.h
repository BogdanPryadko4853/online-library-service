#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include "Service.h"
#include "../repositories/LoanRepository.h"
#include "../enteties/Loan.h"

class LoanService : public Service<Loan, LoanRepository> {
public:
    explicit LoanService(const std::shared_ptr<LoanRepository>& repo)
            : Service(repo) {}

    void createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                    const std::chrono::system_clock::time_point& loanDate,
                    const std::chrono::system_clock::time_point& returnDate) {
        auto loan = std::make_shared<Loan>(id, book, user, loanDate, returnDate);
        create(loan);
    }
};

#endif