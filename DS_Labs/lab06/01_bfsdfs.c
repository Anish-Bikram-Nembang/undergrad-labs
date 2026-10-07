#include <stdio.h>

static void dfs(int graph[20][20], int n, int vertex, int visited[20]) {
  visited[vertex] = 1;
  printf("%d ", vertex + 1);
  for (int next = 0; next < n; ++next)
    if (graph[vertex][next] && !visited[next])
      dfs(graph, n, next, visited);
}

int main(void) {
  int graph[20][20] = {{0}}, queue[20], visited[20] = {0};
  int n, edges, start;
  printf("Number of vertices and edges: ");
  if (scanf("%d %d", &n, &edges) != 2 || n < 1 || n > 20 || edges < 0)
    return 1;
  for (int i = 0; i < edges; ++i) {
    int from, to;
    scanf("%d %d", &from, &to);
    if (from < 1 || from > n || to < 1 || to > n)
      return 1;
    graph[from - 1][to - 1] = 1;
  }
  printf("Starting vertex: ");
  scanf("%d", &start);
  if (start < 1 || start > n)
    return 1;
  int front = 0, back = 0;
  queue[back++] = start - 1;
  visited[start - 1] = 1;
  printf("BFS: ");
  while (front < back) {
    int vertex = queue[front++];
    printf("%d ", vertex + 1);
    for (int next = 0; next < n; ++next)
      if (graph[vertex][next] && !visited[next]) {
        visited[next] = 1;
        queue[back++] = next;
      }
  }
  for (int i = 0; i < n; ++i)
    visited[i] = 0;
  printf("\nDFS: ");
  dfs(graph, n, start - 1, visited);
  puts("");
  return 0;
}
