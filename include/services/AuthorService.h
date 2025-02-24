#ifndef AUTHORSERVICE_H
#define AUTHORSERVICE_H

#include <memory>
#include <vector>
#include "../repositories/AuthorRepository.h"
#include "../enteties/Author.h"

class AuthorService {
private:
    std::shared_ptr<AuthorRepository> authorRepository;

public:
    explicit AuthorService(const std::shared_ptr<AuthorRepository>& repo);
    void createAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio);
    std::shared_ptr<Author> getAuthorById(int id) const;
    std::vector<std::shared_ptr<Author>> getAllAuthors() const;
    void updateAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio);
    void deleteAuthor(int id);
};

#endif