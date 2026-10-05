#include "../propositional_logic.hpp"
#include <iostream>

int main() {
  std::string first, second;
  std::cout << "Enter first proposition: ";
  std::getline(std::cin >> std::ws, first);
  std::cout << "Enter second proposition: ";
  std::getline(std::cin >> std::ws, second);
  auto variables = propositionVariables(first);
  for (char variable : propositionVariables(second))
    if (std::find(variables.begin(), variables.end(), variable) == variables.end())
      variables.push_back(variable);
  try {
    bool equivalent = true;
    std::size_t rows = std::size_t{1} << variables.size();
    for (std::size_t assignment = 0; assignment < rows; ++assignment) {
      std::unordered_map<char, bool> values;
      for (std::size_t i = 0; i < variables.size(); ++i)
        values[variables[i]] = (assignment >> i) & 1U;
      if (evaluateProposition(first, values) != evaluateProposition(second, values)) {
        equivalent = false;
        break;
      }
    }
    std::cout << (equivalent ? "Equivalent\n" : "Not equivalent\n");
  } catch (const std::exception &error) {
    std::cerr << "Error: " << error.what() << '\n';
    return 1;
  }
}
