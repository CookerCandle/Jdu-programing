class BankAccount:
    def __init__(self, initial_balance=0):
        self.balance = initial_balance

    def deposit(self, amount):
        self.balance += amount

def test_account_initial_balance():
    # Arrange (Подготовка): создаем счет без денег
    account = BankAccount(initial_balance=0)
    
    # Act (Действие): в данном случае просто смотрим значение
    # Assert (Проверка): ожидаем, что баланс равен 0
    assert account.balance == 0

def test_account_deposit():
    # Arrange (Подготовка): создаем счет и вносим деньги
    account = BankAccount(initial_balance=0)
    
    # Act (Действие): вносим 100 единиц на счет
    account.deposit(100)
    
    # Assert (Проверка): ожидаем, что баланс равен 100
    assert account.balance == 100