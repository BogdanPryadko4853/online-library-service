#ifndef COURSEWORK_BOOK_H
#define COURSEWORK_BOOK_H

#include <string>
#include <vector>
#include <memory>

class Library;

class Book {
private:
    int id;
    std::string title;
    std::string description;
    int authorId;
    std::vector<std::shared_ptr<Library>> libraries;

public:
    Book(int id, const std::string& title, const std::string& description, int authorId);
    ~Book() = default;

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    int getAuthorId() const;
    const std::vector<std::shared_ptr<Library>>& getLibraries() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);

    void addLibrary(const std::shared_ptr<Library>& library);
    void removeLibrary(const std::shared_ptr<Library>& library);
};

#endif