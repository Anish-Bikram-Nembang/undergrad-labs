/* Program to verify modular exponentiation algorithm and implement to calculate
 * b^n mod m */
#include <stdio.h>

int main(void) {
  long long base, exponent, modulus, result = 1;
  printf("Enter base, exponent, and modulus: ");
  if (scanf("%lld %lld %lld", &base, &exponent, &modulus) != 3 ||
      exponent < 0 || modulus <= 0)
    return 1;
  base %= modulus;
  while (exponent > 0) {
    if (exponent & 1)
      result = (result * base) % modulus;
    base = (base * base) % modulus;
    exponent >>= 1;
  }
  printf("Result = %lld\n", result);
  return 0;
}
