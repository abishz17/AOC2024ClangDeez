#include <stdio.h>
#include <stdlib.h>

int compare(const void *elem1, const void *elem2) {
  int f = *((int *)elem1);
  int s = *((int *)elem2);
  if (f > s)
    return 1;
  if (f < s)
    return -1;
  return 0;
}

int main() {
  FILE *file = fopen("day1.txt", "r");
  if (file == NULL) {
    printf("Unable to open file");
    return 1;
  }
  int left[1000];
  int right[1000];
  int diffarr[1000];
  int result;
  int count = 0;
  while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
    count++;
  }
  qsort(left, sizeof(left) / sizeof(*left), sizeof(*left), compare); 
  qsort(right, sizeof(right) / sizeof(*right), sizeof(*right), compare);
  for (int i = 0; i < 1000; i++) {
    diffarr[i] = abs(left[i] - right[i]);
    result+=diffarr[i];
  }
  printf("The final result is: %d ",result);
  fclose(file);
}
