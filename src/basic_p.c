#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void bigger_smaller_equal(int nb1, int nb2)
{
    if (nb1 > nb2)
    {
        printf("Bigger\n");
    }
    else if (nb1 == nb2)
    {
        printf("Equal\n");
    }
    else
    {
        printf("Smaller\n");
    }
}

void swap(int *p, int *q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
}

void median(int a, int b, int c)
{
    int tab[3];
    tab[0] = a;
    tab[1] = b;
    tab[2] = c;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
                swap(&tab[j], &tab[j + 1]);
        }
    }
    printf("%d\n", tab[1]);
}

void sum(int *tab, int nb_args)
{
    int sum = 0;
    for (int i = 0; i < nb_args; i++) {
        sum += tab[i];
    }
    printf("%d\n", sum);
}

void sum_even(int *tab, int nb_args)
{
    int sum = 0;
    for (int i = 0; i < nb_args; i++) {
        if (tab[i] % 2 == 0)
            sum += tab[i];
    }
    printf("%d\n", sum);
}

void ascii_encode(int *tab, int nb_args)
{
    for (int i = 0; i < nb_args; i++) {
        printf("%c", (tab[i] % 26) + 97);
    }
    printf("\n");
}

void jump(int *tab, int nb_args, int index, int counter)
{

    if (index >= nb_args || index < 0) {
        printf("Out\n");
        exit(0);
    }
    else if (index == nb_args - 1) {
        printf("Done\n");
        exit(0);
    }
    index = tab[index];
    counter++;
    if (counter >= nb_args) {
        printf("Cyclic\n");
        exit(0);
    }
    jump(tab, nb_args, index, counter);
}

void action_switch(int *tab, int nb_args, int instruction)
{
    switch (instruction) {
        case 1:
            printf("%d\n", 7);
            break;
        case 2:
            bigger_smaller_equal(tab[0], tab[1]);
            break;
        case 3:
            median(tab[0], tab[1], tab[2]);
            break;
        case 4:
            sum(tab, nb_args);
            break;
        case 5:
            sum_even(tab, nb_args);
            break;
        case 6:
            ascii_encode(tab, nb_args);
            break;
        case 7:
            jump(tab, nb_args, 0, 0);
            break;
        default:
            break;
    }
}

int main(void)
{
    char *token, *line = NULL;
    size_t len = 0;
    int nb_args = 0;
    int instruction = 0;

    getline(&line, &len, stdin);
    token = strtok(line, " ");
    nb_args = atoi(token);
    token = strtok(NULL, " ");
    instruction = atoi(token);
    free(line);
    line = NULL;

    int tab[nb_args];

    getline(&line, &len, stdin);
    token = strtok(line, " ");
    tab[0] = atoi(token);

    for (int i = 1; i < nb_args; i++)
    {
        token = strtok(NULL, " ");
        tab[i] = atoi(token);
    }

    free(line);
    line = NULL;

    action_switch(tab, nb_args, instruction);

    return (0);
}