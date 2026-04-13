from abc import abstractmethod, ABC

class Teach(ABC):
    @abstractmethod
    def teach(self):
        pass

class Examine(ABC):
    @abstractmethod
    def examine(self):
        pass

class Build(ABC):
    @abstractmethod
    def build(self):
        pass

# --- Реализация ---
class Teacher(Teach):
    def teach(self):
        print("Преподаю предмет")

class Doctor(Examine):
    def examine(self):
        print("Провожу обследование")

class Engineer(Build):
    def build(self):
        print("Строю здание")