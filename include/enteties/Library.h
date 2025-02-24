#ifndef COURSEWORK_LIBRARY_H
#define COURSEWORK_LIBRARY_H

#include <string>
#include <vector>
#include <memory>

class Book;

class Library  : public std::enable_shared_from_this<Library> {
private:
    int id;
    std::string name;
    std::string description;
    std::string address;
    std::vector<std::shared_ptr<Book>> books;

public:
    Library(int id, const std::string &name, const std::string &description, const std::string &address);

    ~Library() = default;

    int getId() const;

    std::string getName() const;

    std::string getDescription() const;

    std::string getAddress() const;

    const std::vector<std::shared_ptr<Book>> &getBooks() const;

    void setName(const std::string &name);

    void setDescription(const std::string &description);

    void setAddress(const std::string &address);

    void addBook(const std::shared_ptr<Book> &book);

    void removeBook(const std::shared_ptr<Book> &book);
};

#endif