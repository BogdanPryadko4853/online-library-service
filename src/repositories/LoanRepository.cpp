#include "../../include/repositories/LoanRepository.h"

//void LoanRepository::addLoan(const std::shared_ptr<Loan>& loan) {
//    loans.push_back(loan);
//}
//
//void LoanRepository::removeLoan(const std::shared_ptr<Loan>& loan) {
//    loans.erase(
//            std::remove_if(
//                    loans.begin(),
//                    loans.end(),
//                    [&loan](const std::shared_ptr<Loan>& l) {
//                        return l->getId() == loan->getId();
//                    }
//            ),
//            loans.end()
//    );
//}
//
//std::shared_ptr<Loan> LoanRepository::findLoanById(int id) const {
//    for (const auto& loan : loans) {
//        if (loan->getId() == id) {
//            return loan;
//        }
//    }
//    return nullptr;
//}
//
//std::vector<std::shared_ptr<Loan>> LoanRepository::getAllLoans() const {
//    return loans;
//}