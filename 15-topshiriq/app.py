from __future__ import annotations

from typing import Optional

from models import UserAccount
from repositories import InMemoryTransactionLogger, InMemoryUserRepository
from services import BankPaymentSystem


class BankApp:
    def __init__(self) -> None:
        self._user_repository = InMemoryUserRepository()
        self._transaction_logger = InMemoryTransactionLogger()
        self._payment_system = BankPaymentSystem(
            self._user_repository,
            self._transaction_logger,
        )
        self._current_user: Optional[UserAccount] = None

    def run(self) -> None:
        while True:
            if self._current_user is None:
                self._show_guest_menu()
                choice = input("Tanlang: ").strip()
                if choice == "1":
                    self._register()
                elif choice == "2":
                    self._login()
                elif choice == "3":
                    self._show_all_users()
                elif choice == "0":
                    print("Dastur tugadi")
                    break
                else:
                    print("Noto'g'ri tanlov")
            else:
                self._show_user_menu()
                choice = input("Tanlang: ").strip()
                if choice == "1":
                    self._show_balance()
                elif choice == "2":
                    self._deposit()
                elif choice == "3":
                    self._transfer()
                elif choice == "4":
                    self._show_history()
                elif choice == "5":
                    self._logout()
                elif choice == "0":
                    print("Dastur tugadi")
                    break
                else:
                    print("Noto'g'ri tanlov")

    def _show_guest_menu(self) -> None:
        print("\n=== BANK ===")
        print("1. Yangi foydalanuvchi yaratish")
        print("2. Kabinetga kirish")
        print("3. Barcha foydalanuvchilar")
        print("0. Chiqish")

    def _show_user_menu(self) -> None:
        current_user = self._require_current_user()
        print(f"\n=== {current_user.username.upper()} KABINETI ===")
        print("1. Balansni ko'rish")
        print("2. Balans qo'shish")
        print("3. Pul yuborish")
        print("4. Operatsiyalar tarixi")
        print("5. Chiqish")
        print("0. Dasturdan chiqish")

    def _register(self) -> None:
        username = input("Ism kiriting: ").strip()
        try:
            initial_balance_text = input(
                "Boshlang'ich balans (ixtiyoriy, default 0): "
            ).strip()
            initial_balance = (
                float(initial_balance_text) if initial_balance_text else 0.0
            )
            user = self._payment_system.register_user(username, initial_balance)
            print(f"Foydalanuvchi yaratildi: {user.username}")
        except ValueError as error:
            print(f"Xatolik: {error}")

    def _login(self) -> None:
        username = input("Ismingizni kiriting: ").strip()
        try:
            self._current_user = self._payment_system.get_user(username)
            print(f"Xush kelibsiz, {self._current_user.username}")
        except ValueError as error:
            print(f"Xatolik: {error}")

    def _show_all_users(self) -> None:
        users = self._user_repository.list_all()
        if not users:
            print("Hali foydalanuvchi yo'q")
            return
        print("\nFoydalanuvchilar:")
        for user in users:
            print(f"- {user.username}")

    def _show_balance(self) -> None:
        current_user = self._require_current_user()
        print(f"Balans: {current_user.get_balance():.2f}")

    def _deposit(self) -> None:
        current_user = self._require_current_user()
        amount = self._read_amount("Qancha pul qo'shmoqchisiz: ")
        if amount is None:
            return
        try:
            transaction = self._payment_system.deposit(current_user.username, amount)
            print(transaction.describe())
        except ValueError as error:
            print(f"Xatolik: {error}")

    def _transfer(self) -> None:
        current_user = self._require_current_user()
        receiver = input("Qabul qiluvchi ismi: ").strip()
        amount = self._read_amount("Yuboriladigan summa: ")
        if amount is None:
            return
        try:
            transaction = self._payment_system.transfer(
                current_user.username,
                receiver,
                amount,
            )
            print(transaction.describe())
        except ValueError as error:
            print(f"Xatolik: {error}")

    def _show_history(self) -> None:
        current_user = self._require_current_user()
        history = current_user.get_history()
        if not history:
            print("Tarix bo'sh")
            return
        print("\nOperatsiyalar tarixi:")
        for item in history:
            print(item.describe())

    def _logout(self) -> None:
        current_user = self._require_current_user()
        print(f"{current_user.username} kabinetdan chiqdi")
        self._current_user = None

    def _require_current_user(self) -> UserAccount:
        if self._current_user is None:
            raise RuntimeError("Foydalanuvchi tizimga kirmagan")
        return self._current_user

    @staticmethod
    def _read_amount(prompt: str) -> float | None:
        try:
            return float(input(prompt).strip())
        except ValueError:
            print("Summani to'g'ri kiriting")
            return None
