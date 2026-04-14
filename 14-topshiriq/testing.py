import pytest


class BankAccount:
    def __init__(self, initial_balance=0):
        self.__balance = initial_balance

    def deposit(self, amount):
        if amount < 0:
            raise ValueError("Сумма депозита не может быть отрицательной")
        self.__balance += amount

    def withdraw(self, amount):
        if amount <= self.__balance:
            self.__balance -= amount
        else:
            print("Недостаточно средств")

    def get_balance(self):
        return self.__balance

def test_account_initial_balance():
    # Arrange (Подготовка): создаем счет без денег
    account = BankAccount(initial_balance=0)
    
    # Act (Действие): в данном случае просто смотрим значение
    # Assert (Проверка): ожидаем, что баланс равен 0
    assert account.get_balance() == 0

def test_account_deposit():
    # Arrange (Подготовка): создаем счет и вносим деньги
    account = BankAccount(initial_balance=0)
    
    # Act (Действие): вносим 100 единиц на счет
    account.deposit(100)
    
    # Assert (Проверка): ожидаем, что баланс равен 100
    assert account.get_balance() == 100

def test_account_withdraw():
    # Arrange (Подготовка): создаем счет и вносим деньги
    account = BankAccount(initial_balance=100)

    # Act (Действие): снимаем 50 единиц с счета
    account.withdraw(50)

    # Assert (Проверка): ожидаем, что баланс равен 50
    assert account.get_balance() == 50

def test_account_deposit_add_negative_amount():
    # Arrange (Подготовка): создаем счет
    account = BankAccount(initial_balance=0)

    # Act (Действие): пытаемся внести отрицательную сумму
    pytest.raises(ValueError, account.deposit, -50)

    # Assert (Проверка): ожидаем, что баланс не изменился
    assert account.get_balance() == 0

def test_account_withdraw_insufficient_funds():
    # Arrange (Подготовка): создаем счет с определенным балансом
    account = BankAccount(initial_balance=50)

    # Act (Действие): пытаемся снять сумму, превышающую баланс
    account.withdraw(100)

    # Assert (Проверка): ожидаем, что баланс не изменился и выводится сообщение о недостатке средств
    assert account.get_balance() == 50