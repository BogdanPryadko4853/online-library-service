#ifndef LIBRARYREPOSITORY_H
#define LIBRARYREPOSITORY_H

#include "../enteties/Library.h"
#include "Repository.h"
#include "../observer/Observable.h"

class LibraryRepository : public Repository<Library> ,public Observable{
private:
    LibraryRepository() = default;

    LibraryRepository(const LibraryRepository &) = delete;

    LibraryRepository &operator=(const LibraryRepository &) = delete;

    static std::shared_ptr<LibraryRepository> instance;

public:
    static std::shared_ptr<LibraryRepository> getInstance() {
        if (!instance) {
            instance = std::shared_ptr<LibraryRepository>(new LibraryRepository());
        }
        return instance;
    }

    std::shared_ptr<Library> findById(int id) const override;

    std::vector<std::shared_ptr<Library>> getAll() const override;

};

#endif