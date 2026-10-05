// 2. Imagine a college hires some lecturers. Some lecturers are paid in period
// basis, while others are paid in month basis. Create a class called lecturer
// that stores the ID, and the name of lecturers. From this class derive two
// classes: PartTime, which adds payperhr (type float); and FullTime, which adds
// paypermonth (type float). Each of these three classes should have a
// readdata() function to get its data from the user, and a printdata() function
// to display its data. Write a main() program to test the FullTime and PartTime
// classes by creating instances of them, asking the user to fill in their data
// with readdata(), and then displaying the data with printdata().
#include <iostream>
#include <string>
class Lecturer { protected: int id; std::string name; public:
  void readdata() { std::cin >> id >> name; } void printdata() const { std::cout << id << ' ' << name; }
};
class PartTime : public Lecturer { float pay; public:
  void readdata() { Lecturer::readdata(); std::cin >> pay; }
  void printdata() const { Lecturer::printdata(); std::cout << ' ' << pay << '\n'; }
};
class FullTime : public Lecturer { float pay; public:
  void readdata() { Lecturer::readdata(); std::cin >> pay; }
  void printdata() const { Lecturer::printdata(); std::cout << ' ' << pay << '\n'; }
};
int main() { PartTime part; FullTime full; part.readdata(); full.readdata(); part.printdata(); full.printdata(); }
