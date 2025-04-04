#include "../../include/repositories/BookRepository.h"
#include "../../include/config/DatabaseManager.h"
#include <algorithm>

std::shared_ptr<BookRepository> BookRepository::instance = nullptr;

std::shared_ptr<BookRepository> BookRepository::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<BookRepository>(new BookRepository());
    }
    return instance;
}

void BookRepository::add(const std::shared_ptr<Book> &book) {
    if (!book) {
        throw std::invalid_argument("Cannot add null book");
    }
    if (exists(book->getId())) {
        throw std::runtime_error("Book with this ID already exists");
    }
    if (titleExists(book->getTitle())) {
        throw std::runtime_error("Book with this title already exists");
    }

    auto& db = DatabaseManager::getInstance();
    std::string sql = "INSERT INTO books (title, description, author_id) VALUES (?, ?, ?)";

    if (!db.executeWithParams(sql, {
            book->getTitle(),
            book->getDescription(),
            std::to_string(book->getAuthorId())
    })) {
        throw std::runtime_error("Failed to add book to database");
    }

    notifyObservers("Added book: ID=" + std::to_string(book->getId()) +
                    ", Title=" + book->getTitle());
}

void BookRepository::remove(const std::shared_ptr<Book> &book) {
    if (!book || !exists(book->getId())) {
        throw std::runtime_error("Book not found");
    }

    auto& db = DatabaseManager::getInstance();
    std::string sql = "DELETE FROM books WHERE id = ?";

    if (!db.executeWithParams(sql, {std::to_string(book->getId())})) {
        throw std::runtime_error("Failed to remove book from database");
    }

    notifyObservers("Removed book: ID=" + std::to_string(book->getId()));
}

std::shared_ptr<Book> BookRepository::findById(int id) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT * FROM books WHERE id = " + std::to_string(id));

    if (result.empty()) {
        return nullptr;
    }

    auto row = result[0];
    auto book = std::make_shared<Book>(
            std::stoi(row[0]),  // id
            row[1],             // title
            row[2],             // description
            std::stoi(row[3])   // author_id
    );

    notifyObservers("Found book with id " + std::to_string(id));
    return book;
}

std::vector<std::shared_ptr<Book>> BookRepository::getAll() const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT * FROM books");

    std::vector<std::shared_ptr<Book>> books;
    for (const auto& row : result) {
        books.push_back(std::make_shared<Book>(
                std::stoi(row[0]), row[1], row[2], std::stoi(row[3])
        ));
    }

    notifyObservers("Retrieved all books (count: " + std::to_string(books.size()) + ")");
    return books;
}

std::vector<std::shared_ptr<Book>> BookRepository::findByTitle(const std::string &title) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT * FROM books WHERE title LIKE '%" + title + "%'"
    );

    std::vector<std::shared_ptr<Book>> books;
    for (const auto& row : result) {
        books.push_back(std::make_shared<Book>(
                std::stoi(row[0]), row[1], row[2], std::stoi(row[3])
        ));
    }

    notifyObservers("Search by title: '" + title + "' found " + std::to_string(books.size()) + " books");
    return books;
}

std::vector<std::shared_ptr<Book>> BookRepository::findByAuthor(int authorId) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT * FROM books WHERE author_id = " + std::to_string(authorId)
    );

    std::vector<std::shared_ptr<Book>> books;
    for (const auto& row : result) {
        books.push_back(std::make_shared<Book>(
                std::stoi(row[0]), row[1], row[2], std::stoi(row[3])
        ));
    }

    notifyObservers("Search by author ID: " + std::to_string(authorId) +
                    " found " + std::to_string(books.size()) + " books");
    return books;
}

bool BookRepository::exists(int id) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query("SELECT 1 FROM books WHERE id = " + std::to_string(id));
    return !result.empty();
}

bool BookRepository::titleExists(const std::string &title) const {
    auto& db = DatabaseManager::getInstance();
    auto result = db.query(
            "SELECT 1 FROM books WHERE title = '" + title + "'"
    );
    return !result.empty();
}