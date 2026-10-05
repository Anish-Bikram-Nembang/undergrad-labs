/* Program to obtain the permutation and combination */
/* Program to obtain the permutation and combination */
#include <stdio.h>

long long factorial(int n) {
  long long result = 1;
  for (int i = 2; i <= n; ++i) result *= i;
  return result;
}
int main(void) {
  int n, r;
  printf("Enter n and r: ");
  if (scanf("%d %d", &n, &r) != 2 || n < 0 || r < 0 || r > n || n > 20)
    return 1;
  printf("Permutation = %lld\nCombination = %lld\n",
         factorial(n) / factorial(n - r),
         factorial(n) / (factorial(r) * factorial(n - r)));
  return 0;
}
