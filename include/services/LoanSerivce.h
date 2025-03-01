#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include "Service.h"
#include "../repositories/LoanRepository.h"
#include "../enteties/Loan.h"
#include "../builder/LoanBuilder.h"

class LoanService : public Service<Loan, LoanRepository> {
public:
    explicit LoanService(const std::shared_ptr<LoanRepository>& repo)
            : Service(repo) {}

    void createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                    const std::chrono::system_clock::time_point& loanDate,
                    const std::chrono::system_clock::time_point& returnDate) {
        auto loan = LoanBuilder()
                .setId(1)
                .setBook(book)
                .setUser(user)
                .setLoanDate(std::chrono::system_clock::now())
                .setReturnDate(std::chrono::system_clock::now() + std::chrono::hours(24 * 14)) // 2 weeks
                .build();
        create(loan);
    }
};

#endif