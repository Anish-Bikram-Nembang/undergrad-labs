/* Program to implement join, product and boolean product of two zero-one
 * matrices */
#include <stdio.h>

int main(void) {
  int rows, cols, A[10][10], B[10][10], result[10][10];
  printf("Rows and columns: ");
  if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || rows > 10 || cols < 1 ||
      cols > 10)
    return 1;
  for (int matrix = 0; matrix < 2; ++matrix)
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) {
        int value;
        scanf("%d", &value);
        if (value != 0 && value != 1)
          return 1;
        (matrix ? B : A)[i][j] = value;
      }
  printf("Join / product:\n");
  for (int operation = 0; operation < 2; ++operation) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result[i][j] = operation ? A[i][j] && B[i][j] : A[i][j] || B[i][j];
        printf("%d ", result[i][j]);
      }
      puts("");
    }
    puts("");
  }
  if (rows != cols)
    return 0;
  printf("Boolean product A * B:\n");
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < cols; ++k)
        result[i][j] |= A[i][k] && B[k][j];
      printf("%d ", result[i][j]);
    }
    puts("");
  }
  return 0;
}
