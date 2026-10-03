#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Set {
private:
  vector<int> elements;
  unordered_map<int, bool> lookup;

public:
  Set() {}
  Set(vector<int> elems) {
    for (int num : elems) {
      if (lookup.find(num) == lookup.end()) {
        lookup.insert({num, true});
        elements.push_back(num);
      }
    }
  }
  vector<int> getElements() { return elements; }
  int add(int element) {
    if (lookup.find(element) == lookup.end()) {
      lookup.insert({element, true});
      elements.push_back(element);
      return 0;
    }
    return 1;
  }
  int add(vector<int> elems) {
    for (int num : elems) {
      if (lookup.find(num) == lookup.end()) {
        lookup.insert({num, true});
        elements.push_back(num);
      }
    }
    return 0;
  }
  int remove(int element) {
    if (lookup.find(element) == lookup.end()) {
      return 1;
    }
    lookup.erase(element);
    for (int i = 0; i < elements.size(); i++) {
      if (elements[i] == element) {
        elements.erase(elements.begin() + i);
        return 0;
      }
    }
    return 0;
  }
  int has(int element) { return (lookup.find(element) != lookup.end()); }
  Set unionSet(Set s) {
    Set unionedSet(elements);
    unionedSet.add(s.getElements());
    return unionedSet;
  }
  Set intersection(Set s) {
    vector<int> elemsInBothSets;
    for (int elem : s.getElements()) {
      if (has(elem)) {
        elemsInBothSets.push_back(elem);
      }
    }
    Set tmp(elemsInBothSets);
    return tmp;
  }
  Set difference(Set s) {
    Set diff(getElements());
    for (int elem : s.getElements()) {
      if (diff.has(elem)) {
        diff.remove(elem);
      }
    }
    return diff;
  }
  Set symmetricDifference(Set s) {
    Set thisAndS = intersection(s);
    Set thisOrS = unionSet(s);
    Set symmDiff(thisOrS.getElements());
    for (int elem : thisAndS.getElements()) {
      if (symmDiff.has(elem)) {
        symmDiff.remove(elem);
      }
    }
    return symmDiff;
  }
  vector<pair<int, int>> cartesianProduct(Set s) {
    vector<pair<int, int>> cartesianProductElems;
    for (int a : elements) {
      for (int b : s.getElements()) {
        cartesianProductElems.push_back({a, b});
      }
    }
    return cartesianProductElems;
  }
  int display() {
    cout << "Elements in Set: [";
    for (int elem : getElements()) {
      int lastElem = getElements()[getElements().size() - 1];
      if (elem != lastElem)
        cout << elem << ", ";
      else
        cout << elem << "]" << endl;
    }
    return 0;
  }
};

// 1. Write a program that accepts 'N' elements into an array but only adds them
// if they are not already present in the set (Enforcing no duplicates rule of
// set)
int Qno1(void) {
  int n;
  vector<int> elems;
  cout << "Enter number of elements" << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cout << "Enter a number" << endl;
    cin >> tmp;
    elems.push_back(tmp);
  }
  Set s(elems);
  s.display();
  return 0;
}

// 2. Create a function that returns '1' if the element exists in the set
// and '0' otherwise.
int Qno2(void) {
  Set s({1, 2, 3, 4, 5});
  int num;
  cout << "Enter a number: " << endl;
  cin >> num;
  cout << s.has(num) << endl;
  return 0;
}

// 3. Write a program to simulate the set operations for the given two sets
// and perforn the following operations:
//  a. Set Union
//  b. Set Intersection
//  c. Set Difference
//  d. Symmetric Difference
//  e.  Cartesian Product

int Qno3(void) {
  Set s1({1, 2, 3, 4, 5}), s2({
                               4,
                               5,
                               6,
                               7,
                           });
  Set unionSet = s1.unionSet(s2);
  Set intersectionSet = s1.intersection(s2);
  Set difference = s1.difference(s2);
  Set symmDiff = s1.symmetricDifference(s2);
  vector<pair<int, int>> cartesianProduct = s1.cartesianProduct(s2);

  cout << "Set A" << endl;
  s1.display();
  cout << "Set B" << endl;
  s2.display();
  cout << endl;
  cout << "AUB" << endl;
  unionSet.display();
  cout << endl;
  cout << "AnB" << endl;
  intersectionSet.display();
  cout << endl;
  cout << "A-B" << endl;
  difference.display();
  cout << endl;
  cout << "AUB - AnB" << endl;
  symmDiff.display();
  cout << endl;
  cout << "Cartesian Product" << endl;
  cout << "[";
  for (int i = 0; i < cartesianProduct.size(); i++) {
    cout << "[" << cartesianProduct[i].first << ", "
         << cartesianProduct[i].second << "]";
    if (i < cartesianProduct.size() - 1)
      cout << ", ";
  }
  cout << "]";
  return 0;
}
int main(void) {
  Qno1();
  Qno2();
  Qno3();
  return 0;
}
