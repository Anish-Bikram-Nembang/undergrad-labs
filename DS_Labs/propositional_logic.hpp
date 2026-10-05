#pragma once
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class Proposition {
  const std::string &text;
  std::unordered_map<char, bool> values;
  std::size_t at = 0;
  void spaces() { while (at < text.size() && std::isspace((unsigned char)text[at])) ++at; }
  bool take(char c) { spaces(); if (at < text.size() && text[at] == c) { ++at; return true; } return false; }
  bool primary() {
    spaces();
    if (take('(')) { bool value = biconditional(); if (!take(')')) throw std::invalid_argument("missing ')'"); return value; }
    if (at >= text.size() || !std::isalpha((unsigned char)text[at])) throw std::invalid_argument("expected variable");
    char name = (char)std::tolower((unsigned char)text[at++]);
    if (values.find(name) == values.end()) throw std::invalid_argument("variable must be p, q, r, or s");
    return values[name];
  }
  bool negation() { if (take('!')) return !negation(); return primary(); }
  bool conjunction() {
    bool value = negation();
    while (true) {
      spaces();
      if (take('n') || take('&')) { bool right = negation(); value = value && right; }
      else return value;
    }
  }
  bool disjunction() {
    bool value = conjunction();
    while (true) {
      spaces();
      if (take('v') || take('|')) { bool right = conjunction(); value = value || right; }
      else return value;
    }
  }
  bool implication() {
    bool left = disjunction(); spaces();
    if (take('>')) { bool right = implication(); return !left || right; }
    if (take('-')) { if (!take('>')) throw std::invalid_argument("expected ->"); bool right = implication(); return !left || right; }
    return left;
  }
  bool biconditional() {
    bool value = implication();
    while (true) {
      spaces();
      if (!take('<')) return value;
      if (!take('>') && !(take('-') && take('>'))) throw std::invalid_argument("expected <->");
      value = value == implication();
    }
  }
public:
  Proposition(const std::string &expression, std::unordered_map<char, bool> assignment)
      : text(expression), values(assignment) {}
  bool evaluate() {
    bool result = biconditional(); spaces();
    if (at != text.size()) throw std::invalid_argument("unexpected character");
    return result;
  }
};

inline std::vector<char> propositionVariables(const std::string &expression) {
  std::vector<char> result;
  for (char c : expression) {
    c = (char)std::tolower((unsigned char)c);
    if (c >= 'p' && c <= 's' && std::find(result.begin(), result.end(), c) == result.end())
      result.push_back(c);
  }
  return result;
}
inline bool evaluateProposition(const std::string &expression,
                                const std::unordered_map<char, bool> &values) {
  return Proposition(expression, values).evaluate();
}
