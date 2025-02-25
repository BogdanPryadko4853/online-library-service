#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include <memory>
#include "../repositories/LoanRepository.h"

class LoanService {
private:
    std::shared_ptr<LoanRepository> loanRepository;

public:
    explicit LoanService(std::shared_ptr<LoanRepository> repo);
    void createLoan(int id, std::shared_ptr<Book> book, std::shared_ptr<User> user,
                    const std::chrono::system_clock::time_point& loanDate,
                    const std::chrono::system_clock::time_point& returnDate);
    void deleteLoan(int id);
    std::shared_ptr<Loan> getLoanById(int id) const;
    std::vector<std::shared_ptr<Loan>> getAllLoans() const;
};

#endif