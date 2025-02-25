#include "../../include/repositories/BookRepository.h"

//void BookRepository::addBook(const std::shared_ptr<Book>& book) {
//    books.push_back(book);
//}
//
//void BookRepository::removeBook(const std::shared_ptr<Book>& book) {
//    books.erase(
//            std::remove_if(
//                    books.begin(),
//                    books.end(),
//                    [&book](const std::shared_ptr<Book>& b) {
//                        return b->getId() == book->getId();
//                    }
//            ),
//            books.end()
//    );
//}
//
//std::shared_ptr<Book> BookRepository::findBookById(int id) const {
//    for (const auto& book : books) {
//        if (book->getId() == id) {
//            return book;
//        }
//    }
//    return nullptr;
//}
//
//std::vector<std::shared_ptr<Book>> BookRepository::getAllBooks() const {
//    return books;
//}