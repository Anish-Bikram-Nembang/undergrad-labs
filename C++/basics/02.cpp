// 2.Write a program that takes balance of a user’s account as input. It should
// then ask the user how much amount he wants to withdraw from his account. The
// program should take this amount as input and deduct from the balance.
// Similarly it should ask the user how much amount he wants to deposit in his
// account. It should take this amount as input and add to the balance. The
// program shall display the new balance after amount has been withdrawn and
// deposited. Note: Your program should have a check on balance and amount being
// withdrawn. Amounts greater than balance cannot be withdrawn i.e. balance
// cannot be negative.

#include <iostream>
#include <stdexcept>
#include <string>
class Account {
private:
  float balance;
  std::string name;

public:
  Account(std::string n, float b) : name{n}, balance{b} {}
  void displayDetails() {
    std::cout << "\nName: " << name << "\n Balance: " << balance << '\n';
  }
  void withdraw(float amount) {
    if (amount > balance)
      throw std::invalid_argument(
          "Amount to withdraw cannot be greater than total user balance");
    balance -= amount;
    std::cout << "nrs" << amount << " Successfully withdrawn!";
    std::cout << "Account details after amount withdrawn:\n";
    displayDetails();
  }
  void deposit(float amount) {
    balance += amount;
    std::cout << "nrs" << amount << " Successfully deposited!";
    std::cout << "Account details after amount deposited:\n";
    displayDetails();
  }
};
int main() {
  std::string name;
  float initialBalance;
  std::cout << "Enter name: ";
  std::getline(std::cin, name);
  std::cout << "Enter balance: ";
  std::cin >> initialBalance;
  Account a(name, initialBalance);

  try {
    float withdrawAmount;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> withdrawAmount;
    a.withdraw(withdrawAmount);

    float depositAmount;
    std::cout << "Enter amount to deposit: ";
    std::cin >> depositAmount;
    a.deposit(depositAmount);

  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what();
  }
  return 0;
}
