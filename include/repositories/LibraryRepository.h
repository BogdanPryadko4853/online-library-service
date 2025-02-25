#ifndef LIBRARYREPOSITORY_H
#define LIBRARYREPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "../enteties/Library.h"
#include "Repository.h"

class LibraryRepository : Repository<Library> {
private:
    std::vector<std::shared_ptr<Library>> libraries;
};

#endif