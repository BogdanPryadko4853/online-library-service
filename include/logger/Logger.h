#ifndef LOGGER_H
#define LOGGER_H

#include "../observer/Observer.h"
#include <iostream>

class Logger : public Observer {
public:
    void update(const std::string& message) override;
};

#endif