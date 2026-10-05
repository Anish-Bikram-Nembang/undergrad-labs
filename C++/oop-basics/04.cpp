// 4. Create a class BankAccount with data members accountHolder, accountNumber,
// and balance. Include functions to deposit, withdraw, and display balance.
#include <iostream>
#include <string>
class BankAccount {
  std::string holder; long long number; double balance;
public:
  BankAccount(std::string h, long long n, double b = 0) : holder(h), number(n), balance(b) {}
  void deposit(double amount) { if (amount > 0) balance += amount; }
  bool withdraw(double amount) { if (amount < 0 || amount > balance) return false; balance -= amount; return true; }
  void display() const { std::cout << holder << ' ' << number << ' ' << balance << '\n'; }
};
int main() {
  std::string holder; long long number; double balance, deposit, withdrawal;
  std::cin >> holder >> number >> balance >> deposit >> withdrawal;
  BankAccount account(holder, number, balance); account.deposit(deposit); account.withdraw(withdrawal); account.display();
}
