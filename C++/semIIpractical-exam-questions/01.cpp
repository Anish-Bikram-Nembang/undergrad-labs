#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
  int accountNumber;
  string holderName;
  float balance;

public:
  BankAccount(int a, string n, float b)
      : accountNumber{a}, holderName{n}, balance{b} {}
  ~BankAccount() { cout << "Account closed\n"; }
};
int main(void) {
  BankAccount personal(1, "Anish", 1000.0f);
  return 0;
}
