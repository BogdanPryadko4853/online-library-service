#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include "Service.h"
#include "../repositories/LoanRepository.h"
#include "../enteties/Loan.h"
#include "../builder/LoanBuilder.h"
#include <chrono>
#include <memory>
#include <vector>

class LoanService : public Service<Loan, LoanRepository> {
public:
    explicit LoanService(const std::shared_ptr<LoanRepository>& repo);

    void createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                    const std::chrono::system_clock::time_point& loanDate,
                    const std::chrono::system_clock::time_point& returnDate);

    void returnLoan(int loanId);
    void renewLoan(int loanId);

    bool isBookAvailable(int bookId) const;
    bool canUserBorrow(int userId) const;
    bool isLoanOverdue(int loanId) const;

    std::vector<std::shared_ptr<Loan>> getActiveLoans() const;
    std::vector<std::shared_ptr<Loan>> getUserLoans(int userId) const;
    std::vector<std::shared_ptr<Loan>> getOverdueLoans() const;

    size_t countActiveLoans() const;
    size_t countUserLoans(int userId) const;
    size_t countOverdueLoans() const;

private:
    static constexpr int MAX_LOANS_PER_USER = 5;
    static constexpr int LOAN_DURATION_DAYS = 14;
};

#endif