#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void add(int a, int b, int c)
{
    if (a + b == c) {
        printf("%d+%d=%d\n", a, b, c);
        exit(0);
    }
    if (a == b + c) {
        printf("%d=%d+%d\n", a, b, c);
        exit(0);
    }
}

void sub(int a, int b, int c)
{
    if (a - b == c) {
        printf("%d-%d=%d\n", a, b, c);
        exit(0);
    }
    if (a == b - c) {
        printf("%d=%d-%d\n", a, b, c);
        exit(0);
    }
}

void mult(int a, int b, int c)
{
    if (a * b == c) {
        printf("%d*%d=%d\n", a, b, c);
        exit(0);
    }
    if (a == b * c) {
        printf("%d=%d*%d\n", a, b, c);
        exit(0);
    }
}

void divide(int a, int b, int c)
{
    if (a != 0 && b != 0 && a / b == c) {
        printf("%d/%d=%d\n", a, b, c);
        exit(0);
    }
    if (b != 0 && c !=  0 && a == b / c) {
        printf("%d=%d/%d\n", a, b, c);
        exit(0);
    }
}

int main(void)
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    add(a, b, c);
    mult(a, b, c);
    divide(a, b, c);
    sub(a, b, c);
    return 0;
}