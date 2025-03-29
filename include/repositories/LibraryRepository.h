#ifndef LIBRARYREPOSITORY_H
#define LIBRARYREPOSITORY_H

#include "../enteties/Library.h"
#include "Repository.h"
#include "../observer/Observable.h"
#include <vector>
#include <memory>

class LibraryRepository : public Repository<Library>, public Observable {
private:
    LibraryRepository() = default;

    LibraryRepository(const LibraryRepository &) = delete;

    LibraryRepository &operator=(const LibraryRepository &) = delete;

    static std::shared_ptr<LibraryRepository> instance;

public:
    static std::shared_ptr<LibraryRepository> getInstance();

    void add(const std::shared_ptr<Library> &library) override;

    void remove(const std::shared_ptr<Library> &library) override;

    [[nodiscard]] std::shared_ptr<Library> findById(int id) const override;

    [[nodiscard]] std::vector<std::shared_ptr<Library>> getAll() const override;

    [[nodiscard]] std::vector<std::shared_ptr<Library>> findByName(const std::string &name) const;

    [[nodiscard]] std::vector<std::shared_ptr<Library>> findByAddress(const std::string &address) const;


    [[nodiscard]] bool exists(int id) const;

    [[nodiscard]] bool nameExists(const std::string &name) const;

};

#endif