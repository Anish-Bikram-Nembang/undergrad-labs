// 3. An industry seals lorry and taxi. Create a class Automobile that stores
// production date and price. From this class derive another two classes: Lorry,
// which adds weight capacity in kilogram and Taxi, which adds seat-capacity in
// number. Each of these classes should have member functions to get data and
// set data. Use user-defined constructors to initialize these objects.
#include <iostream>
#include <string>
class Automobile { protected: std::string date; double price; public: Automobile(std::string d, double p) : date(d), price(p) {} };
class Lorry : public Automobile { double capacity; public: Lorry(std::string d, double p, double c) : Automobile(d, p), capacity(c) {} void display() const { std::cout << date << ' ' << price << ' ' << capacity << '\n'; } };
class Taxi : public Automobile { int seats; public: Taxi(std::string d, double p, int s) : Automobile(d, p), seats(s) {} void display() const { std::cout << date << ' ' << price << ' ' << seats << '\n'; } };
int main() { Lorry lorry("2026-01-01", 100000, 5000); Taxi taxi("2026-01-01", 30000, 4); lorry.display(); taxi.display(); }
