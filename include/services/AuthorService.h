#ifndef AUTHORSERVICE_H
#define AUTHORSERVICE_H

#include "Service.h"
#include "../repositories/AuthorRepository.h"
#include "../enteties/Author.h"
#include "../builder/AuthorBuilder.h"
#include <stdexcept>

class AuthorService : public Service<Author, AuthorRepository> {
public:
    explicit AuthorService(const std::shared_ptr<AuthorRepository>& repo)
            : Service(repo) {}

    void createAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio);
    void updateAuthor(int id, const std::string& firstName, const std::string& lastName, const std::string& bio);

    // Новые методы
    std::vector<std::shared_ptr<Author>> findAuthorsByName(const std::string& name) const;
    bool authorExists(int id) const;
};

#endif