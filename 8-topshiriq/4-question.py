from abc import ABC, abstractmethod

# --- Интерфейсы (используем абстрактные базовые классы - ABC) ---

class IMovable(ABC):
    @abstractmethod
    def do_movement(self):
        pass

class IEnginePowered(ABC):
    @abstractmethod
    def start_engine(self):
        pass

class IFlyable(ABC):
    @abstractmethod
    def fly(self):
        pass

# --- Реализация (LSP и ISP) ---

class Bicycle(IMovable):
    def do_movement(self):
        print("Крутим педали")

class Car(IMovable, IEnginePowered):
    def __init__(self, engine):
        self._engine = engine # DIP: передаем объект двигателя

    def start_engine(self):
        self._engine.start()

    def do_movement(self):
        print("Едем по дороге")

class Plane(IMovable, IEnginePowered, IFlyable):
    def start_engine(self):
        print("Запуск турбин")

    def do_movement(self):
        print("Разгон по полосе")

    def fly(self):
        print("Взлет!")
