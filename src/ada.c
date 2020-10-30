#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char tab[16] = "0123456789abcdef";

int count_separator(char *str)
{
    int counter = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '#')
            counter++;
    }
    return (counter);
}

char **my_str_to_word_array(char *str)
{
    int count = count_separator(str);
    int len = strlen(str);
    char **word_array = malloc(sizeof(char *) * count + 1);
    int i = 0, j = 0;
    for (int x = 0; x != count; x++) {
        word_array[x] = malloc(sizeof(char) * len + 1);
        for (i = 0; str[j] != '#'; j++, i++) {
            word_array[x][i] = str[j];
        }
        j++;
        word_array[x][i] = '\0';
    }
    word_array[count] = NULL;
    return(word_array);
}

void process(char *line)
{
    char **word_array = my_str_to_word_array(line);
    int booty = 0;
    int base = 0;
    for (int i = 0; word_array[i] != NULL; i++) {
        if (!booty) {
            if (word_array[i][0] == '\0') {
                base = 10;
                booty = 1;
                continue;
            }
            base = atoi(word_array[i]);
            if (base < 2 || base > 16) {
                printf("%s\n", "no");
                return;
            }
            booty = 1;
        }
        else {
            for (int z = 0; word_array[i][z] != '\0'; z++) {
                char new_tab[base + 1];
                strncpy(new_tab, tab, base);
                new_tab[base] = '\0';
                if (strstr(new_tab, &word_array[i][z]) == NULL) {
                    printf("%s\n", "no");
                    return; 
                }
            }
            booty = 0;
        }
    }
    printf("%s\n", "yes");
}

int main(void)
{
    size_t len = 0;
    char *line = NULL;
    int nb = 0;

    getline(&line, &len, stdin);
    nb = atoi(line);
    free(line);
    line = NULL;
    getline(&line, &len, stdin);
    process(line);
    // for (int i = 0; i < nb; i++) {
    //     getline(&line, &len, stdin);
    //     process(line);
    // }


    return (0);
}