// 1.   Write a programs to generate permutations and combinations for give n
// and r
#include <iostream>
#include <stdexcept>

using namespace std;

std::size_t factorial(int n, int skipAfter = 0) {
  if (n > 20)
    throw std::invalid_argument("number for factorial cannot exceed 20");
  std::size_t fact{1};
  for (int i = n; i > skipAfter; i--)
    fact *= i;
  return fact;
}
size_t permutation(int n, int r) {
  if (r < 0 || n < 0)
    throw invalid_argument("arguments cannot be negative");
  if (r > n)
    throw invalid_argument("r cannot be greater than n");
  int nMinusR = n - r;
  return factorial(n, nMinusR);
}
size_t combination(int n, int r) {
  if (r < 0 || n < 0)
    throw invalid_argument("arguments cannot be negative");
  if (r > n)
    throw invalid_argument("r cannot be greater than n");
  r = r < (n - r) ? r : (n - r);
  int nMinusR = n - r;
  size_t numerator = factorial(n, nMinusR);
  size_t denominator = factorial(r);
  return numerator / denominator;
}
int main(void) {
  int n, r;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter r: ";
  cin >> r;
  try {
    size_t combinationResult = combination(n, r);
    size_t permutationResult = permutation(n, r);

    cout << "Combination: " << combinationResult << '\n';
    cout << "Permutation: " << permutationResult << '\n';
  } catch (const invalid_argument &e) {
    cerr << "An error occured: " << e.what() << '\n';
  }
  return 0;
}
