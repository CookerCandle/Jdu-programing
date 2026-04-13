from abc import ABC, abstractmethod

# 1. Абстрактный продукт (что мы готовим?)
class Pizza(ABC):
    @abstractmethod
    def prepare(self):
        pass

# 2. Конкретные продукты (виды пиццы)
class Margherita(Pizza):
    def prepare(self):
        return "Готовим Маргариту: томаты, моцарелла, базилик. 🧀"

class Pepperoni(Pizza):
    def prepare(self):
        return "Готовим Пепперони: острые колбаски, много сыра. 🍕"

class FourCheese(Pizza):
    def prepare(self):
        return "Готовим Четыре сыра: дорблю, чеддер, пармезан, моцарелла. 🧀🧀"

# 3. Singleton Factory (Единственная кухня пиццерии)
class PizzaFactory:
    _instance = None

    # Реализация Singleton
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(PizzaFactory, cls).__new__(cls)
            # Инициализация "оборудования" кухни
            cls._instance.oven_temperature = 450 #type: ignore
        return cls._instance

    # Метод Фабрики
    def order_pizza(self, pizza_type: str) -> Pizza:
        menu = {
            "маргарита": Margherita,
            "пепперони": Pepperoni,
            "четыре сыра": FourCheese
        }
        
        pizza_class = menu.get(pizza_type.lower())
        
        if pizza_class:
            pizza = pizza_class()
            print(f"[Кухня] Температура печи: {self.oven_temperature}°C") #type: ignore
            return pizza
        
        raise ValueError("Такой пиццы нет в меню!")

# --- Работа пиццерии ---

# Создаем "точки доступа" к кухне в разных частях программы
kitchen_terminal_1 = PizzaFactory()
kitchen_terminal_2 = PizzaFactory()

# Проверяем, что кухня одна и та же (Singleton)
print(f"Это одна и та же кухня? {kitchen_terminal_1 is kitchen_terminal_2}") # True

# Делаем заказы (Factory)
my_pizza = kitchen_terminal_1.order_pizza("пепперони")
print(my_pizza.prepare())

friend_pizza = kitchen_terminal_2.order_pizza("маргарита")
print(friend_pizza.prepare())
