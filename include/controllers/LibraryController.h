#ifndef LIBRARYCONTROLLER_H
#define LIBRARYCONTROLLER_H

#include <crow.h>
#include <memory>
#include "../services/LibraryService.h"

class LibraryController {
private:
    std::shared_ptr<LibraryService> libraryService;

public:
    explicit LibraryController(const std::shared_ptr<LibraryService>& service);
    void setupRoutes(crow::SimpleApp& app);
};

#endif