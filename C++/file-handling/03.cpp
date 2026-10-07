// 3. Create a BankAccount class with the following attributes:
// Account number
// Account holder name
// Balance
// Implement functions for:
// Deposit
// Withdrawal
// Display balance
// Store transaction details in a file.
// Exception requirement: Handle exceptions for:
// Insufficient balance
// Negative deposit
// Invalid withdrawal amount
#include <fstream>
#include <iostream>
#include <stdexcept>
class BankAccount {
  double balance;
  std::ofstream log;

public:
  BankAccount(double b) : balance(b), log("transactions.txt", std::ios::app) {
    if (b < 0 || !log)
      throw std::runtime_error("invalid account");
  }
  void deposit(double a) {
    if (a < 0)
      throw std::invalid_argument("negative deposit");
    balance += a;
    log << "deposit " << a << '\n';
  }
  void withdraw(double a) {
    if (a <= 0)
      throw std::invalid_argument("invalid withdrawal");
    if (a > balance)
      throw std::runtime_error("insufficient balance");
    balance -= a;
    log << "withdraw " << a << '\n';
  }
  void display() const { std::cout << balance << '\n'; }
};
int main() {
  try {
    BankAccount account(100);
    account.deposit(25);
    account.withdraw(50);
    account.display();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
