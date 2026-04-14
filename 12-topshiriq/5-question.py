class RouteStrategy:
    def build_route(self, start, end):
        pass


class RoadStrategy(RouteStrategy):
    def build_route(self, start, end):
        return f"🚗 Едем по шоссе из {start} в {end}. Учитываем пробки и светофоры."

class WalkingStrategy(RouteStrategy):
    def build_route(self, start, end):
        return f"🚶 Идем пешком из {start} в {end}. Срезаем через парк и дворы."

class PublicTransportStrategy(RouteStrategy):
    def build_route(self, start, end):
        return f"🚌 Маршрут из {start} в {end} на автобусе. Ждем на остановке 10 минут."


class Navigator:
    def __init__(self, strategy: RouteStrategy):
        self._strategy = strategy # Устанавливаем стратегию при создании

    def set_strategy(self, strategy: RouteStrategy):
        self._strategy = strategy # Позволяет сменить транспорт на ходу

    def show_route(self, start, end):
        # Навигатору плевать, какой там транспорт, он просто жмет "старт"
        result = self._strategy.build_route(start, end)
        print(result)


# 1. Создаем навигатор и сразу ставим стратегию "На машине"
my_navigator = Navigator(RoadStrategy())
my_navigator.show_route("Дом", "Офис")

# 2. Машина сломалась! Переключаемся на "Пешком" прямо на ходу
my_navigator.set_strategy(WalkingStrategy())
my_navigator.show_route("Дом", "Офис")

# 3. Устали идти? Выбираем "Автобус"
my_navigator.set_strategy(PublicTransportStrategy())
my_navigator.show_route("Дом", "Офис")
