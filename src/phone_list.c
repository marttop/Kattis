#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node {
    struct node *ptr0;
    struct node *ptr1;
    struct node *ptr2;
    struct node *ptr3;
    struct node *ptr4;
    struct node *ptr5;
    struct node *ptr6;
    struct node *ptr7;
    struct node *ptr8;
    struct node *ptr9;
    int nb;
} node_t;

node_t *new_tree_node(void)
{
    node_t *tree_head = malloc(sizeof(*tree_head));

    tree_head->nb = 0;
    tree_head->ptr0 = NULL;
    tree_head->ptr1 = NULL;
    tree_head->ptr2 = NULL;
    tree_head->ptr3 = NULL;
    tree_head->ptr4 = NULL;
    tree_head->ptr5 = NULL;
    tree_head->ptr6 = NULL;
    tree_head->ptr7 = NULL;
    tree_head->ptr8 = NULL;
    tree_head->ptr9 = NULL;

    return (tree_head);
}

int push_tree_digits(char *str, node_t *tree_head)
{
    node_t *tmp = tree_head;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            if (tmp->ptr0 == NULL) {
                tmp->ptr0 = new_tree_node();
                tmp = tmp->ptr0;
            } else
                tmp = tmp->ptr0;
        } else if (str[i] == '1') {
            if (tmp->ptr1 == NULL) {
                tmp->ptr1 = new_tree_node();
                tmp = tmp->ptr1;
            } else
                tmp = tmp->ptr1;
        } else if (str[i] == '2') {
           if (tmp->ptr2 == NULL) {
                tmp->ptr2 = new_tree_node();
                tmp = tmp->ptr2;
            } else
                tmp = tmp->ptr2;
        } else if (str[i] == '3') {
            if (tmp->ptr3 == NULL) {
                tmp->ptr3 = new_tree_node();
                tmp = tmp->ptr3;
            } else
                tmp = tmp->ptr3;
        } else if (str[i] == '4') {
            if (tmp->ptr4 == NULL) {
                tmp->ptr4 = new_tree_node();
                tmp = tmp->ptr4;
            } else
                tmp = tmp->ptr4;
        } else if (str[i] == '5') {
            if (tmp->ptr5 == NULL) {
                tmp->ptr5 = new_tree_node();
                tmp = tmp->ptr5;
            } else
                tmp = tmp->ptr5;
        } else if (str[i] == '6') {
            if (tmp->ptr6 == NULL) {
                tmp->ptr6 = new_tree_node();
                tmp = tmp->ptr6;
            } else
                tmp = tmp->ptr6;
        } else if (str[i] == '7') {
            if (tmp->ptr7 == NULL) {
                tmp->ptr7 = new_tree_node();
                tmp = tmp->ptr7;
            } else
                tmp = tmp->ptr7;
        } else if (str[i] == '8') {
            if (tmp->ptr8 == NULL) {
                tmp->ptr8 = new_tree_node();
                tmp = tmp->ptr8;
            }
            else
                tmp = tmp->ptr8;
        } else if (str[i] == '9') {
            if (tmp->ptr9 == NULL) {
                tmp->ptr9 = new_tree_node();
                tmp = tmp->ptr9;
            } else
                tmp = tmp->ptr9;
        }
        if (tmp->nb == 1)
            return (1);
    }
    tmp->nb = 1;
    if (tmp->ptr0 == NULL && tmp->ptr1 == NULL && tmp->ptr2 == NULL && tmp->ptr3 == NULL
    && tmp->ptr4 == NULL && tmp->ptr5 == NULL && tmp->ptr6 == NULL && tmp->ptr7 == NULL
    && tmp->ptr8 == NULL && tmp->ptr9 == NULL)
        return (0);
    else
        return (1);
}

int main(void)
{
    int nbTest, nbPhone, read;
    size_t len = 0;
    char *line = NULL;
    node_t *tree_head;

    read = getline(&line, &len, stdin);
    if (read == -1)
        return (84);
    nbTest = atoi(line);
    free(line);
    line = NULL;

    for (int check = 0, save_check = 0; nbTest != 0; nbTest--)  {
        tree_head = new_tree_node();
        read = getline(&line, &len, stdin);
        if (read == -1)
            return (84);
        nbPhone = atoi(line);
        free(line);
        line = NULL;
        for (save_check = 0, check = 0; nbPhone != 0; nbPhone--) {
            read = getline(&line, &len, stdin);
            if (read == -1)
                return (84);
            if (save_check == 1) {
                free(line);
                line = NULL;
                continue;
            }
            check = push_tree_digits(line, tree_head);
            free(line);
            line = NULL;
            if (check == 1)
                save_check = check;
        }
        if (save_check == 0)
            printf("YES\n");
        else
            printf("NO\n");
        free(tree_head);
    }
    return (0);
}