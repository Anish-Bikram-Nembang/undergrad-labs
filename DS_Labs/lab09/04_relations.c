#include <stdio.h>

int main(void) {
  int n, relation[20][20];
  printf("Size of relation: ");
  if (scanf("%d", &n) != 1 || n < 1 || n > 20) return 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &relation[i][j]);
  int reflexive = 1, symmetric = 1, transitive = 1;
  for (int i = 0; i < n; ++i) {
    if (!relation[i][i]) reflexive = 0;
    for (int j = 0; j < n; ++j) {
      if (relation[i][j] != relation[j][i]) symmetric = 0;
      for (int k = 0; k < n; ++k)
        if (relation[i][j] && relation[j][k] && !relation[i][k])
          transitive = 0;
    }
  }
  printf("Reflexive: %s\nSymmetric: %s\nTransitive: %s\n",
         reflexive ? "yes" : "no", symmetric ? "yes" : "no",
         transitive ? "yes" : "no");
  return 0;
}
