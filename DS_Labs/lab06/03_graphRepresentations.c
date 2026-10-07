#include <stdio.h>

int main(void) {
  int vertices, edges, adjacency[20][20] = {{0}}, incidence[20][20] = {{0}};
  printf("Number of vertices and edges: ");
  if (scanf("%d %d", &vertices, &edges) != 2 || vertices < 1 || vertices > 20 ||
      edges < 0 || edges > 20)
    return 1;
  for (int edge = 0; edge < edges; ++edge) {
    int from, to;
    scanf("%d %d", &from, &to);
    if (from < 1 || from > vertices || to < 1 || to > vertices)
      return 1;
    adjacency[from - 1][to - 1] = adjacency[to - 1][from - 1] = 1;
    incidence[from - 1][edge] = incidence[to - 1][edge] = 1;
  }
  printf("Adjacency matrix:\n");
  for (int i = 0; i < vertices; ++i) {
    for (int j = 0; j < vertices; ++j)
      printf("%d ", adjacency[i][j]);
    puts("");
  }
  printf("Incidence matrix:\n");
  for (int i = 0; i < vertices; ++i) {
    for (int j = 0; j < edges; ++j)
      printf("%d ", incidence[i][j]);
    puts("");
  }
  printf("Adjacency list:\n");
  for (int i = 0; i < vertices; ++i) {
    printf("%d:", i + 1);
    for (int j = 0; j < vertices; ++j)
      if (adjacency[i][j])
        printf(" %d", j + 1);
    puts("");
  }
  return 0;
}
