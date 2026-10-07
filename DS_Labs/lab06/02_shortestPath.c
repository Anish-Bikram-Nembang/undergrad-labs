#include <stdio.h>

#define MAX 20
#define INF 1000000000

int main(void) {
  int n, graph[MAX][MAX], source;
  printf("Number of vertices: ");
  if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    return 1;
  printf("Enter weighted adjacency matrix (0 means no edge):\n");
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &graph[i][j]);
  printf("Source vertex: ");
  scanf("%d", &source);
  if (source < 1 || source > n)
    return 1;
  int distance[MAX], used[MAX] = {0};
  for (int i = 0; i < n; ++i)
    distance[i] = INF;
  distance[source - 1] = 0;
  for (int step = 0; step < n; ++step) {
    int vertex = -1;
    for (int i = 0; i < n; ++i)
      if (!used[i] && distance[i] < INF &&
          (vertex == -1 || distance[i] < distance[vertex]))
        vertex = i;
    if (vertex == -1)
      break;
    used[vertex] = 1;
    for (int next = 0; next < n; ++next)
      if (graph[vertex][next] > 0 &&
          distance[vertex] + graph[vertex][next] < distance[next])
        distance[next] = distance[vertex] + graph[vertex][next];
  }
  for (int i = 0; i < n; ++i)
    printf("%d -> %d: %s\n", source, i + 1,
           distance[i] == INF ? "unreachable" : "");
  for (int i = 0; i < n; ++i)
    if (distance[i] != INF)
      printf("distance to %d = %d\n", i + 1, distance[i]);
  return 0;
}
