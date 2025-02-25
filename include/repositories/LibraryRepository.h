#ifndef LIBRARYREPOSITORY_H
#define LIBRARYREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Library.h"
#include "Repository.h"

class LibraryRepository : public  Repository<Library> {
private:
    std::vector<std::shared_ptr<Library>> libraries;
public:
    using Repository<Library>::add;
    using Repository<Library>::remove;
    using Repository<Library>::findById;
    using Repository<Library>::getAll;
};

#endif