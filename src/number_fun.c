#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (void)
{
  int nb[3], loop = 0;
  scanf("%d", &loop);
  for (int i = 0, check = 0; i != loop; i++, check = 0) {
    scanf("%d %d %d", &nb[0], &nb[1], &nb[2]);
    if (nb[0] + nb[1] == nb[2])
      check++;
    if (nb[0] * nb[1] == nb[2])
      check++;
    if (nb[0] % nb[1] == 0 || nb[1] % nb[0] == 0) {
      if (nb[0] / nb[1] == nb[2] || nb[1] / nb[0] == nb[2] )
        check++;
    }
    if (nb[0] - nb[1] == nb[2] || nb[1] - nb[0] == nb[2])
      check++;
    if (check != 0)
      printf("Possible\n");
    else printf("Impossible\n");
  }
  return (0);
}