#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void verify_map(char **map, int nb)
{
    int black = 0, white = 0, cons = 0;

    for (int i = 0; i < nb; i++) {
        white = 0;
        black = 0;
        for (int j = 0; j < nb; j++) {
            if (map[i][j] == 'B') {
                black += 1;
                cons += 1;
                if (cons != 3 && map[i][j + 1] != 'B')
                    cons = 0;
            }
            else if (map[i][j] == 'W') {
                white += 1;
                cons += 1;
                if (cons != 3 && map[i][j + 1] != 'W')
                    cons = 0;
            }
            if (cons == 3) {
                printf("%d\n", 0);
                exit(0);
            }
        }
        if (white != black) {
            printf("%d\n", 0);
            exit(0);
        }
    }

    for (int i = 0; i < nb; i++) {
        white = 0;
        black = 0;
        for (int j = 0; j < nb; j++) {
            if (map[j][i] == 'B') {
                black += 1;
                cons += 1;
                if (cons != 3 && map[j + 1][i] != 'B')
                    cons = 0;
            }
            else if (map[j][i] == 'W') {
                white += 1;
                cons += 1;
                if (cons != 3 && map[j + 1][i] != 'W')
                    cons = 0;
            }
            if (cons == 3) {
                printf("%d\n", 0);
                exit(0);
            }
        }
        if (white != black) {
            printf("%d\n", 0);
            exit(0);
        }
    }

    if (white != black) {
        printf("%d\n", 0);
        exit(0);
    }
    else {
        printf("%d\n", 1);
        exit(0);
    }
}

int main(void)
{
    int nb = 0, i = 0;
    char **map = NULL;
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    nb = atoi(line);
    free(line);
    line = NULL;

    map = malloc(sizeof(char *) * (nb + nb + 1));

    for (; i < nb; i++) {
        getline(&map[i], &len, stdin);
    }

    int j = 0;
    map[i] = malloc(sizeof(char) * (nb + 1));
    for (; j < nb; j++) {
        map[i][j] = 'F';
    }
    map[i][j] = '\0';

    verify_map(map, nb);

    return (0);
}