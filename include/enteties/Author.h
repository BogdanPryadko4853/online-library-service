#ifndef COURSEWORK_AUTHOR_H
#define COURSEWORK_AUTHOR_H

#include <string>

class Author {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string bio;

public:
    Author(int id, const std::string& firstName, const std::string& lastName, const std::string& bio);
    ~Author() = default;

    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getBio() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setBio(const std::string& bio);
};

#endif