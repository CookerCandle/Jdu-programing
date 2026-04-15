from __future__ import annotations

from abc import ABC, abstractmethod
from typing import Dict, List, Optional

from models import Transaction, UserAccount


class UserRepository(ABC):
    @abstractmethod
    def add(self, user: UserAccount) -> None:
        raise NotImplementedError

    @abstractmethod
    def get_by_username(self, username: str) -> Optional[UserAccount]:
        raise NotImplementedError

    @abstractmethod
    def exists(self, username: str) -> bool:
        raise NotImplementedError

    @abstractmethod
    def list_all(self) -> List[UserAccount]:
        raise NotImplementedError


class InMemoryUserRepository(UserRepository):
    def __init__(self) -> None:
        self._users: Dict[str, UserAccount] = {}

    def add(self, user: UserAccount) -> None:
        self._users[user.username.lower()] = user

    def get_by_username(self, username: str) -> Optional[UserAccount]:
        return self._users.get(username.strip().lower())

    def exists(self, username: str) -> bool:
        return username.strip().lower() in self._users

    def list_all(self) -> List[UserAccount]:
        return list(self._users.values())


class TransactionLogger(ABC):
    @abstractmethod
    def log(self, transaction: Transaction) -> None:
        raise NotImplementedError

    @abstractmethod
    def all(self) -> List[Transaction]:
        raise NotImplementedError


class InMemoryTransactionLogger(TransactionLogger):
    def __init__(self) -> None:
        self._transactions: List[Transaction] = []

    def log(self, transaction: Transaction) -> None:
        self._transactions.append(transaction)

    def all(self) -> List[Transaction]:
        return list(self._transactions)
