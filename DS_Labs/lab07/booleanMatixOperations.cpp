// 2.   Write a programs to implement Boolean matrix operations- join, product,
// and Boolean product between two zero-one matrix.
#include <iostream>
using namespace std;

const int MAX = 10;

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
  cout << "Enter matrix elements (0 or 1):\n";

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cin >> matrix[i][j];
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

void join(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows,
          int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      C[i][j] = A[i][j] || B[i][j];
  }
}

void product(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows,
             int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      C[i][j] = A[i][j] && B[i][j];
  }
}

void booleanProduct(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
                    int rowsA, int colsA, int colsB) {
  for (int i = 0; i < rowsA; i++)
    for (int j = 0; j < colsB; j++) {
      C[i][j] = 0;
      for (int k = 0; k < colsA; k++)
        C[i][j] = C[i][j] || (A[i][k] && B[k][j]);
    }
}

int main() {
  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int rows, cols;

  cout << "Enter rows and columns: ";
  cin >> rows >> cols;

  cout << "\nMatrix A:\n";
  inputMatrix(A, rows, cols);

  cout << "\nMatrix B:\n";
  inputMatrix(B, rows, cols);

  cout << "\nJoin (A OR B):\n";
  join(A, B, C, rows, cols);
  displayMatrix(C, rows, cols);

  cout << "\nBoolean Product (A AND B):\n";
  product(A, B, C, rows, cols);
  displayMatrix(C, rows, cols);

  cout << "\nBoolean Matrix Product (A * B):\n";
  booleanProduct(A, B, C, rows, cols, cols);
  displayMatrix(C, rows, cols);

  return 0;
}
