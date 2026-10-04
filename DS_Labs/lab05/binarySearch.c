#include <stdio.h>

int binarySearch(int *arr, int target, int low, int high) {
  int mid = low + (high - low) / 2;
  if (low > high) {
    return -1;
  }
  if (arr[mid] == target) {
    return mid;
  }
  if (arr[mid] > target) {
    return binarySearch(arr, target, low, mid - 1);
  }
  return binarySearch(arr, target, mid + 1, high);
}
int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = 9;
  int result = binarySearch(arr, 7, 0, size - 1);
  if (result == -1) {
    printf("Element not found!\n");
    return 1;
  }
  printf("Element found at index %d!\n", result);
  return 0;
}
