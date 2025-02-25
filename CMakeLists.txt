cmake_minimum_required(VERSION 3.30)
project(courseWork)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        C:/asio/asio-1.30.2/include
        C:/crow/include
)

add_executable(courseWork main.cpp
        include/enteties/Book.h
        src/enteties/Book.cpp
        include/enteties/Loan.h
        include/enteties/Author.h
        include/enteties/User.h
        include/enteties/Library.h
        src/enteties/Library.cpp
        src/enteties/Loan.cpp
        src/enteties/User.cpp
        src/enteties/Author.cpp
        include/repositories/BookRepository.h
        include/repositories/LoanRepository.h
        include/repositories/UserRepository.h
        include/repositories/AuthorRepository.h
        include/repositories/LibraryRepository.h
        src/repositories/UserRepository.cpp
        src/repositories/BookRepository.cpp
        src/repositories/LoanRepository.cpp
        src/repositories/LibraryRepository.cpp
        src/repositories/AuthorRepository.cpp
        include/services/AuthorService.h
        src/services/AuthorService.cpp
        include/services/BookService.h
        src/services/BookService.cpp
        include/services/LibraryService.h
        src/services/LibraryService.cpp
        include/controllers/AuthController.h
        src/controllers/AuthController.cpp
        include/controllers/BookController.h
        src/controllers/BookController.cpp
        include/services/LoanSerivce.h
        include/services/UserService.h
        src/services/LoanService.cpp
        src/services/UserService.cpp
        src/controllers/LoanController.cpp
        src/controllers/LibraryController.cpp
        src/controllers/UserController.cpp
        include/controllers/LibraryController.h
        include/controllers/LoanController.h
        include/controllers/UserController.h
        include/repositories/Repository.h)

target_link_libraries(courseWork Ws2_32 Mswsock)
