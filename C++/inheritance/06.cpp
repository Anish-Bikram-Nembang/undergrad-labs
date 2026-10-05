// 6. Explain IS-A relationship and HAS-A relationship with a suitable example.
#include <iostream>
class Engine { public: void start() const { std::cout << "engine started\n"; } };
class Vehicle { Engine engine; public: void start() const { engine.start(); } };
class Car : public Vehicle {};
int main() { Car car; car.start(); }
