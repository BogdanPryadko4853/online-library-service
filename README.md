# 🏛️ Online Library Service 
**REST API для управления библиотекой на C++ с использованием микрофреймворка Crow**

[![C++](https://img.shields.io/badge/C++-17/20-blue.svg)](https://isocpp.org/)
[![Crow](https://img.shields.io/badge/Crow-0.3%2B-orange.svg)](https://crowcpp.org/)
[![SQLite](https://img.shields.io/badge/SQLite-3-green.svg)](https://sqlite.org/)

## 📦 Особенности
- Полный CRUD для 5 сущностей: 
  - Авторы �
  - Книги 📚 
  - Библиотеки 🏛️
  - Пользователи 👤
  - Учёт выдачи 📆
- Валидация данных и обработка ошибок (400, 404, 500)
- Паттерны проектирования:
  - Singleton (Репозитории)
  - Observer (Логирование)
  - Builder (Создание объектов)
  - Strategy (Сервисный слой)
- Транзакции SQLite
- JSON-сериализация

## ⚙️ Установка
```bash
# 1. Клонировать репозиторий
git clone https://github.com/BogdanPryadko4853/online-library-service.git

# 2. Собрать проект
cd online-library-service
mkdir build && cd build
cmake .. && make

# 3. Запустить сервер
./online_library_service
