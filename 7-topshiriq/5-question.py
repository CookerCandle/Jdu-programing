class IModel:
    def get_specs(self):
        pass

# Конкретная модель X
class IphoneX(IModel):
    def __init__(self):
        # Мы сами определяем характеристики внутри модели
        self.processor = "A11 Bionic"
        self.display = "OLED"
        self.ram = "3GB"

    def get_specs(self):
        return f"iPhone X: {self.processor}, {self.display}, {self.ram}"

# Конкретная модель XR
class IphoneXR(IModel):
    def __init__(self):
        self.processor = "A12 Bionic"
        self.display = "LCD"
        self.ram = "3GB"

    def get_specs(self):
        return f"iPhone XR: {self.processor}, {self.display}, {self.ram}"

class Iphone:
    def __init__(self, model: IModel):
        self.model = model

    def show_info(self):
        print(self.model.get_specs())
