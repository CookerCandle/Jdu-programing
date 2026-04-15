from __future__ import annotations

from abc import ABC, abstractmethod

from models import Transaction, UserAccount
from repositories import TransactionLogger, UserRepository


class PaymentSystem(ABC):
    @abstractmethod
    def register_user(self, username: str, initial_balance: float = 0.0) -> UserAccount:
        raise NotImplementedError

    @abstractmethod
    def get_user(self, username: str) -> UserAccount:
        raise NotImplementedError

    @abstractmethod
    def deposit(self, username: str, amount: float) -> Transaction:
        raise NotImplementedError

    @abstractmethod
    def transfer(
        self, sender_username: str, receiver_username: str, amount: float
    ) -> Transaction:
        raise NotImplementedError


class BankPaymentSystem(PaymentSystem):
    def __init__(
        self, user_repository: UserRepository, transaction_logger: TransactionLogger
    ) -> None:
        self._user_repository = user_repository
        self._transaction_logger = transaction_logger

    def register_user(self, username: str, initial_balance: float = 0.0) -> UserAccount:
        normalized_username = username.strip()
        if not normalized_username:
            raise ValueError("Имя пользователя не может быть пустым")
        if self._user_repository.exists(normalized_username):
            raise ValueError("Пользователь с таким именем уже существует")

        user = UserAccount(normalized_username, initial_balance)
        self._user_repository.add(user)
        if initial_balance > 0:
            transaction = Transaction(
                sender="SYSTEM",
                receiver=user.username,
                amount=initial_balance,
                success=True,
                message="Initial deposit",
            )
            user.add_transaction(transaction)
            self._transaction_logger.log(transaction)
        return user

    def get_user(self, username: str) -> UserAccount:
        user = self._user_repository.get_by_username(username)
        if user is None:
            raise ValueError("Пользователь не найден")
        return user

    def deposit(self, username: str, amount: float) -> Transaction:
        user = self.get_user(username)
        user.deposit(amount)
        transaction = Transaction(
            sender="SYSTEM",
            receiver=user.username,
            amount=amount,
            success=True,
            message="Deposit completed",
        )
        self._transaction_logger.log(transaction)
        user.add_transaction(transaction)
        return transaction

    def transfer(
        self, sender_username: str, receiver_username: str, amount: float
    ) -> Transaction:
        sender = self.get_user(sender_username)
        receiver = self.get_user(receiver_username)

        if sender.username.lower() == receiver.username.lower():
            raise ValueError("Нельзя переводить деньги самому себе")

        if amount <= 0:
            raise ValueError("Сумма должна быть больше нуля")

        if amount > sender.get_balance():
            transaction = Transaction(
                sender=sender.username,
                receiver=receiver.username,
                amount=amount,
                success=False,
                message="Недостаточно средств",
            )
            sender.add_transaction(transaction)
            self._transaction_logger.log(transaction)
            raise ValueError("Недостаточно средств")

        sender.withdraw(amount)
        receiver.deposit(amount)

        transaction = Transaction(
            sender=sender.username,
            receiver=receiver.username,
            amount=amount,
            success=True,
            message="Transfer completed",
        )
        sender.add_transaction(transaction)
        receiver.add_transaction(transaction)
        self._transaction_logger.log(transaction)
        return transaction
