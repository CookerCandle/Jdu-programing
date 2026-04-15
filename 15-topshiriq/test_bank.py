import unittest

from repositories import InMemoryTransactionLogger, InMemoryUserRepository
from services import BankPaymentSystem


class BankPaymentSystemTests(unittest.TestCase):
    def setUp(self) -> None:
        self.user_repository = InMemoryUserRepository()
        self.transaction_logger = InMemoryTransactionLogger()
        self.payment_system = BankPaymentSystem(
            self.user_repository, self.transaction_logger
        )

    def test_register_user_with_initial_balance(self) -> None:
        user = self.payment_system.register_user("Ali", 100)

        self.assertEqual(user.username, "Ali")
        self.assertEqual(user.get_balance(), 100)
        self.assertEqual(len(user.get_history()), 1)
        self.assertEqual(len(self.transaction_logger.all()), 1)

    def test_deposit_increases_balance_and_logs_transaction(self) -> None:
        self.payment_system.register_user("Ali")

        transaction = self.payment_system.deposit("Ali", 50)
        user = self.payment_system.get_user("Ali")

        self.assertTrue(transaction.success)
        self.assertEqual(user.get_balance(), 50)
        self.assertEqual(len(user.get_history()), 1)
        self.assertEqual(self.transaction_logger.all()[-1], transaction)

    def test_transfer_moves_money_between_users(self) -> None:
        self.payment_system.register_user("Ali", 100)
        self.payment_system.register_user("Vali", 25)

        transaction = self.payment_system.transfer("Ali", "Vali", 40)

        sender = self.payment_system.get_user("Ali")
        receiver = self.payment_system.get_user("Vali")

        self.assertTrue(transaction.success)
        self.assertEqual(sender.get_balance(), 60)
        self.assertEqual(receiver.get_balance(), 65)
        self.assertEqual(len(sender.get_history()), 2)
        self.assertEqual(len(receiver.get_history()), 2)

    def test_transfer_more_than_balance_raises_and_does_not_change_balances(
        self,
    ) -> None:
        self.payment_system.register_user("Ali", 30)
        self.payment_system.register_user("Vali", 10)

        with self.assertRaises(ValueError):
            self.payment_system.transfer("Ali", "Vali", 50)

        sender = self.payment_system.get_user("Ali")
        receiver = self.payment_system.get_user("Vali")

        self.assertEqual(sender.get_balance(), 30)
        self.assertEqual(receiver.get_balance(), 10)
        self.assertEqual(len(sender.get_history()), 2)
        self.assertEqual(self.transaction_logger.all()[-1].success, False)

    def test_duplicate_usernames_are_rejected(self) -> None:
        self.payment_system.register_user("Ali")

        with self.assertRaises(ValueError):
            self.payment_system.register_user("ali")


if __name__ == "__main__":
    unittest.main()
