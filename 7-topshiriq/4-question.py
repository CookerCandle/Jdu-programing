# SRP (Single Responsibility Principle) - Принцип единственной ответственности
class ListSearcher:
    def find_index(self, data_list, target):
        return f"Поиск {target} в списке..."

class ListCopier:
    def duplicate(self, data_list):
        return "Создание глубокой копии списка..."

class ListReverser:
    def reverse(self, data_list):
        return "Разворот порядка элементов..."

class ListSplitter:
    def split(self, data_list, chunk_size):
        return f"Разделение списка на части по {chunk_size}..."
    
# not SRP
class ListManager:
    def find_index(self, data_list, target):
        return f"Поиск {target} в списке..."
    
    def duplicate(self, data_list):
        return "Создание глубокой копии списка..."
    
    def reverse(self, data_list):
        return "Разворот порядка элементов..."
    
    def split(self, data_list, chunk_size):
        return f"Разделение списка на части по {chunk_size}..."