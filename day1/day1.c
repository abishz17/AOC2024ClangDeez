#include <stdio.h>
#include <stdlib.h>

int compare(const void *elem1, const void *elem2) {
  int f = *((int *)elem1); // Casting void pointer to integer pointer
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
  int occurencearr[1000];
  int result;
  int similarityScore;
  int count = 0;
  while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
    count++;
  }
  qsort(left, sizeof(left) / sizeof(*left), sizeof(*left), compare);
  qsort(right, sizeof(right) / sizeof(*right), sizeof(*right), compare);
  for (int i = 0; i < 1000; i++) {
    diffarr[i] = abs(left[i] - right[i]);
    result += diffarr[i];
  }
  for (int i = 0; i < 1000; i++) {
    int similarityCount = 0;
    for (int j = 0; j < 1000; j++) {
      if (left[i] == right[j]) {
        similarityCount++;
      }
    }
    occurencearr[i] = left[i] * similarityCount;
  }
  for(int i = 0 ; i < 1000 ; i++){
    similarityScore += occurencearr[i];
  }
  printf("The final result is: %d ", result);
  printf("The similarity score is: %d ", similarityScore);
  fclose(file);
}
