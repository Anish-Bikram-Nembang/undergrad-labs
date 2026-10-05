#include "../propositional_logic.hpp"
#include <iostream>

int main() {
  int premiseCount;
  std::cout << "Number of premises: ";
  if (!(std::cin >> premiseCount) || premiseCount < 1) return 1;
  std::vector<std::string> premises(premiseCount);
  for (int i = 0; i < premiseCount; ++i) {
    std::cout << "Premise " << i + 1 << ": ";
    std::getline(std::cin >> std::ws, premises[i]);
  }
  std::string conclusion;
  std::cout << "Conclusion: ";
  std::getline(std::cin >> std::ws, conclusion);
  auto variables = propositionVariables(conclusion);
  for (const auto &premise : premises)
    for (char variable : propositionVariables(premise))
      if (std::find(variables.begin(), variables.end(), variable) == variables.end())
        variables.push_back(variable);
  try {
    std::size_t rows = std::size_t{1} << variables.size();
    for (std::size_t assignment = 0; assignment < rows; ++assignment) {
      std::unordered_map<char, bool> values;
      for (std::size_t i = 0; i < variables.size(); ++i)
        values[variables[i]] = (assignment >> i) & 1U;
      bool premisesTrue = true;
      for (const auto &premise : premises)
        premisesTrue &= evaluateProposition(premise, values);
      if (premisesTrue && !evaluateProposition(conclusion, values)) {
        std::cout << "The argument is invalid.\n";
        return 0;
      }
    }
  } catch (const std::exception &error) {
    std::cerr << "Error: " << error.what() << '\n';
    return 1;
  }
  std::cout << "The argument is valid.\n";
}
