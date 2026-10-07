// 4. Write a C++ program using a class named FileManager that copies the
// contents of one text file into another file. The program should: Ask the user
// for the source and destination filenames Open the source file. Copy its
// contents to the destination file. Display an appropriate message after
// successful copying. Exception requirement: Handle exceptions when: The source
// file does not exist. The destination file cannot be opened. An unexpected
// file operation occurs.
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
class FileManager {
public:
  static void copy(const std::string &source, const std::string &destination) {
    std::ifstream in(source);
    if (!in)
      throw std::runtime_error("source file does not exist");
    std::ofstream out(destination);
    if (!out)
      throw std::runtime_error("destination cannot be opened");
    out << in.rdbuf();
    if (!out)
      throw std::runtime_error("file operation failed");
  }
};
int main() {
  std::string source, destination;
  std::cin >> source >> destination;
  try {
    FileManager::copy(source, destination);
    std::cout << "Copied successfully\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
