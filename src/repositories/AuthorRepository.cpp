#include "../../include/repositories/AuthorRepository.h"

//
//void AuthorRepository::add(const std::shared_ptr<Author> &item) {
//    authors.push_back(item);
//}
//
//void AuthorRepository::removeAuthor(const std::shared_ptr<Author>& author) {
//    authors.erase(
//            std::remove_if(
//                    authors.begin(),
//                    authors.end(),
//                    [&author](const std::shared_ptr<Author>& a) {
//                        return a->getId() == author->getId();
//                    }
//            ),
//            authors.end()
//    );
//}
//
//std::shared_ptr<Author> AuthorRepository::findAuthorById(int id) const {
//    for (const auto& author : authors) {
//        if (author->getId() == id) {
//            return author;
//        }
//    }
//    return nullptr;
//}
//
//std::vector<std::shared_ptr<Author>> AuthorRepository::getAllAuthors() const {
//    return authors;
//}