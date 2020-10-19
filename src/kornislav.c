#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (void)
{
  int turtle[4], smallest = 100, smallest_id = 0, biggest = 0, biggest_id = 0, arr[2];
  scanf("%d %d %d %d", &turtle[0], &turtle[1], &turtle[2], &turtle[3]);
  for (int i = 0; i != 4; i++) {
    if (turtle[i] > biggest) {
      biggest = turtle[i];
      biggest_id = i;
    }
    if (turtle[i] < smallest) {
      smallest = turtle[i];
      smallest_id = i;
    }
  }
  for (int i = 0, j = 0; i != 4; i++) {
    if (i != biggest_id && i != smallest_id) {
      arr[j] = turtle[i];
      j++;
    }
  }
  if (arr[0] > arr[1])
    biggest = arr[0];
  else biggest = arr[1];
  printf("%d\n", smallest * biggest);
  return (0);
}