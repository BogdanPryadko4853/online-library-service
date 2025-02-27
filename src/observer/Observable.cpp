#include "../../include/observer/Observable.h"

void Observable::addObserver(const std::shared_ptr<Observer>& observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(const std::shared_ptr<Observer>& observer) {
    auto it = std::remove(observers.begin(), observers.end(), observer);
    observers.erase(it, observers.end());
}

void Observable::notifyObservers(const std::string& message) const {
    for (const auto& observer : observers) {
        observer->update(message);
    }
}