#ifndef SERVICE_H
#define SERVICE_H

#include <memory>
#include <vector>
#include <functional>

template <typename T, typename Repository>
class Service {
protected:
    std::shared_ptr<Repository> repository;

public:
    explicit Service(const std::shared_ptr<Repository>& repo) : repository(repo) {}
    virtual ~Service() = default;

    void create(const std::shared_ptr<T>& item) {
        repository->add(item);
    }

    std::shared_ptr<T> getById(int id) const {
        return repository->findById(id);
    }

    std::vector<std::shared_ptr<T>> getAll() const {
        return repository->getAll();
    }

    void update(int id, const std::function<void(std::shared_ptr<T>)>& updateFunction) {
        auto item = repository->findById(id);
        if (item) {
            updateFunction(item);
        }
    }

    void deleteById(int id) {
        auto item = repository->findById(id);
        if (item) {
            repository->remove(item);
        }
    }
};

#endif