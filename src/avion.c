#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    int result[6];
    int i = 0;

    getline(&line, &len, stdin);
    if (strstr(line, "FBI")) {
        result[0] = 1;
        i++;
    }
    for (int index = 2; index < 6; index++) {
        getline(&line, &len, stdin);
        if (strstr(line, "FBI")) {
            result[i] = index;
            i++;
        }
    }
    result[i] = -1;


    if (result[0] == -1) {
        printf("%s\n", "HE GOT AWAY!");
        return (0);
    }
    else {
        for (int x = 0; result[x] != -1; x++) {
            if (result[x + 1] == -1) {
                printf("%d\n", result[x]);
                break;
            }
            printf("%d ", result[x]);
        }
    }
    return (0);
}