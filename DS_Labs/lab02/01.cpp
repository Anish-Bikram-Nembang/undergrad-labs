// 1. Write a program to enter a number and perform ciel() and floor function to
// obtain the rounded values

#include <iostream>
using namespace std;
int floor(float num) {
  if (num >= 0) {
    return (int)num;
  } else {
    return (num == (int)num) ? (int)num : (int)num - 1;
  }
}
int ciel(float num) {
  int floored = floor(num);
  return (num == floored) ? floored : floored + 1;
}

int main(void) {
  float numToBeCieled = -3.2;
  int cieledNumber = ciel(numToBeCieled);
  cout << "ceil(" << numToBeCieled << ") = " << cieledNumber << endl;

  float numToBeFloored = 4.23;
  int flooredNumber = floor(numToBeFloored);
  cout << "floor(" << numToBeFloored << ") = " << flooredNumber << endl;

  return 0;
}
