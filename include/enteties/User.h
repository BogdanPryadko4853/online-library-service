#ifndef COURSEWORK_USER_H
#define COURSEWORK_USER_H

#include <string>
#include <vector>
#include <memory>

class Loan;

class User {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string password;
    std::vector<std::shared_ptr<Loan>> loans;

public:
    User(int id, const std::string& firstName, const std::string& lastName);
    ~User() = default;

    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    const std::vector<std::shared_ptr<Loan>>& getLoans() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPassword(const std::string& password);

    void addLoan(const std::shared_ptr<Loan>& loan);
    void removeLoan(const std::shared_ptr<Loan>& loan);

    std::string getPassword();

};

#endif