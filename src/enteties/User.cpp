#include "../../include/enteties/User.h"
#include "../../include/enteties/Loan.h"

User::User(int id, const std::string& firstName, const std::string& lastName)
        : id(id), firstName(firstName), lastName(lastName) {}

int User::getId() const {
    return id;
}

std::string User::getFirstName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}

const std::vector<std::shared_ptr<Loan>>& User::getLoans() const {
    return loans;
}

void User::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void User::addLoan(const std::shared_ptr<Loan>& loan) {
    loans.push_back(loan);
}

void User::removeLoan(const std::shared_ptr<Loan>& loan) {
    loans.erase(
            std::remove_if(
                    loans.begin(),
                    loans.end(),
                    [&loan](const std::shared_ptr<Loan>& l) {
                        return l == loan;
                    }
            ),
            loans.end()
    );
}