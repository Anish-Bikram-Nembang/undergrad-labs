#include <stdio.h>

static void quickSortRange(int *arr, int low, int high) {
  if (low >= high) return;
  int i = low, j = high, pivot = arr[low + (high - low) / 2];
  while (i <= j) {
    while (arr[i] < pivot) ++i;
    while (arr[j] > pivot) --j;
    if (i <= j) {
      int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
      ++i; --j;
    }
  }
  if (low < j) quickSortRange(arr, low, j);
  if (i < high) quickSortRange(arr, i, high);
}

void quickSort(int *arr, int size) {
  if (size > 1) quickSortRange(arr, 0, size - 1);
}
int main(void) {
  int arr[] = {9, 7, 10, 3, 2, 4, 5, 1, 8, 6};
  printf("Original array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  quickSort(arr, 10);
  printf("Sorted array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
