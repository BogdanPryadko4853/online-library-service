#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>

template<typename T>
class Repository {
protected:
    std::vector<std::shared_ptr<T>> items;

public:
    virtual ~Repository() = default;

    void add(const std::shared_ptr<T> &item) {
        items.push_back(item);
    }

    void remove(const std::shared_ptr<T> &item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    std::shared_ptr<T> findById(int id) const {
        auto it = std::find_if(items.begin(), items.end(), [id](const std::shared_ptr<T> &item) {
            return item->getId() == id;
        });
        return (it != items.end()) ? *it : nullptr;
    }

    std::vector<std::shared_ptr<T>> getAll() const {
        return items;
    }
};

#endif