#include <stdio.h>

static void moveDisks(int count, char source, char target, char helper) {
  if (count == 0) return;
  moveDisks(count - 1, source, helper, target);
  printf("Move disk %d from %c to %c\n", count, source, target);
  moveDisks(count - 1, helper, target, source);
}

int main(void) {
  int disks;
  printf("Number of disks: ");
  if (scanf("%d", &disks) != 1 || disks < 1 || disks > 20) return 1;
  moveDisks(disks, 'A', 'C', 'B');
  return 0;
}