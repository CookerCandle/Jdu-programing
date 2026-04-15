from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from datetime import datetime
from typing import List


class BalanceOperations(ABC):
    @abstractmethod
    def get_balance(self) -> float:
        raise NotImplementedError

    @abstractmethod
    def deposit(self, amount: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def withdraw(self, amount: float) -> None:
        raise NotImplementedError


@dataclass(slots=True)
class Transaction:
    sender: str
    receiver: str
    amount: float
    created_at: datetime = field(default_factory=datetime.now)
    success: bool = True
    message: str = ""

    def describe(self) -> str:
        status = "SUCCESS" if self.success else "FAILED"
        timestamp = self.created_at.strftime("%Y-%m-%d %H:%M:%S")
        return (
            f"[{timestamp}] {status}: {self.sender} -> {self.receiver} | "
            f"{self.amount:.2f} | {self.message}"
        )


class UserAccount(BalanceOperations):
    def __init__(self, username: str, initial_balance: float = 0.0) -> None:
        self.__username = username.strip()
        self.__balance = 0.0
        self.__history: List[Transaction] = []
        if initial_balance:
            self.deposit(initial_balance)

    @property
    def username(self) -> str:
        return self.__username

    def get_balance(self) -> float:
        return self.__balance

    def deposit(self, amount: float) -> None:
        self._validate_amount(amount)
        self.__balance += amount

    def withdraw(self, amount: float) -> None:
        self._validate_amount(amount)
        if amount > self.__balance:
            raise ValueError("Недостаточно средств")
        self.__balance -= amount

    def add_transaction(self, transaction: Transaction) -> None:
        self.__history.append(transaction)

    def get_history(self) -> List[Transaction]:
        return list(self.__history)

    @staticmethod
    def _validate_amount(amount: float) -> None:
        if amount <= 0:
            raise ValueError("Сумма должна быть больше нуля")
