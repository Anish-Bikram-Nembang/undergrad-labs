// 3. Create a class Time with data members hours and minutes. Write a function
// to add two Time objects.
#include <iostream>
class Time {
  int hours, minutes;
public:
  Time(int h = 0, int m = 0) : hours(h + m / 60), minutes(m % 60) {}
  Time operator+(const Time &other) const { return {hours + other.hours, minutes + other.minutes}; }
  void display() const { std::cout << hours << " hours " << minutes << " minutes\n"; }
};
int main() { int h, m, h2, m2; std::cin >> h >> m >> h2 >> m2; (Time(h, m) + Time(h2, m2)).display(); }
