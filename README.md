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

📡 Примеры запросов

📖 Получить все книги
```curl
curl http://localhost:8080/books
```
```curl
[
  {
    "id": 1,
    "title": "Clean Code",
    "description": "Руководство по написанию читаемого кода",
    "authorId": 1
  }
]
```

🔍 Получить книгу по ID
```curl
curl http://localhost:8080/books/1
```
```curl
{
  "id": 1,
  "title": "Clean Code",
  "description": "Руководство по написанию читаемого кода",
  "authorId": 1
}
```
🖼️ Скриншоты работы

<img src="image/gm1.png" alt="">
<img src="image/gm1.png" alt="">
<img src="image/gm1.png" alt="">
<img src="image/gm1.png" alt="">
