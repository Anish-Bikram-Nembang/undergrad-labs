// 1. Create a C++ program using a Student class with attributes such as rollNo,
// name, and marks. Implement functions to: Accept student details. Display
// student details. Write student records to a file. Read and display all
// student records from the file. Use appropriate file handling classes such as
// ofstream and ifstream.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Student {
private:
  int rollNo;
  string name;
  float marks;

public:
  void getDetails() {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter roll no: ";
    cin >> rollNo;
    cout << "Enter marks: ";
    cin >> marks;
  }
  void displayDetails() {
    cout << "Name: " << name << "\n";
    cout << "Roll no: " << rollNo << "\n";
    cout << "Marks: " << marks << "\n";
  }
  void readFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
      cout << "Unable to open file";
      return;
    }
    while (inFile >> rollNo >> name >> marks) {
      displayDetails();
    }
    inFile.close();
  }
  void writeToFile() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
      cout << "Unable to open file";
      return;
    }
    outFile << rollNo << " " << name << " " << marks << "\n";
    outFile.close();
  }
};

int main(void) {
  Student s;
  s.getDetails();
  s.displayDetails();
  return 0;
}
