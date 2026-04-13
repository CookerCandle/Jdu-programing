from abc import ABC, abstractmethod

# 1. Базовый интерфейс (Компонент)
class Pizza(ABC):
    @abstractmethod
    def get_cost(self) -> float:
        pass

    @abstractmethod
    def get_description(self) -> str:
        pass

# 2. Конкретный объект (Основа пиццы)
class PlainPizza(Pizza):
    def get_cost(self):
        return 500.0

    def get_description(self):
        return "Классическое тесто"

# 3. Базовый класс Декоратора (Обертка)
# Он сам является пиццей и содержит внутри себя другую пиццу
class PizzaDecorator(Pizza):
    def __init__(self, pizza: Pizza):
        self._wrapped_pizza = pizza

    def get_cost(self):
        return self._wrapped_pizza.get_cost()

    def get_description(self):
        return self._wrapped_pizza.get_description()

# 4. Конкретные декораторы (Добавки)
class CheeseDecorator(PizzaDecorator):
    def get_cost(self):
        return super().get_cost() + 100.0  # Цена базы + сыр

    def get_description(self):
        return super().get_description() + ", сыр"

class MushroomDecorator(PizzaDecorator):
    def get_cost(self):
        return super().get_cost() + 80.0   # Цена базы + грибы

    def get_description(self):
        return super().get_description() + ", грибы"

# --- Использование ---

# Заказываем пустую пиццу
my_pizza = PlainPizza()

# Добавляем сыр (оборачиваем)
my_pizza = CheeseDecorator(my_pizza)

# Добавляем еще сыр! (оборачиваем еще раз)
my_pizza = CheeseDecorator(my_pizza)

# Добавляем грибы
my_pizza = MushroomDecorator(my_pizza)

print(f"Заказ: {my_pizza.get_description()}")
print(f"Итого к оплате: {my_pizza.get_cost()} sum.")
