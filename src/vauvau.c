#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_next_number()
{
    int num = atoi(strtok(NULL, " "));
    return (num);
}

void print_answer(int aDog, int bDog)
{
    if ((aDog && !bDog) || (!aDog && bDog)) {
        printf("one\n");
        return;
    }
    else if (aDog && bDog) {
        printf("both\n");
        return;
    }
    else {
        printf("none\n");
        return;
    }
}

void loop(int a, int b, int c, int d, int pers)
{
    int aAngry = 1;
    int bAngry = 1;
    int a_tmp = a, b_tmp = b, c_tmp = c, d_tmp = d;
    for (int i = 1; i < pers; i++) {
        if (aAngry) {
            a_tmp--;
            if (a_tmp == 0) {
                a_tmp = a;
                aAngry = 0;
            }
        }
        else {
            b_tmp--;
            if (b_tmp == 0) {
                b_tmp = b;
                aAngry = 1;
            }
        }
        if (bAngry) {
            c_tmp--;
            if (c_tmp == 0) {
                c_tmp = c;
                bAngry = 0;
            }
        }
        else {
            d_tmp--;
            if (d_tmp == 0) {
                d_tmp = d;
                bAngry = 1;
            }
        }
    }
    print_answer(aAngry, bAngry);
}


int main(void)
{
    size_t len = 0;
    int a, b, c, d;
    int first, sec, third;
    char *line, *args = NULL;

    getline(&line, &len, stdin);
    args = strtok(line, " ");
    a = atoi(args);
    b = get_next_number();
    c = get_next_number();
    d = get_next_number();
    free(line);
    line = NULL;

    getline(&line, &len, stdin);
    args = strtok(line, " ");
    first = atoi(args);
    sec = get_next_number();
    third = get_next_number();
    free(line);

    loop(a, b, c, d, first);
    loop(a, b, c, d, sec);
    loop(a, b, c, d, third);

    return (0);
}