#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.h"

class Observable {
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    virtual ~Observable() = default;

    void addObserver(const std::shared_ptr<Observer> &observer);

    void removeObserver(const std::shared_ptr<Observer> &observer);

    void notifyObservers(const std::string &message) const;
};

#endif