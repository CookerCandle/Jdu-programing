# 1. То, что у нас уже есть (Старая система в суммах)
class OldPizzaSystem:
    def get_price_rub(self):
        return 25000  # Цена в суммах

# 2. То, что хочет внешняя система (Интерфейс в долларах)
class USAPaymentSystem:
    def receive_payment_usd(self, amount_usd):
        print(f"Оплата принята: ${amount_usd:.2f}")

# 3. АДАПТЕР — мост между суммами и долларами
class PaymentAdapter:
    def __init__(self, old_system: OldPizzaSystem, exchange_rate: float):
        self.old_system = old_system
        self.exchange_rate = exchange_rate

    def get_price_usd(self):
        # Берем суммы из старой системы и конвертируем
        price_rub = self.old_system.get_price_rub()
        return price_rub / self.exchange_rate

# --- Использование ---

# У нас есть старая система
my_pizza_shop = OldPizzaSystem()

# Нам нужно оплатить через американскую систему (курс 1$ = 10000 sum)
adapter = PaymentAdapter(my_pizza_shop, exchange_rate=10000.0)

# Внешняя система оплаты
payment_gateway = USAPaymentSystem()

# Теперь мы можем передать данные из старой системы в новую через адаптер
price_in_usd = adapter.get_price_usd()
payment_gateway.receive_payment_usd(price_in_usd)
