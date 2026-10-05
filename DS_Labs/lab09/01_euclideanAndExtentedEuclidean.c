#include <stdio.h>

int main(void) {
  long long a, b, oldR, r, oldS = 1, s = 0, oldT = 0, t = 1;
  printf("Enter two integers: ");
  if (scanf("%lld %lld", &a, &b) != 2) return 1;
  oldR = a; r = b;
  while (r != 0) {
    long long quotient = oldR / r, next;
    next = oldR - quotient * r; oldR = r; r = next;
    next = oldS - quotient * s; oldS = s; s = next;
    next = oldT - quotient * t; oldT = t; t = next;
  }
  if (oldR < 0) oldR = -oldR, oldS = -oldS, oldT = -oldT;
  printf("gcd = %lld\n%lld(%lld) + %lld(%lld) = %lld\n",
         oldR, a, oldS, b, oldT, oldR);
  return 0;
}
