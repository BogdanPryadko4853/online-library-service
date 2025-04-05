cmake_minimum_required(VERSION 3.30)
project(courseWork)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/bogda/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake")


add_library(sqlite STATIC sqlite/sqlite3.c)
target_include_directories(sqlite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/sqlite
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        C:/asio/asio-1.30.2/include
        C:/crow/include
)

link_directories("C:/curl/curl-8.12.1/lib")

# Собираем основной исполняемый файл
add_executable(courseWork
        main.cpp
        include/config/DatabaseManager.h
        src/config/DatabaseManager.cpp
        src/builder/LibraryBuilder.cpp
        src/builder/LoanBuilder.cpp
        src/builder/UserBuilder.cpp
        src/builder/AuthorBuilder.cpp
        src/builder/BookBuilder.cpp
        src/enteties/Book.cpp
        src/enteties/Library.cpp
        src/enteties/Loan.cpp
        src/enteties/User.cpp
        src/enteties/Author.cpp
        src/repositories/UserRepository.cpp
        src/repositories/BookRepository.cpp
        src/repositories/LoanRepository.cpp
        src/repositories/LibraryRepository.cpp
        src/repositories/AuthorRepository.cpp
        src/services/AuthorService.cpp
        src/services/BookService.cpp
        src/services/LibraryService.cpp
        src/controllers/AuthController.cpp
        src/controllers/BookController.cpp
        src/services/LoanService.cpp
        src/services/UserService.cpp
        src/controllers/LoanController.cpp
        src/controllers/LibraryController.cpp
        src/controllers/UserController.cpp
        src/observer/Observable.cpp
        src/logger/Logger.cpp
)

target_link_libraries(courseWork PRIVATE
        Ws2_32
        Mswsock
        sqlite
)