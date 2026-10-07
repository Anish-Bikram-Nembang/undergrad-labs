#include <iostream>
#include <set>
using namespace std;

void display(set<int> s) {
  for (int x : s)
    cout << x << " ";
  cout << endl;
}

int main() {
  int n, m, x;

  set<int> A, B;

  cout << "Enter number of elements in A: ";
  cin >> n;

  cout << "Enter elements of A: ";
  for (int i = 0; i < n; i++) {
    cin >> x;
    A.insert(x);
  }

  cout << "Enter number of elements in B: ";
  cin >> m;

  cout << "Enter elements of B: ";
  for (int i = 0; i < m; i++) {
    cin >> x;
    B.insert(x);
  }

  // Union
  set<int> uni = A;
  uni.insert(B.begin(), B.end());

  cout << "\nUnion (A U B): ";
  display(uni);

  // Intersection
  set<int> intersection;

  for (int a : A) {
    if (B.count(a))
      intersection.insert(a);
  }

  cout << "Intersection (A n B): ";
  display(intersection);

  // Difference A - B
  set<int> differenceAB;

  for (int a : A) {
    if (!B.count(a))
      differenceAB.insert(a);
  }

  cout << "Difference (A - B): ";
  display(differenceAB);

  // Cartesian Product A x B
  cout << "Cartesian Product (A x B): ";
  for (int a : A) {
    for (int b : B) {
      cout << "(" << a << ", " << b << ") ";
    }
  }
  cout << endl;

  return 0;
}
