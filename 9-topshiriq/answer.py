from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import Dict, List, Optional


# =========================
# Доменные модели
# =========================


@dataclass
class Book:
    id: int
    title: str
    author: str


@dataclass
class User:
    id: int
    name: str
    email: str


@dataclass
class RentalRecord:
    book_id: int
    user_id: int


# =========================
# Абстракции (контракты)
# =========================


class BookRepository(ABC):
    @abstractmethod
    def add(self, book: Book) -> None:
        pass

    @abstractmethod
    def remove(self, book_id: int) -> None:
        pass

    @abstractmethod
    def get_by_id(self, book_id: int) -> Optional[Book]:
        pass

    @abstractmethod
    def list_all(self) -> List[Book]:
        pass


class UserRepository(ABC):
    @abstractmethod
    def register(self, user: User) -> None:
        pass

    @abstractmethod
    def add(self, user: User) -> None:
        pass

    @abstractmethod
    def remove(self, user_id: int) -> None:
        pass

    @abstractmethod
    def get_by_id(self, user_id: int) -> Optional[User]:
        pass

    @abstractmethod
    def list_all(self) -> List[User]:
        pass


class RentalRepository(ABC):
    @abstractmethod
    def create_rental(self, book_id: int, user_id: int) -> None:
        pass

    @abstractmethod
    def close_rental(self, book_id: int) -> None:
        pass

    @abstractmethod
    def get_renter_id(self, book_id: int) -> Optional[int]:
        pass

    @abstractmethod
    def list_active(self) -> List[RentalRecord]:
        pass


class Notifier(ABC):
    @abstractmethod
    def notify_book_received(self, user: User, book: Book) -> None:
        pass

    @abstractmethod
    def notify_book_returned(self, user: User, book: Book) -> None:
        pass


class ReportGenerator(ABC):
    @abstractmethod
    def generate_active_rentals_report(self) -> str:
        pass


# =========================
# Реализации инфраструктуры
# =========================


class InMemoryBookRepository(BookRepository):
    def __init__(self) -> None:
        self._books: Dict[int, Book] = {}

    def add(self, book: Book) -> None:
        self._books[book.id] = book

    def remove(self, book_id: int) -> None:
        self._books.pop(book_id, None)

    def get_by_id(self, book_id: int) -> Optional[Book]:
        return self._books.get(book_id)

    def list_all(self) -> List[Book]:
        return list(self._books.values())


class InMemoryUserRepository(UserRepository):
    def __init__(self) -> None:
        self._users: Dict[int, User] = {}

    def register(self, user: User) -> None:
        # SRP: этот класс отвечает только за хранение/получение пользователей.
        self._users[user.id] = user

    def add(self, user: User) -> None:
        self._users[user.id] = user

    def remove(self, user_id: int) -> None:
        self._users.pop(user_id, None)

    def get_by_id(self, user_id: int) -> Optional[User]:
        return self._users.get(user_id)

    def list_all(self) -> List[User]:
        return list(self._users.values())


class InMemoryRentalRepository(RentalRepository):
    def __init__(self) -> None:
        self._active_rentals: Dict[int, int] = {}

    def create_rental(self, book_id: int, user_id: int) -> None:
        self._active_rentals[book_id] = user_id

    def close_rental(self, book_id: int) -> None:
        self._active_rentals.pop(book_id, None)

    def get_renter_id(self, book_id: int) -> Optional[int]:
        return self._active_rentals.get(book_id)

    def list_active(self) -> List[RentalRecord]:
        return [
            RentalRecord(book_id=book_id, user_id=user_id)
            for book_id, user_id in self._active_rentals.items()
        ]


class ConsoleNotifier(Notifier):
    def notify_book_received(self, user: User, book: Book) -> None:
        print(f"[УВЕДОМЛЕНИЕ] {user.name} получил(а) книгу '{book.title}'.")

    def notify_book_returned(self, user: User, book: Book) -> None:
        print(f"[УВЕДОМЛЕНИЕ] {user.name} вернул(а) книгу '{book.title}'.")


# =========================
# Сервисы (бизнес-логика)
# =========================


class LibraryService:
    """
    Этот сервис демонстрирует несколько принципов SOLID:

    1) SRP (Single Responsibility Principle)
       Сервис занимается только сценариями библиотеки (выдать/принять книгу).
       Хранение данных и уведомления делегированы другим классам.

    2) OCP (Open/Closed Principle)
       Для добавления нового типа уведомлений (email, telegram) или нового
       типа репозитория (SQL, API) этот класс менять не нужно.
       Достаточно подставить новую реализацию абстракции.

    3) LSP (Liskov Substitution Principle)
       Любую реализацию BookRepository/UserRepository/RentalRepository/Notifier
       можно подставить вместо текущей без поломки логики сервиса.

    4) ISP (Interface Segregation Principle)
       Контракты разделены: Notifier отвечает только за уведомления,
       репозитории только за свои операции.

    5) DIP (Dependency Inversion Principle)
       Сервис зависит от абстракций (интерфейсов), а не от конкретных
       InMemory-классов.
    """

    def __init__(
        self,
        book_repo: BookRepository,
        user_repo: UserRepository,
        rental_repo: RentalRepository,
        notifier: Notifier,
    ) -> None:
        self._book_repo = book_repo
        self._user_repo = user_repo
        self._rental_repo = rental_repo
        self._notifier = notifier

    def rent_book_to_user(self, book_id: int, user_id: int) -> None:
        book = self._book_repo.get_by_id(book_id)
        user = self._user_repo.get_by_id(user_id)

        if book is None:
            print(f"Книга с id={book_id} не найдена.")
            return
        if user is None:
            print(f"Пользователь с id={user_id} не найден.")
            return
        if self._rental_repo.get_renter_id(book_id) is not None:
            print(f"Книга '{book.title}' уже выдана.")
            return

        self._rental_repo.create_rental(book_id=book_id, user_id=user_id)
        self._notifier.notify_book_received(user=user, book=book)

    def return_book(self, book_id: int) -> None:
        renter_id = self._rental_repo.get_renter_id(book_id)
        if renter_id is None:
            print(f"Книга с id={book_id} не находится в аренде.")
            return

        book = self._book_repo.get_by_id(book_id)
        user = self._user_repo.get_by_id(renter_id)

        if book is None or user is None:
            print("Ошибка данных: книга или пользователь не найдены.")
            return

        self._rental_repo.close_rental(book_id)
        self._notifier.notify_book_returned(user=user, book=book)


class ActiveRentalsReportGenerator(ReportGenerator):
    # SRP: этот класс отвечает только за формирование отчета.
    def __init__(
        self,
        rental_repo: RentalRepository,
        book_repo: BookRepository,
        user_repo: UserRepository,
    ) -> None:
        self._rental_repo = rental_repo
        self._book_repo = book_repo
        self._user_repo = user_repo

    def generate_active_rentals_report(self) -> str:
        active = self._rental_repo.list_active()
        if not active:
            return "Отчет: сейчас нет книг, выданных в аренду."

        lines = ["Отчет по выданным книгам:"]
        for record in active:
            book = self._book_repo.get_by_id(record.book_id)
            user = self._user_repo.get_by_id(record.user_id)
            if book is None or user is None:
                lines.append(f"- Некорректная запись аренды: {record}")
            else:
                lines.append(
                    f"- Книга '{book.title}' (id={book.id}) выдана пользователю "
                    f"{user.name} (id={user.id})"
                )
        return "\n".join(lines)


def demo() -> None:
    # Компоновка зависимостей (DIP): high-level модули получают абстракции,
    # а конкретные реализации подставляются снаружи.
    book_repo = InMemoryBookRepository()
    user_repo = InMemoryUserRepository()
    rental_repo = InMemoryRentalRepository()
    notifier = ConsoleNotifier()

    library_service = LibraryService(
        book_repo=book_repo,
        user_repo=user_repo,
        rental_repo=rental_repo,
        notifier=notifier,
    )

    report_generator = ActiveRentalsReportGenerator(
        rental_repo=rental_repo,
        book_repo=book_repo,
        user_repo=user_repo,
    )

    # Управление книгами (добавление/удаление)
    book_repo.add(Book(id=1, title="Clean Code", author="Robert C. Martin"))
    book_repo.add(Book(id=2, title="The Pragmatic Programmer", author="Andrew Hunt"))
    book_repo.remove(999)  # Демонстративно: удаление несуществующей книги.

    # Управление пользователями (регистрация/добавление/удаление)
    user_repo.register(User(id=101, name="Ali", email="ali@example.com"))
    user_repo.add(User(id=102, name="Malika", email="malika@example.com"))
    user_repo.remove(999)  # Демонстративно: удаление несуществующего пользователя.

    # Управление арендой (дать и принять обратно)
    library_service.rent_book_to_user(book_id=1, user_id=101)
    library_service.rent_book_to_user(book_id=2, user_id=102)
    print(report_generator.generate_active_rentals_report())

    library_service.return_book(book_id=1)
    print(report_generator.generate_active_rentals_report())


if __name__ == "__main__":
    demo()
